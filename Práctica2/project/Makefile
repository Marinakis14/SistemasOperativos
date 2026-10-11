all: hello

hello: hello.o imprime.o
	cc hello.o imprime.o -o hello

hello.o: hello.c imprime.h
	cc -c hello.c

imprime.o: imprime.c
	cc -c imprime.c

.PHONY: all, clean

clean: 
	rm -rf *.o
	rm -rf hello
	
