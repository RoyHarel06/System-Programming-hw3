CC=gcc

all: isort txtfind

isort: insertion.c
	$(CC) -Wall -g -o isort insertion.c

txtfind: txtfind.c
	$(CC) -Wall -g -o txtfind txtfind.c
	
.PHONY: clean valgrind
	
clean:
	rm -f *.o *.a *.so connections