all: ejemplo2

ejemplo2: ejemplo2.o
	cc ejemplo2.o -pthread -o ejemplo2

ejemplo2.o: ejemplo2.c
	cc -c ejemplo2.c

.PHONY: all clean

clean:
	rm -rf *.o
	rm -rf ejemplo2
