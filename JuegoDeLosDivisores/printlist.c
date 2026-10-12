// Fichero para mostrar la lista con los números que quedan para elegir

#include <stdio.h>
#include <stdbool.h>

void MostrarLista(int numeros[], int cantidad_n, int numeros_usados[], int cantidad_nu) {

	printf("\n");

	for (int i = 0; i < cantidad_n; i++) {
		bool disponible = true; // para saber si se muestra el numero o no
		for (int j = 0; j < cantidad_nu; j++) {
			if (numeros[i] == numeros_usados[j]) {
				disponible = false;
			}
		}
		if (disponible) {
			printf("%d ", numeros[i]);
		} else {
			printf("* ");
		}
	}
	printf("\n");
}	
