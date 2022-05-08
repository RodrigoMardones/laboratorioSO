#include "leerArchivo.h"
#include "vis.h"
#include "unistd.h"

int main(int argc,char* argv[]){

    //Variables locales
    char*** matrix = NULL;
    int** rangos = NULL;
    char *inputfile, *outputfile,*inputf, *outputf, *deep, *ndisc;
    int nfilas, ncolumnas, ancho, discos;

    //Obtener argumentos
    int opt;
    //"i, o, d, n" son las variables en los argumentos, y : significan que tienen argumento adicional
    while((opt = getopt(argc, argv,"i:o:d:n:")) != -1) 
    { 
        switch(opt) 
        { 
            case 'i': 
                inputf = optarg;
             case 'o':
                outputf = optarg; 
                break; 
             case 'd': 
                deep = optarg; 
                break;
             case 'n': 
                ndisc = optarg; 
                break;
                
        } 
    }

    //Concatenar ruta dr archivos en /src
    char *src= "./src/";
    inputfile = (char*) malloc(sizeof(char*)*255);
    outputfile = (char*) malloc(sizeof(char*)*255);
    strcat(inputfile,src);
    strcat(inputfile,inputf);
    strcat(outputfile,src);
    strcat(outputfile,outputf);

    //Inicializar variables
    nfilas = 0;
    ncolumnas = 6; 
    ancho = strtol(deep, NULL,0);
    discos = strtol(ndisc, NULL,0);

    nfilas = rowNumber(inputfile);	
    matrix = setMatrix(matrix, nfilas, ncolumnas);
    matrix = fillMatrix(inputfile, matrix);
    matrix = setDisc(matrix, nfilas);
    rangos = setRange(ancho,discos);
    unlink(outputfile);
    writeDiscs(matrix, rangos, nfilas,ncolumnas, discos, outputfile);
	return 0;
}


