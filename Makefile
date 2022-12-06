CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lX11 

resize: resize.o

resize.o: resize.cpp

resize.cpp:
	$(CC) -c $@
