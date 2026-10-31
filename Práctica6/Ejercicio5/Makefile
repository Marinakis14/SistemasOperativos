all: ejemplo5 ejemplo5_mejorado

ejemplo5: ejemplo5.o 
	cc ejemplo5.o -pthread -o ejemplo5

ejemplo5_mejorado: ejemplo5_mejorado.o 
	cc ejemplo5_mejorado.o -pthread -o ejemplo5_mejorado

ejemplo5.o: ejemplo5.c
	cc -c ejemplo5.c

ejemplo5_mejorado.o: ejemplo5_mejorado.c
	cc -c ejemplo5_mejorado.c

.PHONY: all clean

clean:
	rm -rf *.o
	rm -rf ejemplo5
	rm -rf ejemplo5_mejorado

