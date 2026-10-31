all: fooblockcheck foominer_modificado foominer_mp

fooblockcheck: fooblockcheck.o foominerlib.o
	cc fooblockcheck.o foominerlib.o -o fooblockcheck -lcrypto

foominer_modificado: foominer_modificado.o foominerlib.o
	cc foominer_modificado.o foominerlib.o -o foominer_modificado -lcrypto

foominer.o: foominer.c
	cc -c foominer.c

foominer_modificado.o: foominer_modificado.c
	cc -c foominer_modificado.c

foominerlib.o: foominerlib.c
	cc -c foominerlib.c

fooblockcheck.o: fooblockcheck.c
	cc -c fooblockcheck.c

.PHONY: all clean

clean: 
	rm -rf *.o
	rm -rf fooblockcheck
	rm -rf foominer_modificado
	rm -rf *.solved
