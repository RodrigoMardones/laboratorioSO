#include "stdlib.h"
#include "stdio.h"
#include "string.h"

char *trim(char *s) {
    char *ptr;
    if (!s)
        return NULL;
    if (!*s)
        return s;    
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}

void createFileFirstResult(char*** matrix,int nfilas, int ncols){
	FILE* salida = fopen("./src/propiedades.csv","w");
	for(int i=0;i<nfilas;i++){
		char buff[512] = "";
		fprintf(salida, "%s,%s,%s,%s,%s,%s\n",
			trim(matrix[i][0]),
			trim(matrix[i][1]),
			trim(matrix[i][2]),
			trim(matrix[i][3]),
			trim(matrix[i][4]),
			trim(matrix[i][5])
		);
	}
	fclose(salida);
}