add: fibonacci

fibonacci: fibonacci.o main.o
	gcc -g fibonacci.o main.o -o fibonacci

fibonacci.o: fibonacci.c
	cc -c fibonacci.c

main.o: main.c fibonacci.h
	cc -c main.c

.PHONY: all clean

clean:
	rm -rf *.o
	rm fibonacci
