all: foominer fooblockcheck

foominer: foominer.o foominerlib.o
	cc foominer.o foominerlib.o -o foominer -lcrypto

fooblockcheck: fooblockcheck.o foominerlib.o
	cc fooblockcheck.o foominerlib.o -o fooblockcheck -lcrypto

foominer.o: foominer.c
	cc -c foominer.c

foominerlib.o: foominerlib.c
	cc -c foominerlib.c

fooblockcheck.o: fooblockcheck.c
	cc -c fooblockcheck.c

.PHONY: all clean

clean: 
	rm -rf *.o
	rm -rf foominer
	rm -rf fooblockcheck
	rm -rf *.solved
