// Fichero "main.c"

#include <stdio.h>
#include <stdlib.h>
#include "logica.h"
#include "printlist.h"
#include "comprobar.h"

int main(void) {
	int numero_elegido;
	int puntuación1 = 0;
	int puntuación2 = 0;
	int numeros[10] = {1,2,3,4,5,6,7,8,9,10};
	int numeros_usados[10] = {0};
	int cantidad_usados = 0;
	int numeros_restantes = 10;
	int numeros_usados_este_turno[10] = {0};

	// Vamos a añadir una condición para saber cuando terminar

	while (numeros_restantes != 0) {
		// Mostramos la lista de numeros restantes por pantalla
		MostrarLista(numeros, 10,  numeros_usados, cantidad_usados);

		// Comprobamos si quedan divisores o no
		bool parar = ComprobarDivisores(numeros, 10, numeros_usados, cantidad_usados, &puntuación1, &puntuación2);

		if (parar) { // si no quedan divisores
			break;
			// ComprobarDivisores suma los numeros restantes automaticamente si ya no quedan divisores
		}

		printf("Elige un número:\n");
		
		if (scanf("%d", &numero_elegido) == 1) {
			jugada(numero_elegido, &puntuación1, &puntuación2, numeros, numeros_usados, &cantidad_usados);
			numeros_restantes = 10 - cantidad_usados;
		}

	}

	// Si ya no quedan numeros salimos del bucle
	if (puntuación1 > puntuación2) {
		printf("HAS GANADO!!!");
	} else if (puntuación1 == puntuación2) {
		printf("Hemos empatado, repite el juego para desempatar");	
	} else {
		printf("Yo gano!, repite el juego para jugar la revancha");
	}
	return 0;
}	
