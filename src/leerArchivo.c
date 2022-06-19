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

char*** fillMatrix(char* filename, char*** matrix,int nfilas){
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

void storeData(char*** matrix,int nfilas, char* filename){
	FILE* tempvis = fopen(filename,"w");

	for(int i=0; i < nfilas; i++){
		fprintf(tempvis,"%s,",matrix[i][0]);
		fprintf(tempvis,"%s,",matrix[i][1]);
		fprintf(tempvis,"%s,",matrix[i][2]);
		fprintf(tempvis,"%s,",matrix[i][3]);
		fprintf(tempvis,"%s,",matrix[i][4]);
		fprintf(tempvis,"%s",matrix[i][5]);
		if(i<nfilas-1){
			fprintf(tempvis,"%s","\n");
		}		
	}

    fclose(tempvis);

}

char* discByRange(char*** matrix, int nfilas, int initFilas, int endFilas, int nvis,int numdisco){

	char*** discmatrix; 
	int j = 0;
	discmatrix = setMatrix(discmatrix, nvis, 6);
	for(int i=0; i < nfilas; i++){
		double distancia = strtod(matrix[i][5], (char **)NULL);	
		//Rango de disco final (x hasta el final)
		if(endFilas == 0)
		{
			if(distancia >= initFilas){
				strcpy(discmatrix[j][0],matrix[i][0]);
				strcpy(discmatrix[j][1],matrix[i][1]);
				strcpy(discmatrix[j][2],matrix[i][2]);
				strcpy(discmatrix[j][3],matrix[i][3]);
				strcpy(discmatrix[j][4],matrix[i][4]);
				strcpy(discmatrix[j][5],matrix[i][5]);
				j++;
			}
		}
		//Rango de disco finito (x a y)
		else
		{
			if(distancia >= initFilas && distancia <= endFilas){
				strcpy(discmatrix[j][0],matrix[i][0]);
				strcpy(discmatrix[j][1],matrix[i][1]);
				strcpy(discmatrix[j][2],matrix[i][2]);
				strcpy(discmatrix[j][3],matrix[i][3]);
				strcpy(discmatrix[j][4],matrix[i][4]);
				strcpy(discmatrix[j][5],matrix[i][5]);
				j++;
			}
		}
	}
	char* filename = (char*) malloc(sizeof(char*)*30);
	char* charnumdisco = (char*) malloc(sizeof(char*)*1);
	sprintf(charnumdisco, "%d", numdisco);
	strcat(filename, "./tempdisco");
	strcat(filename, charnumdisco);
	strcat(filename, ".txt");
	unlink(filename);
	storeData(discmatrix,nvis,filename);
	return filename;
}



void writeFile(char* calculo,char* outputfile,int numdisc){
	char mediaReal[50];
	char mediaImaginaria[50];
	char potencia[50];
	char ruidoTotal[50];

	int inum,numfila,numcolumna;
	numfila = 0;

	numcolumna = 1;
	i = 0;
	inum = 0;
	while(calculo[i] != '\0'){ 
        if(calculo[i] != ','){		
			switch(numcolumna) 
        	{ 
            	case 1: 
                	mediaReal[inum] = calculo[i];				
					break;
				case 2: 
                	mediaImaginaria[inum] = calculo[i];
					break;
				case 3: 
                	potencia[inum] = calculo[i];
					break;
				case 4: 
                	ruidoTotal[inum] = calculo[i];
					break;
				default:
					break;	    
        	} 
        	inum++;        			
  		}else if(calculo[i] == ','){
			switch(numcolumna) 
        	{ 
            	case 1: 
                	mediaReal[inum] = '\0';				
					break;
				case 2: 
                	mediaImaginaria[inum] = '\0';
					break;
				case 3: 
                	potencia[inum] = '\0';
					break;
				default:
					break;	    
        	} 
  			numcolumna++;
  			inum = 0;
		}else{
			break;
		}		
  		i++;	
	}	
	ruidoTotal[inum] = '\0';			

	//Escribir archivo
    FILE* destfile = fopen(outputfile, "a");
    fprintf(destfile,"Disco %i:\n",(numdisc));
    fprintf(destfile,"Media real: %s \n", mediaReal);
	fprintf(destfile,"Media imaginaria: %s \n", mediaImaginaria);
	fprintf(destfile,"Potencia: %s \n", potencia);
    fprintf(destfile,"Ruido total: %s \n",ruidoTotal);
    fclose(destfile);

}

