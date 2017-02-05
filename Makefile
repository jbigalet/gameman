all:
	python2 opcodes.py
	clang++ gameman.cpp -std=c++14 -lGL -lGLEW -lglfw -g -lz -Wall -O0
