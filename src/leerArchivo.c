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

