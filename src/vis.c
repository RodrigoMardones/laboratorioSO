#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "unistd.h"
#include "math.h"
#include "calcularVisibilidad.h"

#define READ 0
#define WRITE 1


int main(int argc,char* argv[]){

	char filename[50];
	int nfilas = strtod(argv[1], (char **)NULL);
	char*** matrix = NULL;

	//recibir dato de pipein
	read(STDIN_FILENO, filename,50);

	//calcular visibilidad
	matrix = setMatrix(matrix, nfilas, 6);
	matrix = fillMatrix(filename, matrix,nfilas);
	char* precalculo = (char*) malloc(sizeof(char*)*200);
	precalculo = calculateDiscVisibility(matrix,nfilas);	
	char calculo[200];
	strcpy(calculo, precalculo);
	//enviar dato a pipeout
	write(STDOUT_FILENO,calculo,200);



	return 0;
}