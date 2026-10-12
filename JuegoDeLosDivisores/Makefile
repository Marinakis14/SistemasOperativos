add: JuegoDeLosDivisores

JuegoDeLosDivisores: logica.o main.o printlist.o comprobar.o
	gcc -g logica.o main.o printlist.o comprobar.o -o JuegoDeLosDivisores

logica.o: logica.c
	cc -c logica.c

main.o: main.c logica.h printlist.h comprobar.h
	cc -c main.c

printlist.o: printlist.c
	cc -c printlist.c

comprobar.o: comprobar.c
	cc -c comprobar.c

.PHONY: add clean

clean: 
	rm -rf *.o
	rm -rf JuegoDeLosDivisores

