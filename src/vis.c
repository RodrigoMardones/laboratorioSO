#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void calculateDiscVisibility(char*** matrix, int nfilas, int ncols, int vis){
	double mediaReal = 0;
	double mediaImaginaria = 0;
	double ruidoTotal = 0;
	double potencia = 0;
	for(int i = 0; i < nfilas; i++){
		double realPotencia = strtod(matrix[i][2], (char**) NULL);
		double imaginarioPotencia = strtod(matrix[i][3], (char**) NULL);
		double expresion = pow(realPotencia,2) + sqrt(pow(imaginarioPotencia,2));
		potencia = potencia + expresion;
		for(int j = 0; j < ncols;j++){
			if(j == 2){
				double real = strtod(matrix[i][j], (char **)NULL);
				mediaReal = mediaReal + real;
			}
			if(j == 3){
				double imaginario = strtod(matrix[i][j], (char **)NULL);
				mediaImaginaria = mediaImaginaria + imaginario;
			}
			if(j == 4){
				double ruido = strtod(matrix[i][j], (char**)NULL);
				ruidoTotal = ruidoTotal + ruido;
			}
		}
	}
	mediaReal = (mediaReal/vis);
	mediaImaginaria = (mediaImaginaria/vis);
	printf("media real: %f  \n", mediaReal);
	printf("media imaginaria: %f \n", mediaImaginaria);
	printf("potencia: %f \n", potencia);
	printf("ruido total: %f \n",ruidoTotal);	
}

