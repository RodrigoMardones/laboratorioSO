#include <stdio.h>
#include <stdlib.h>
#include "utilsVis.h"
#include  "leerArchivo.h"

int main(int argc, char* argv[]){
	int filas;
    int cols = 6;
    char*** matrix = NULL;
    matrix = readFile("./build/intermedio.csv", &filas, cols);
	calculateDiscVisibility(matrix,0, filas, cols, filas,"salida.txt");
	return 0;
}