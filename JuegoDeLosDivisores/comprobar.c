// Fichero para comprobar si quedan divisores

#include <stdio.h>
#include <stdbool.h>

bool ComprobarDivisores(int numeros[], int cantidad_n, int numeros_usados[], int cantidad_nu, int *puntuación1, int *puntuación2) {
	// hacemos una lista con los numeros que faltan
	int numeros_restantes[10];
	int contador = 0;

	for (int i = 0; i < cantidad_n; i++) {
		bool añadir = true;
		for (int j = 0; j < cantidad_nu; j++) {
			if (numeros[i] == numeros_usados[j]) {
				añadir = false;
			}
		}
		// si el numero no esta en la lista de usados, añadir sera true
		if (añadir) {
			numeros_restantes[contador] = numeros[i];
			contador++;
		}
	}

	// tenemos la lista con los numeros restantes, ahora miramos si alguno puede dividirse por otro
	for (int i = 0; i < contador; i++) {
		for (int j = 0; j < contador; j++) {
			if (numeros_restantes[i] % numeros_restantes[j] == 0 && numeros_restantes[i] != numeros_restantes[j]) {
				// si hay algun divisor terminamos
				return false;
			}
		}
	}

	// si no encontramos ningun divisor entonces sumamos los numeros restantes a la puntuación de la maquina y terminamos
	int suma = 0;
	for (int i = 0; i < contador; i++) {
		suma += numeros_restantes[i];
	}
	*puntuación2 += suma;
	printf("No quedan divisores!\n\nYo sumo %d.\n\nResultado final:\nTu puntuación: %d.\nMi puntuación: %d.\n", suma, *puntuación1, *puntuación2);
	return true;
}
