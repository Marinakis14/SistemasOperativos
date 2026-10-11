// Fichero "main.c" para ejecutar el calculo del factorial

#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char* argv[]) {
	int numero;

	if (argc <2) {
		printf("Insuficiente número de argumentos.\n");
		return(-1);
	}

	numero = atoi(argv[1]);
	MostrarFactorial(numero);
	return 0;
}	
