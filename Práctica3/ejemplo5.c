#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(char argc, char* argv[])
{
	char * myargv[] = {"ejemplo5b", "Uno", "Dos", "Tres", "Catorce!", NULL};
	char * myenv[] = {NULL};

	printf("Me. (PID: %d)\n", getpid());
	int status;
	pid_t pid = fork();

	if (pid > 0) {
		waitpid(pid,&status,0);
		printf("Padre: Hijo finalizado con valor de estado %d\n", status);
	} else if (pid < 0) {
		perror("Error en el fork");
		return(-1);
	} else {
		if (execve(myargv[0], myargv, myenv) == -1){
			perror("Error lanzando el programa de ejemplo.");
			exit(-1);
		}
	}

	return 0;
}
