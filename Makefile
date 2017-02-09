all:
	cd autogen && python2 gen_opcodes_stuff.py
	clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lX11 -g -Wall -O0
