#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) 
{
	if (fork() > 0) {
		printf("Padre: esperando a que finalice el proceso hijo...\n");
		pid_t pid = wait(NULL);
		printf("Padre: hijo (%d) finalizado.\n", pid);
	}
	else {
		printf("Hijo: durmiendo unos segundos...\n");
		sleep(1);
		printf("Hijo: finalizado.\n");
	}

	return 0;
}
