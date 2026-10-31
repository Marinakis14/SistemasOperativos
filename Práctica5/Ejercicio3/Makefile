all: foominer fooblockcheck foominer_mp

foominer: foominer.o foominerlib.o
	cc foominer.o foominerlib.o -o foominer -lcrypto

fooblockcheck: fooblockcheck.o foominerlib.o
	cc fooblockcheck.o foominerlib.o -o fooblockcheck -lcrypto

foominer_mp: foominer_mp.o foominer_mp.h
	cc foominer_mp.o -o foominer_mp -lcrypto

foominer.o: foominer.c
	cc -c foominer.c

foominer_mp.o: foominer_mp.c
	cc -c foominer_mp.c

foominerlib.o: foominerlib.c
	cc -c foominerlib.c

fooblockcheck.o: fooblockcheck.c
	cc -c fooblockcheck.c

.PHONY: all clean

clean: 
	rm -rf *.o
	rm -rf foominer
	rm -rf fooblockcheck
	rm -rf foominer_mp
	rm -rf *.solved
