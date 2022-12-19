CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lX11 

resize: resize.o utils.o

resize.o: resize.cpp

utils.o: utils.cpp

resize.cpp:

utils.cpp:
