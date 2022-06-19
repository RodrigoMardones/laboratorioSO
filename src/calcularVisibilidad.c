#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "math.h"

char*** setMatrix(char*** matrix, int nfil, int ncol){	
	matrix = (char***) malloc(sizeof(char**)*nfil);
	for(int i=0;i<nfil;i++){	
		matrix[i] = (char**) malloc(sizeof(char*)*ncol);
		for(int j=0;j<ncol;j++){	
			matrix[i][j] = (char*) malloc(sizeof(255));
		}
	}
	return matrix;
}

char*** fillMatrix(char* filename, char*** matrix,int nfilas){
	char buffer[255];
	char numero[255];
	FILE* tempvis;
	int inum,numfila,numcolumna,i;
	numfila = 0;

	tempvis= fopen(filename,"r");
	if(tempvis){	
		while (fgets(buffer, 255, (FILE*)tempvis) != NULL){
			numcolumna = 0;
			i = 0;
			inum = 0;
		 	while(buffer[i] != '\0'){ 
        		if(buffer[i] != ',' && buffer[i] != '\n' && buffer[i] != '\0'){		
        				numero[inum] = buffer[i];
        				inum++;        			
  				}else if(buffer[i] == ','){
  					numero[inum] = '\0';
  					strcpy(matrix[numfila][numcolumna],numero);
  					numcolumna++;
  					inum = 0;
  				}else if(buffer[i] == '\n'){
  					numero[inum] = '\0';
  					strcpy(matrix[numfila][numcolumna],numero);
  					inum = 0;
				}else{
				
					break;
				}				
  				i++;
			}	
			numfila++;			
		}
		numero[inum] = '\0';
  		strcpy(matrix[numfila-1][numcolumna],numero);		
	}
	fclose(tempvis);
	return matrix;
}


char* calculateDiscVisibility(char*** matrix, int nfilas){
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

		potencia = potencia + pow(real,2);
		potencia = potencia + sqrt(pow(imaginario,2));
		mediaReal = mediaReal + real;
		mediaImaginaria = mediaImaginaria + imaginario;
		ruidoTotal = ruidoTotal + ruido;
	}
	
	mediaReal = (mediaReal/nfilas);
	mediaImaginaria = (mediaImaginaria/nfilas);

	char* calculos =  (char*) malloc(sizeof(char*)*250);
	char* tempcalculos = (char*) malloc(sizeof(char*)*30);
	
	sprintf(tempcalculos, "%f", mediaReal);
	strcpy(calculos,tempcalculos);
	strcat(calculos,",");
	sprintf(tempcalculos, "%f", mediaImaginaria);
	strcat(calculos,tempcalculos);
	strcat(calculos,",");
	sprintf(tempcalculos, "%f", potencia);
	strcat(calculos,tempcalculos);
	strcat(calculos,",");
	sprintf(tempcalculos,"%f", ruidoTotal);
	strcat(calculos,tempcalculos);
	
	return calculos;
}




