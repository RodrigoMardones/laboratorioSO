#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "ctype.h"
#include "string.h"

int i,j;

int rowNumber(char* filename){
	char buffer[255];
	FILE* vis_csv;
	int nfilas = 0;

    vis_csv= fopen(filename,"r");
	if(vis_csv){	
		while (fgets(buffer, 255, (FILE*)vis_csv) != NULL){
			nfilas = nfilas + 1;
		}
		fclose(vis_csv);
	}
	return nfilas;
}
	
char*** setMatrix(char*** matrix, int nfil, int ncol){	
	matrix = (char***) malloc(sizeof(char**)*nfil);
	for(i=0;i<nfil;i++){	
		matrix[i] = (char**) malloc(sizeof(char*)*ncol);
		for(j=0;j<ncol;j++){	
			matrix[i][j] = (char*) malloc(sizeof(255));
		}
	}
	return matrix;
}

double** setMatrixDouble(double** matrix, int nfil, int ncol){	
	matrix = (double**) malloc(sizeof(double*)*nfil);
	for(i=0;i<nfil;i++){	
		matrix[i] = (double*) malloc(sizeof(double)*ncol);
	}

	for(i=0;i<nfil;i++){
			for(j=0;j<ncol;j++){	
			matrix[i][j] =0.0;
		}
	}
	return matrix;
}

char*** fillMatrix(char* filename, char*** matrix){
	char buffer[255];
	char numero[255];
	FILE* vis_csv;
	int inum,numfila,numcolumna;
	numfila = 0;

	vis_csv= fopen(filename,"r");
	if(vis_csv){	
		while (fgets(buffer, 255, (FILE*)vis_csv) != NULL){
			numcolumna = 0;
			i = 0;
			inum = 0;
		 	while(buffer[i] != '\0'){ 
        			if(buffer[i] != ',' && buffer[i] != '\n'){		
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
	}
	fclose(vis_csv);
	return matrix;
}

char*** setDisc(char*** matriz, int nfil){
	for(i=0;i<nfil;i++){
		double u = strtod(matriz[i][0], (char **)NULL);
		double v = strtod(matriz[i][1], (char **)NULL);
		double radio = (u*u) + (v*v);
		int disco = sqrt(radio);
		char* discostr = (char*) malloc(sizeof(255)); 
		sprintf(discostr, "%d", disco);
		strcpy(matriz[i][5],discostr);		
	}
	return matriz;
}

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

double** discByRange(char*** matrix, int nfilas, int initFilas, int endFilas, int nvis){

	double** discmatrix; 
	int j = 0;
	discmatrix = setMatrixDouble(discmatrix, nvis, 6);
	for(int i=0; i < nfilas; i++){
		double distancia = strtod(matrix[i][5], (char **)NULL);	
		//Rango de disco final (x hasta el final)
		if(endFilas == 0)
		{
			if(distancia >= initFilas){
				discmatrix[j][0] = strtod(matrix[i][0], (char **)NULL);
				discmatrix[j][1] = strtod(matrix[i][1], (char **)NULL);
				discmatrix[j][2] = strtod(matrix[i][2], (char **)NULL);
				discmatrix[j][3] = strtod(matrix[i][3], (char **)NULL);
				discmatrix[j][4] = strtod(matrix[i][4], (char **)NULL);
				discmatrix[j][5] = strtod(matrix[i][5], (char **)NULL);
				j++;
			}
		}
		//Rango de disco finito (x a y)
		else
		{
			if(distancia >= initFilas && distancia <= endFilas){
				discmatrix[j][0] = strtod(matrix[i][0], (char **)NULL);
				discmatrix[j][1] = strtod(matrix[i][1], (char **)NULL);
				discmatrix[j][2] = strtod(matrix[i][2], (char **)NULL);
				discmatrix[j][3] = strtod(matrix[i][3], (char **)NULL);
				discmatrix[j][4] = strtod(matrix[i][4], (char **)NULL);
				discmatrix[j][5] = strtod(matrix[i][5], (char **)NULL);
				j++;
			}
		}
	}

	return discmatrix;
}
