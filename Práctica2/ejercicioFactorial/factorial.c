// Fichero "factorial.c" para calcular el factorial de un numero

int CalcFactorial(int numero) {
	int resultado = 0;
	// Nos aseguramos que el numero sea valido para calcular el factorial
	if (numero < 0) {
		return 0;
	} else if (numero == 0 || numero == 1) { // Caso base
		return 1;
	} else { // Caso recursivo
		resultado = numero*CalcFactorial(numero - 1);
	}
	return resultado;
}
