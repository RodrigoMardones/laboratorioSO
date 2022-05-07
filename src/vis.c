#include <stdio.h>
#include <stdlib.h>
#include "utilsVis.h"
#include  "leerArchivo.h"

int main(int argc, char* argv[]){
	int filas;
    int initFilas = atoi(argv[1]);
    int endFilas = atoi(argv[2]);
    int cols = atoi(argv[3]);
    int deep = atoi(argv[4]);
    char* output = argv[5];
    char*** matrix = NULL;
    matrix = readFile("./build/intermedio.csv", &filas, cols);
	calculateDiscVisibility(matrix,initFilas, endFilas, cols, deep, output);
	return 0;
}