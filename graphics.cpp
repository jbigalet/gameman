#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>

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

const i8* vertex_shader_source = R"VSS(
#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 uv_in;

out vec2 uv;

void main() {
    gl_Position = vec4(pos.xy, 0.f, 1.f);
    uv = uv_in;
}
)VSS";

const i8* fragment_shader_source = R"VSS(
#version 330 core

uniform sampler2D tex;

in vec2 uv;
out vec4 color;

void main() {
    color = vec4(vec3(texture(tex, uv)), 1.f);
}
)VSS";


u32 compile_shader(u32 shader_type, const i8* shader_source) {
    u32 shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shader_source, NULL);
    glCompileShader(shader);
    i32 compile_res;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_res);
    if(!compile_res) {
        i8 compile_failure_log[512];
        glGetShaderInfoLog(shader, 512, NULL, compile_failure_log);
        std::cout << "shader compilation failed:\n" << compile_failure_log << std::endl;
        unreachable();
    }
    return shader;
}

struct GHandler {
    Display* display;
    Window window;
    GLXContext ctx;
    XSetWindowAttributes window_attr;

    u32 shader;
    u32 vao;
    u32 texture;

    Color fb[GC_HEIGHT][GC_WIDTH];

    void init(u32 mul=4) {
        for(u8 y=0 ; y<GC_HEIGHT ; y++)
            for(u8 x=0 ; x<GC_WIDTH ; x++)
                fb[y][x] = Color{0, 0, 0};

        display = XOpenDisplay(NULL);
        check(display != NULL);
        i32 screen_id = DefaultScreen(display);

        i32 glx_attr[] = {
            GLX_X_RENDERABLE,   true,
            GLX_DRAWABLE_TYPE,  GLX_WINDOW_BIT,
            GLX_RENDER_TYPE,    GLX_RGBA_BIT,
            GLX_X_VISUAL_TYPE,  GLX_TRUE_COLOR,
            GLX_RED_SIZE,       8,
            GLX_GREEN_SIZE,     8,
            GLX_BLUE_SIZE,      8,
            GLX_ALPHA_SIZE,     8,
            GLX_DEPTH_SIZE,     24,
            GLX_STENCIL_SIZE,   8,
            GLX_DOUBLEBUFFER,   true,
            0,
        };

        // get available config
        i32 fbc_count;
        GLXFBConfig* fbc_list = glXChooseFBConfig(display, screen_id, glx_attr, &fbc_count);
        check(fbc_list != 0);

        // choose best available config
        i32 max_samples = -1;
        GLXFBConfig fbc;
        XVisualInfo* visual_info = NULL;
        for(i32 i=0; i<fbc_count; i++) {
            XVisualInfo *new_visual_info = glXGetVisualFromFBConfig(display, fbc_list[i]);
            if(!new_visual_info)
                continue;

            i32 samples;
            glXGetFBConfigAttrib(display, fbc_list[i], GLX_SAMPLES, &samples);
            if(samples > max_samples){
                if(visual_info)
                    XFree(visual_info);

                fbc = fbc_list[i];
                max_samples = samples;
                visual_info = new_visual_info;
            }
        }
        XFree(fbc_list);

        // create window
        Window root_window = RootWindow(display, visual_info->screen);
        window_attr = {
            .colormap = XCreateColormap(display,
                                        root_window,
                                        visual_info->visual,
                                        AllocNone),
            .background_pixmap = 0,
            .border_pixel = 0,
            .event_mask = StructureNotifyMask
        };

        window = XCreateWindow(display,
                               root_window,  // parent window
                               0, 0,  // position
                               GC_WIDTH*mul, GC_HEIGHT*mul,  // size
                               1,  // border
                               visual_info->depth,  // depth
                               InputOutput,  // class
                               visual_info->visual,  // visual
                               CWBorderPixel | CWColormap | CWEventMask,  // value mask
                               &window_attr);  // attributes
        check(window);
        XFree(visual_info);

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

        XStoreName(display, window, "Gameman");
        XMapRaised(display, window);

        // create glx context

        // get glx context creator proc
        typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
        glXCreateContextAttribsARBProc glXCreateContextAttribsARB;
        glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB((GLubyte *)"glXCreateContextAttribsARB");

        int context_attribs[] = {
            GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
            GLX_CONTEXT_MINOR_VERSION_ARB, 3,
            GLX_CONTEXT_FLAGS_ARB,         GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
            GLX_CONTEXT_PROFILE_MASK_ARB,  GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
        };

        ctx = glXCreateContextAttribsARB(display, fbc, 0, true, context_attribs);
        XSync(display, false);  // force sync to make the next check effective
        check(ctx);

        glXMakeCurrent(display, window, ctx);

        XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);

