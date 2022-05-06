#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char* filename = "./src/uvplaneco1.csv";

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
    int i = 0;
    int numcolumna = 0;
    int numfila = 0;
    int inum = 0;
    char buff[255];
    char numero[255];
    if(vis_csv){
		int count = 0;	
		while (fgets(buff, 255, (FILE*)vis_csv) != NULL){
			numcolumna = 0;
            // por qué rompe?
			if(count == 2){ break;}	
			i = 0;
			inum = 0;
		 	while(buff[i] != '\0'){ 
        			if(buff[i] != ',' && buff[i] != '\n'){		
        				numero[inum] = buff[i];
        				inum++;        			
  				}else if(buff[i] == ','){
  					numero[inum] = '\0';
  					strcpy(matrix[numfila][numcolumna],numero);
  					numcolumna++;
  					inum = 0;
  				}else if(buff[i] == '\n'){
  					numero[inum] = '\0';
  					strcpy(matrix[numfila][numcolumna],numero);
  					inum = 0;
				}else{
				
					break;
				}				
  				i++;
			}	
			numfila++;		
			count++;	
		}			
	}
}


char*** readFile(char* filename) {
    FILE* vis_csv = fopen(filename,"r");
    int nfilas = 0;
    int ncolumnas = 6;
    char buff[255];
    if(vis_csv){
        while (fgets(buff, 255, (FILE*)vis_csv) != NULL){
			nfilas = nfilas + 1;
		}
		fclose(vis_csv);
    }
    char*** matrix = createMatrix(nfilas, ncolumnas);
    storeData(matrix, filename);
    return matrix;
}

void EstablecerDisco(char*** matrix){
	for(int i=0;i<2;i++){
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
            printf("%s\n",matrix[i][j]);
        }
    }
}


