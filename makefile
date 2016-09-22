#CC     =       cc
CC      =       gcc
FLAGS   =       -Wall -g

COMPILE =       $(CC) $(FLAGS)

all: mymalloc memgrind

mymalloc:	mymalloc.c mymalloc.h
	$(COMPILE) mymalloc.c -o mymalloc

memgrind: memgrind.c
	$(COMPILE) memgrind.c -o memgrind

clean:
	rm -rf *.o mymalloc memgrind
