// File "foominer.c"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include "foominerlib.h"
#include <time.h>
#include <signal.h>
#include <stdbool.h>

void señal_usuario(int n);
void señal_sigint(int n);
void señal_alarma(int n);

int contador = 0;
bool tiempo = false;

int main(int argc, char* argv[])
{	
  int difficulty;
  uint32_t nonce_start, nonce_end, nonce_sol;
  struct fooblock b;
  char* blockfile;

  signal(SIGUSR1, señal_usuario);
  signal(SIGINT, señal_sigint);
  signal(SIGALRM, señal_alarma);

  if (argc < 5) { 
    printf("Too few arguments.\nUsage:\n");
    printf("%s <block file> <difficulty> <nonce start> <nonce end>\n", argv[0]);
    return -1; 
  }

  blockfile = argv[1];
  difficulty = atoi(argv[2]);
  nonce_start = (uint32_t) atol(argv[3]);
  nonce_end = (uint32_t) atol(argv[4]);

  if (fooblock_load(blockfile, &b) == -1) {
    return -1; 
  }
    
  if (fooblock_mine(&b, difficulty, nonce_start, nonce_end, &nonce_sol) == 0){
    printf("(%d) found nonce %u is valid.\n", getpid(), nonce_sol);
    fooblock_save_solved(blockfile, &b, nonce_sol);
    return 0;
  }
  printf("(%d) Nonce not found.\n", getpid());
  return 1;
}

void señal_usuario(int n) {
	printf("Miner (%d) working, %d hashes checked.\n", getpid(), hashes);
}

void señal_sigint(int n) {
	if (!tiempo) {
		printf("Requesting miner status.\n");
		kill(getpid(), SIGUSR1);
		printf("Press Ctrl+C again within 2 seconds to terminate.\n");
		contador ++;
		tiempo = true;
		alarm(2);
	} else if (contador > 0 && tiempo) {
		printf("Termination requested.\n");
		exit(0);
	}
}

void señal_alarma(int n) {
	printf("Termination cancelled.\n");
	tiempo = false;
	contador = 0;
}
