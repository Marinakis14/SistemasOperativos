add: race

race: race.o player.o
	gcc -g race.o player.o -o race

race.o: race.c player.h
	cc -c race.c

player.o: player.c player.h
	cc -c player.c

.PHONY: add, clean

clean: 
	rm -rf *.o
	rm -rf race