        check(glewInit() == GLEW_OK);

        glClearColor(0.5, 0.5, 0.5, 1.);
        glViewport(0, 0, mul*GC_WIDTH, mul*GC_HEIGHT);


        // setup shaders

        u32 vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex_shader_source);
        u32 fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fragment_shader_source);

        shader = glCreateProgram();
        glAttachShader(shader, vertex_shader);
        glAttachShader(shader, fragment_shader);
        glLinkProgram(shader);

        i32 program_link_res;
        glGetProgramiv(shader, GL_LINK_STATUS, &program_link_res);
        if(!program_link_res) {
            i8 link_failure_log[512];
            glGetProgramInfoLog(shader, 512, NULL, link_failure_log);
            std::cout << "shader program linking failed:\n" << link_failure_log << std::endl;
            unreachable();
        }

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        glUseProgram(shader);


        // setup screen vao

        // 2d plane vertices with uvs
        f32 plane_vertices[] = {
            -1.0f,  1.0f,    0.0f, 1.0f,
            -1.0f, -1.0f,    0.0f, 0.0f,
            1.0f, -1.0f,     1.0f, 0.0f,

            -1.0f,  1.0f,    0.0f, 1.0f,
            1.0f, -1.0f,     1.0f, 0.0f,
            1.0f,  1.0f,     1.0f, 1.0f
        };

        glGenVertexArrays(1, &vao);
        u32 vbo;
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
                glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices), &plane_vertices, GL_STATIC_DRAW);

                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4*sizeof(f32), (GLvoid*)0);
                glEnableVertexAttribArray(0);

                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4*sizeof(f32), (GLvoid*)(2*sizeof(f32)));
                glEnableVertexAttribArray(1);

            glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            glActiveTexture(GL_TEXTURE0);
            glUniform1ui(glGetUniformLocation(shader, "tex"), 0);
    }

    ~GHandler() {
        XCloseDisplay(display);
    }

    void draw() {
        auto stime = now();

        u8 img[GC_HEIGHT][GC_WIDTH][3];
        for(u8 y=0 ; y<GC_HEIGHT ; y++)
            for(u8 x=0 ; x<GC_WIDTH ; x++) {
                img[GC_HEIGHT-1-y][x][0] = fb[y][x].r;
                img[GC_HEIGHT-1-y][x][1] = fb[y][x].g;
                img[GC_HEIGHT-1-y][x][2] = fb[y][x].b;
            }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, GC_WIDTH, GC_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, &img[0]);

        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glXSwapBuffers(display, window);
        /* std::cout << "draw in " << tdiff_micro(stime, now()) << std::endl; */
    }

    bool handle_events() {
        while(XEventsQueued(display, QueuedAfterFlush) > 0) {
            XEvent e;
            XNextEvent(display, &e);
            switch(e.type) {
                case Expose:
                    /* draw(); */
                    break;

                case ConfigureNotify:
                    glViewport(0, 0, e.xconfigure.width, e.xconfigure.height);
                    break;

                case KeyPress:

                    /* // debug: draw checkeer */
                    /* for(u8 y=0 ; y<GC_HEIGHT ; y++) */
                    /*     for(u8 x=0 ; x<GC_WIDTH ; x++) { */
                    /*         u8 c = (x+y)%2 == 0 ? 255 : 0; */
                    /*         fb[y][x] = Color{c, c, c}; */
                    /*     } */

                    if(XLookupKeysym(&e.xkey, 0) == 0xff1b){  // escape
                        glXDestroyContext(display, ctx);
                        XFreeColormap(display, window_attr.colormap);
                        XDestroyWindow(display, window);
                        XCloseDisplay(display);
                    }

                    break;

                case DestroyNotify:
                    return true;
                    break;

                /* case ClientMessage: */
                /*     if(e.xclient.data.l[0] == wmDeleteMessage) */
                /*         running = false; */
                /*     break; */
            }
        }
        return false;
    }
};

GHandler the_ghandler;
