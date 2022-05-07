#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Establecer rango de distancia de visibilidad de cada disco de acuedo al ancho
int** setRange(int deep, int discs){

    int** ranges;
	ranges = (int**) malloc(sizeof(int*)*discs);
	for(int i=0;i<discs;i++){	
		ranges[i] = (int*) malloc(sizeof(int)*2);
	}

	int i;
    int start = 0;
	int end = deep - 1;

	for(i=0;i<discs;i++){	
		ranges[i][0] = start;
		ranges[i][1] = end;
		if(i == discs - 1){
			ranges[i][1] = 0;
		}
		start = end + 1;
		end = end + deep;
	}

	return ranges;
}

//Calcular los datos de cada disco
void calculateDiscVisibility(char*** matrix, int nfilas, int initFilas, int endFilas, int nvis, int numdisco, char* salida){
	double mediaReal = 0;
	double mediaImaginaria = 0;
	double ruidoTotal = 0;
	double potencia = 0;

	for(int i=0; i < nfilas; i++){
		//Coord visibilidad
		double u = strtod(matrix[i][0], (char **)NULL);
		double v = strtod(matrix[i][1], (char **)NULL);
		//Parte real
		double real = strtod(matrix[i][2], (char **)NULL);
		//Pater imaginaria
		double imaginario = strtod(matrix[i][3], (char **)NULL);
		//Ruido
		double ruido = strtod(matrix[i][4], (char **)NULL);
		//Distancia
		double distancia = strtod(matrix[i][5], (char **)NULL);
		//Rango de disco final (x hasta el final)
		if(endFilas == 0)
		{
			if(distancia >= initFilas){
				double expresion = pow(real,2) + sqrt(pow(imaginario,2));
				potencia = potencia + expresion;
				mediaReal = mediaReal + real;
				mediaImaginaria = mediaImaginaria + imaginario;
				ruidoTotal = ruidoTotal + ruido;
			}
		}
		//Rango de disco finito (x a y)
		else
		{
			if(distancia >= initFilas && distancia <= endFilas){
				double expresion = pow(real,2) + sqrt(pow(imaginario,2));
				potencia = potencia + expresion;
				mediaReal = mediaReal + real;
				mediaImaginaria = mediaImaginaria + imaginario;
				ruidoTotal = ruidoTotal + ruido;
			}
		}
	}

	mediaReal = (mediaReal/nvis);
	mediaImaginaria = (mediaImaginaria/nvis);


    FILE* f = fopen(salida, "a");
	fprintf(f,"Disco %i:\n",numdisco);
    fprintf(f,"Media real: %f \n", mediaReal);
	fprintf(f,"Media imaginaria: %f \n", mediaImaginaria);
	fprintf(f,"Potencia: %f \n", potencia);
	fprintf(f,"Ruido total: %f \n \n",ruidoTotal);
    fclose(f);
}

//Calcular el n° de distancias de visibilidad en cada disco
int visNumber(char*** matrix, int nfilas, int initFilas, int endFilas){	
	int i,j,numbervis;
	numbervis = 0;
	for(i=0; i<nfilas; i++){
		int vis = atoi(matrix[i][5]);
		if (endFilas == 0){
				if(vis >= initFilas){
			numbervis++;
			}
		}else{
			if(vis >= initFilas && vis <= endFilas){
				numbervis++;
			}
		}
	}
	return numbervis;
}

//Escribir la info correspondiente a cada disco
void writeDiscs(char*** matrix, int** ranges, int nfilas,int ncols,  int discs, char* salida){
	int i,j,nvis;
	for(i=0; i<discs; i++){
			nvis = visNumber(matrix, nfilas, ranges[i][0], ranges[i][1]);
			calculateDiscVisibility(matrix, nfilas, ranges[i][0], ranges[i][1], nvis,(i + 1),salida);
	}

}


