# makefile

COMPILE=gcc -g -Wall -c
LINK=gcc -g -Wall
SDL_CFLAGS=`sdl-config --cflags`
SDL_LIBS=`sdl-config --libs`


all: test

test: test.o graphics.o wrapper.o
	$(LINK) test.o graphics.o wrapper.o -o test $(SDL_LIBS)

test.o: test.c test.h
	$(COMPILE) test.c -o test.o $(SDL_CFLAGS)

graphics.o: graphics.c graphics.h
	$(COMPILE) graphics.c -o graphics.o $(SDL_CFLAGS)

wrapper.o: wrapper.c wrapper.h
	$(COMPILE) wrapper.c -o wrapper.o $(SDL_CFLAGS)

clean:
	rm *.o test
