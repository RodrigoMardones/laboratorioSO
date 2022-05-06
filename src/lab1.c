#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "leerArchivo.h"


void vertabla(){
	for(i=0;i<2;i++){
		for(j=0;j<ncolumnas;j++){
			printf("%s\n",matriz[i][j]);	
		}
	}
}
int main(){

	LeerArchivo();
	EstablecerDisco();
	vertabla();		
	return 0;
}


