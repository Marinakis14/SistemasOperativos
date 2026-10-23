#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	int estado;
	if (fork() > 0) {
		printf("Padre: esperando a que finalice el proceso hijo...\n");
		pid_t pid = wait(NULL);
		printf("Padre: hijo (PID=%d) finalizado con estado %d.\n", pid, estado);
	}
	else {
		printf("Hijo: durmiendo unos segundos...\n");
		sleep(1);
		printf("Hijo: finalizado.\n");
		exit(1);
	}

	return 0;
}
