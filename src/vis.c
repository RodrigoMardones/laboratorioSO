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

	char hola[4];
	//recibir dato de pipein
	read(STDIN_FILENO, hola,sizeof(hola));

	int nfilas = strtod(argv[1], (char **)NULL);
	//double* calculo = calculateDiscVisibility(matrix,nfilas);	
	//enviar dato a pipeout
	write(STDOUT_FILENO,hola,sizeof(hola));

	return 0;
}