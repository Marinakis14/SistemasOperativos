// Fichero "fibonacci.h"

#include <stdio.h>
int CalcFibonacci(int n);

void MostrarFibonacci(int n) {
	if (CalcFibonacci(n) == -1) {
		printf("La posición no puede ser negativo");
	} else {
		printf("El número de la sucesión de Fibonacci en la posición %d es: %d", n, CalcFibonacci(n));
	}
}
