// Fichero "factorial.h"

#include <stdio.h>

int CalcFactorial(int numero);

void MostrarFactorial(int numero) {
	printf("El factorial de %d es %d.\n", numero, CalcFactorial(numero));
}
