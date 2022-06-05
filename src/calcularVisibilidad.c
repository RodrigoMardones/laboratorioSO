#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "math.h"


double* calculateDiscVisibility(double** matrix, int nfilas){
	double mediaReal = 0;
	double mediaImaginaria = 0;
	double ruidoTotal = 0;
	double potencia = 0;

	for(int i=0; i < nfilas; i++){
		//Coord visibilidad
		double u = matrix[i][0];
		double v = matrix[i][1];
		//Parte real
		double real = matrix[i][2];
		//Pater imaginaria
		double imaginario = matrix[i][3];
		//Ruido
		double ruido = matrix[i][4];
		//Distancia
		double distancia = matrix[i][5];

		//double expresion = pow(real,2) + sqrt(pow(imaginario,2));
		potencia = potencia + pow(real,2);
		potencia  = potencia + sqrt(pow(imaginario,2));
		mediaReal = mediaReal + real;
		mediaImaginaria = mediaImaginaria + imaginario;
		ruidoTotal = ruidoTotal + ruido;
	}
	
	mediaReal = (mediaReal/nfilas);
	mediaImaginaria = (mediaImaginaria/nfilas);

	double* calculos;
	calculos = (double*) malloc(sizeof(double)*4);
	calculos[0] = mediaReal;
	calculos[1] = mediaImaginaria;
	calculos[2] = potencia;
	calculos[3] = ruidoTotal;

	return calculos;
}




