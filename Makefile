all:
	cd autogen && python2 gen_opcodes_stuff.py
	clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lglfw -g -lz -Wall -O3
