all: ejemplo4

ejemplo4: ejemplo4.o
	cc ejemplo4.o -pthread -o ejemplo4

ejemplo4.o: ejemplo4.c
	cc -c ejemplo4.c

.PHONY: all clean

clean:
	rm -rf *.o
	rm -rf ejemplo4

