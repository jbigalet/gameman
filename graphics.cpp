#include <X11/Xlib.h>
#include <X11/Xatom.h>

#define GC_WIDTH 160
#define GC_HEIGHT 144

struct Color {
    u8 r;
    u8 g;
    u8 b;

    u32 rgb() const {
        u32 t;
        t = r << 16;
        t |= g << 8;
        t |= b;
        return t;
    }

    bool operator<(const Color& c) const {
        return rgb() < c.rgb();
    }
};

struct Point {
    u8 x;
    u8 y;
};

struct GHandler {
    Display* display;
    Window window;
    i32 screen_id;
    GC gc;
    Colormap cmap;
    Pixmap pixmap;

    u16 window_width;
    u16 window_height;

    Color fb[GC_WIDTH][GC_HEIGHT];

    void init(u32 mul=4) {
        for(u8 x=0 ; x<GC_WIDTH ; x++)
            for(u8 y=0 ; y<GC_HEIGHT ; y++)
                fb[x][y] = Color{0, 0, 0};

        display = XOpenDisplay(NULL);
        check(display != NULL);
        screen_id = DefaultScreen(display);
        window = XCreateSimpleWindow(display,
                                     RootWindow(display, screen_id),
                                     0, 0,  // top left
                                     GC_WIDTH*mul, GC_HEIGHT*mul,  // size
                                     1, BlackPixel(display, screen_id),  // border
                                     WhitePixel(display, screen_id));  // background

        // change window type to dialog to get a floating window on i3
        Atom window_type_atom = XInternAtom(display, "_NET_WM_WINDOW_TYPE", false);
        Atom dialog_atom      = XInternAtom(display, "_NET_WM_WINDOW_TYPE_DIALOG", false);
        XChangeProperty(display,
                        window,
                        window_type_atom, XA_ATOM,  // property + atom type
                        32, //  format
                        PropModeReplace, //  mode
                        (u8*)&dialog_atom, // data
                        1); //  nelements


        /* XClearWindow(display, window); */
        XMapRaised(display, window);
        /* XSync(display, true); */
        XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);

        gc = DefaultGC(display, screen_id);  // graphic context
        cmap = DefaultColormap(display, screen_id);

        pixmap = XCreatePixmap(display, window, GC_WIDTH*mul, GC_HEIGHT*mul, 24);
    }

    ~GHandler() {
        XCloseDisplay(display);
    }

    void draw() {
        auto stime = now();

        f32 ratio_x = window_width/(f32)GC_WIDTH;
        f32 ratio_y = window_height/(f32)GC_HEIGHT;

        std::map<Color, std::vector<XRectangle>> m;
        for(u8 x=0 ; x<GC_WIDTH ; x++)
            for(u8 y=0 ; y<GC_HEIGHT ; y++) {
                auto it = m.find(fb[x][y]);
                if(it == m.end())
                    m[fb[x][y]] = std::vector<XRectangle>();
                m[fb[x][y]].push_back( XRectangle {
                        (i16)(x*ratio_x), (i16)(y*ratio_y), (u16)ratio_x, (u16)ratio_y
                });
            }

        /* XClearWindow(display, window); */

        for(auto& kv: m) {
            Color pc = kv.first;

            XColor c;
            c.red = 255*(u16)pc.r;
            c.green = 255*(u16)pc.g;
            c.blue = 255*(u16)pc.b;
            c.flags = DoRed | DoGreen | DoBlue;
            XAllocColor(display, cmap, &c);

            XSetForeground(display, gc, c.pixel);

            XFillRectangles(display, pixmap, gc, &kv.second[0], kv.second.size());
        }

        XCopyArea(display, pixmap, window, gc, 0, 0, window_width, window_height, 0, 0);
        XFlush(display);
        std::cout << "draw in " << tdiff_micro(stime, now()) << std::endl;
    }

    bool handle_events() {
        bool destroy = false;
        while(XEventsQueued(display, QueuedAfterFlush) > 0) {
            XEvent e;
            XNextEvent(display, &e);
            switch(e.type) {
                case Expose:
                    /* draw(); */
                    /* XFillRectangle(display, window, gc, 10, 10, 50, 50); */
                    break;

                case ConfigureNotify:
                    window_width = e.xconfigure.width;
                    window_height = e.xconfigure.height;
                    pixmap = XCreatePixmap(display, window, window_width, window_height, 24);
                    break;

                case KeyPress:
                    for(u8 x=0 ; x<GC_WIDTH ; x++)
                        for(u8 y=0 ; y<GC_HEIGHT ; y++) {
                            u8 c = (x+y)%2 == 0 ? 255 : 0;
                            fb[x][y] = Color{c, c, c};
                        }
                    /* XDestroyWindow(display, window); */
                    break;

                case DestroyNotify:
                    destroy = true;
                    break;

                /* case ClientMessage: */
                /*     if(e.xclient.data.l[0] == wmDeleteMessage) */
                /*         running = false; */
                /*     break; */
            }
        }
        return destroy;
    }
};

GHandler the_ghandler;
