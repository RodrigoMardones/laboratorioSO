#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h> 
#include "leerArchivo.h"

int** setRange(int deep,int discs);
void writeDiscs(char*** matrix, int** ranges, int nfilas,int ncols,  int discs, char* salida);

int main(int argc,char* argv[]){


    //Variables locales
    char*** matrix = NULL;
    int** rangos = NULL;
    char *filename, *outputfile;
    int nfilas, ncolumnas,ancho,discos;

    filename = "./src/uvplaneco1.csv";
    outputfile = "./src/propiedades.txt";
    nfilas = 0;
    ncolumnas = 6; 
    ancho = 100;
    discos = 4;

    nfilas = rowNumber(filename);	
    matrix = setMatrix(matrix, nfilas, ncolumnas);
    matrix = fillMatrix(filename, matrix);
    matrix = setDisc(matrix, nfilas);
    rangos = setRange(ancho,discos);
    unlink(outputfile);
    writeDiscs(matrix, rangos, nfilas,ncolumnas, discos, outputfile);
	return 0;
}


