// Fichero "fibonacci.c" para calcular el n-ésimo término de la sucesión de Fibonacci

int CalcFibonacci(int posicion) {
	int resultado = 0;
	//Comprobamos que el numero sea válido
	if (posicion < 1) { 
	       return (-1);
	} else if (posicion == 1) { // Caso base 1
		return 0;
	} else if (posicion == 2) { // Caso base 2 porque la recursividad usa 2 pasos antes
		return 1;
	} else {
		resultado = CalcFibonacci(posicion - 1) + CalcFibonacci(posicion - 2);
	}
}
