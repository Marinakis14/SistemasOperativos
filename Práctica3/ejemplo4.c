#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(char argc, char* argv[])
{
	char * myargv[] = {"/noexiste", "-1", NULL};
	char * myenv[] = {NULL};

	if (execve(myargv[0], myargv, myenv) == -1){
		perror("Error lanzando el programa de ejemplo.");
		exit(-1);
	}

	printf("Boo!!\n");

	return 0;
}

// No aparece la cadena Boo!! porque al ejecutar execve() se ejecuta un nuevo programa, y como los parametros son correctos, entra en el nuevo programa y en este caso ejecuta el comando ls y por eso salen listados los ficheros que hay en el directorio, al entrar en el nuevo programa, el inicial nunca llega a el printf("Boo!!\n") y por tanto nunca aparece la cadena por pantalla

// Al cambiar el nombre del ejecutable de /bin/ls a otro que no exite, no se puede entrar en el nuevo programa y por tanto continua en el programa actual y llega al exit(-1) que hace que finalice y por eso tampoco se be el Boo!! por pantalla
