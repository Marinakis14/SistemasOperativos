all: factorial

factorial: factorial.o main.o
	cc factorial.o main.o -o factorial

factorial.o: factorial.c
	cc -c factorial.c

main.o: main.c factorial.h
	cc -c main.c

.PHONY: clean, all

clean:
	rm -rf *.o
	rm factorial
