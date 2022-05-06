#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char*** createMatrix(int nfilas, int nCols){
    char*** matriz = (char***) malloc(sizeof(char**)*nfilas);
	for(int i=0;i<nfilas;i++){	
		matriz[i] = (char**) malloc(sizeof(char*)*nCols);
		for(int j=0;j<nCols;j++){	
			matriz[i][j] = (char*) malloc(sizeof(255));
		}
	}
    return matriz;
}

void storeData(char*** matrix, char* filename){
	FILE* vis_csv = fopen(filename,"r");
	int charPerLine = 0;
	int numcolumna = 0;
    int numfila = 0;
    int inum = 0;
	// para guardar valor leido
    char buff[255];
	// para traspasar valor
    char numero[255];
    if(vis_csv){
		while (fgets(buff, 255, (FILE*)vis_csv) != NULL){
			charPerLine = 0;
			numcolumna = 0;
			inum = 0;

		 	while(buff[charPerLine] != '\0'){ 
				if(buff[charPerLine] != ',' && buff[charPerLine] != '\n'){		
					numero[inum] = buff[charPerLine];
					inum++;        			
  				}else if(buff[charPerLine] == ','){
  					numero[inum] = '\0';
					// printf("%s en (%d,%d) ", numero,numfila, numcolumna);
  					strcpy(matrix[numfila][numcolumna],numero);
  					numcolumna++;
  					inum = 0;
  				}else if(buff[charPerLine] == '\n'){
  					numero[inum] = '\0';
					// printf("valor final: %s \n", numero);
  					strcpy(matrix[numfila][numcolumna],numero);
  					inum = 0;
				}else{
					break;
				}				
  				charPerLine++;
			}
			numfila++;		
		}			
	}
}

char*** readFile(char* filename, int* nfilas, int ncols){
    FILE* vis_csv = fopen(filename,"r");
    *nfilas = 0;
    char buff[255];
    if(vis_csv){
        while (fgets(buff, 255, (FILE*)vis_csv) != NULL){
			// printf("%s \n", buff);
			*nfilas = *nfilas + 1;
		}
		fclose(vis_csv);
    }
	char*** matrix;
    matrix = createMatrix(*nfilas, ncols);
    storeData(matrix, filename);
	return matrix;
}

void setDistance(char*** matrix, int filas){
    // dos solo de muestra, entre 0 y 2 toma un rango ese rango ese el disco
	for(int i=0; i<filas;i++){
		double u = strtod(matrix[i][0], (char **)NULL);
		double v = strtod(matrix[i][1], (char **)NULL);
		double radio = (u*u) + (v*v);
		int disco = sqrt(radio);
		char* discostr = (char*) malloc(sizeof(255)); 
		sprintf(discostr, "%d", disco);
		strcpy(matrix[i][5],discostr);	
	}
}

void printMatrix(char*** matrix,int nfilas,int ncols){
    for(int i=0; i<nfilas;i++){
        for(int j=0;j<ncols;j++){
			printf("(%d, %d) ",i,j);
			printf("%s \n", matrix[i][j]);
        }
    }
}

char* parseArgs(int argc, char* argv[], char* toFind){
    for(int i=0; i<argc;i++){
        int isFlag = strcmp(toFind, argv[i]);
        if(isFlag == 0){
            return argv[i+1];
        }
    }
    return "";
}

