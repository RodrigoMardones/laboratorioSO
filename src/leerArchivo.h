
int i,j,inum;
int nfilas = 0;
int ncolumnas = 6;
int numfila = 0;
int numcolumna = 0;	
char buff[255];
char numero[255];
char*** matriz;
FILE* vis_csv;
	
void LeerArchivo(){
	//Obtener número de filas
    vis_csv= fopen("./src/uvplaneco1.csv","r");
	if(vis_csv){	
		while (fgets(buff, 255, (FILE*)vis_csv) != NULL){
			nfilas = nfilas + 1;
		}
		fclose(vis_csv);
	}
	
	//Crear Matriz	
	matriz = (char***) malloc(sizeof(char**)*nfilas);
	for(i=0;i<nfilas;i++){	
		matriz[i] = (char**) malloc(sizeof(char*)*ncolumnas);
		for(j=0;j<ncolumnas;j++){	
			matriz[i][j] = (char*) malloc(sizeof(255));
		}
	}

	//Leer Archivo y guardar en matriz
	vis_csv= fopen("./src/uvplaneco1.csv","r");
	if(vis_csv){
		int count = 0;	
		while (fgets(buff, 255, (FILE*)vis_csv) != NULL){
			numcolumna = 0;
			if(count == 2){ break;}	
			i = 0;
			inum = 0;
		 	while(buff[i] != '\0'){ 
        			if(buff[i] != ',' && buff[i] != '\n'){		
        				numero[inum] = buff[i];
        				inum++;        			
  				}else if(buff[i] == ','){
  					numero[inum] = '\0';
  					strcpy(matriz[numfila][numcolumna],numero);
  					numcolumna++;
  					inum = 0;
  				}else if(buff[i] == '\n'){
  					numero[inum] = '\0';
  					strcpy(matriz[numfila][numcolumna],numero);
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
	fclose(vis_csv);
}

//Establece el disco de la visibilidad
void EstablecerDisco(){
	for(i=0;i<2;i++){
		double u = strtod(matriz[i][0], (char **)NULL);
		double v = strtod(matriz[i][1], (char **)NULL);
		double radio = (u*u) + (v*v);
		int disco = sqrt(radio);
		char* discostr = (char*) malloc(sizeof(255)); 
		sprintf(discostr, "%d", disco);
		strcpy(matriz[i][5],discostr);	
	}
}

