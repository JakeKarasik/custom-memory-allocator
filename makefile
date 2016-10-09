#CC     =       cc
CC      =       gcc
FLAGS   =       -Wall -g

COMPILE =       $(CC) $(FLAGS)

all: memgrind

memgrind: memgrind.c mymalloc.c mymalloc.h
	$(COMPILE) mymalloc.c memgrind.c -o memgrind

clean:
	rm -rf *.o memgrind
