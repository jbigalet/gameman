all:
	cd autogen && python2 gen_opcodes_stuff.py
	# clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lX11 -g -Wall -O0
	clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lX11 -g -Wall -O3
	# clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lX11 -g -Wall -fsanitize=address -O0
	# clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lX11 -g -Wall -fsanitize=undefined
	# clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lX11 -g -Wall -fsanitize=undefined -fsanitize=address
