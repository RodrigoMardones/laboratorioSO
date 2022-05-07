#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "leerArchivo.h"

void calculateDiscVisibility(char*** matrix, int initFilas, int endFilas, int ncols, int vis, char* salida);

int main(int argc,char* argv[]){

    char*** matrix = NULL;
    char *filename, *outputfile;
    int nfilas, ncolumnas;

    filename = "./src/uvplaneco1.csv";
    outputfile = "./src/propiedades.txt";
    nfilas = 0;
    ncolumnas = 6; 

    nfilas = rowNumber(filename);	
    matrix = setMatrix(matrix, nfilas, ncolumnas);
    matrix = fillMatrix(filename, matrix);
    matrix = setDisc(matrix, nfilas);
    calculateDiscVisibility(matrix, 1000,2000,ncolumnas,1000,outputfile);
	return 0;
}


