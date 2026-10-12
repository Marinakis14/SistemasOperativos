// Fichero que contiene la lógica del juego

#include <stdio.h>
#include <stdbool.h>

void jugada(int n, int *puntuación1, int *puntuación2, int numeros[], int numeros_usados[], int *cantidad_usados) {
	// n es el número que ha elegido, el usuario

	// La lista con los numeros usados en este turno la paso como argumento para poder usarla en main y no tener que devolver nada
	int cant = 0; // para guardar los numeros en la lista

	// Vamos a comprobar que no se ha usado ya
	for (int i = 0; i < *cantidad_usados; i++) {
		if (n == numeros_usados[i]) {
			printf("El número %d no está en la lista!\nElige otro número:\n", n);
			return;
		}
	}

	// Vamos a comprobar también que n es un numero válido (entero entre 1 y 10)
	if (n < 1 || n > 10) {
		printf("El número %d no está en la lista!\nElige otro número:\n", n);
		return;
	}

	// Ahora vamos a ver los divisores que tiene n en la lista
	int divisores[10];
	int cantidad = 0; // para guardar los números en la lista

	for (int i = 0; i < 10; i++) { // Para recorrer todos los numero de la lista
		bool válido = true; // Para saber si es un número usado o no
		// Comprobamos que no se haya usado ya
		for (int j = 0; j < *cantidad_usados; j++) {
			// Si el numero ya se ha usado lo marcamos como no válido
			if (numeros[i] == numeros_usados[j]) {
				válido = false;
			}
		}
		if (válido == true) { // Comprobamos si es un divisor de nuestro número o no
			if (n % numeros[i] == 0 && numeros[i] != n) { // Si es un divisor de nuestro número lo añadimos a la lista
				divisores[cantidad] = numeros[i];
				cantidad++;
			}
		}
	}

	// Ahora tenemos todos los divisores de n en la lista divisores
	
	// Marcamos que hemos usado el numero n (elegido)
	numeros_usados[*cantidad_usados] = n;
	(*cantidad_usados)++;

	// Si no tiene divisores
	if (cantidad == 0) {
		printf("El %d no tiene divisores en la lista!\n", n);
		printf("Yo sumo %d.", n);
		*puntuación2 += n; // Sumamos el número a la puntuación de la máquina
	} else { 
		// Si hay divisores los ponemos todos en la lista de usados
		int suma = 0; // para saber lo que suma la máquina
		for (int i = 0; i < cantidad; i++) {
			numeros_usados[*cantidad_usados] = divisores[i];
			(*cantidad_usados)++;
			// sumamos el divisor a la puntuación de la máquina
			suma += divisores[i];
		}	 
		printf("Tu sumas %d.\nYo sumo %d.\n", n, suma);
		*puntuación2 += suma;
		// Sumamos el numero al usuario
		*puntuación1 += n;
	}	
	
	// Mostramos las puntuaciones de cada uno
	printf("\nTu puntuación: %d.\nMi puntuación: %d.\n", *puntuación1, *puntuación2);
}
