#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	pid_t pid;
        int status;

	if (fork() > 0) {
		printf("Padre: esperando a que finalice el proceso hijo...\n");
		waitpid(pid, &status, 0);
		if (WIFEXITED(status)) {
			printf("Padre: hijo (PID=%d) finalizado con estado %d.\n", pid, WEXITSTATUS(status));
		} else {
			printf("Padre: proceso hijo finalizado anormalmente.\n");
		}
	}
	else {
		printf("Hijo: durmiendo unos segundos...\n");
		sleep(1);
		srand(getpid());
		int d = rand() %3; /* Asigna a d un n. aleatorio entre 0 y 2) */
		printf("Hijo: calculando 100/%d = %d y finalizando.\n", d, 100/d);
		exit(1);
	}

	return 0;
}
