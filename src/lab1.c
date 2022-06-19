#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "unistd.h"
#include "math.h"
#include <sys/wait.h>
#include <sys/types.h>
#include "leerArchivo.h"

#define READ 0
#define WRITE 1


int main(int argc,char* argv[]){

    //Variables locales
    char*** matrix = NULL;
    int** rangos = NULL;
    char *inputfile, *outputfile,*inputf, *outputf, *deep, *ndisc;
    int nfilas, ncolumnas, ancho, numdiscos,nvis,cantvisi;
    cantvisi = 0;

    //Obtener argumentos
    int opt;
    //"i, o, d, n" son las variables en los argumentos, y : significan que tienen argumento adicional
    while((opt = getopt(argc, argv,"i:o:d:n:b")) != -1) 
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
             case 'b': 
                cantvisi = 1; 
                break;                
        } 
    }

    //Concatenar ruta dr archivos en /src
    char *src= "./src/";
    char *dest = "./";
    inputfile = (char*) malloc(sizeof(char*)*255);
    outputfile = (char*) malloc(sizeof(char*)*255);
    strcat(inputfile,src);
    strcat(inputfile,inputf);
    strcat(outputfile,dest);
    strcat(outputfile,outputf);

    //Inicializar variables
    nfilas = 0;
    ncolumnas = 6; 
    ancho = strtol(deep, NULL,0);
    numdiscos = strtol(ndisc, NULL,0);

    nfilas = rowNumber(inputfile);	
    matrix = setMatrix(matrix, nfilas, ncolumnas);
    matrix = fillMatrix(inputfile, matrix,nfilas);
    matrix = setDisc(matrix, nfilas);
    rangos = setRange(ancho,numdiscos);
    unlink(outputfile);

    //disco 1 rangos [1][x] = rango [i][x]

   for (int i=0; i < numdiscos; i++)  {
        int numerodisco = i+1;
        nvis = visNumber(matrix, nfilas, rangos[i][0], rangos[i][1]);
        char *tempFileName  = discByRange(matrix, nfilas, rangos[i][0], rangos[i][1],nvis, numerodisco);

        char* nvischar = (char*) malloc(sizeof(char*)*50);
        sprintf(nvischar, "%d", nvis);
        char* args[3] = {"./build/vis",nvischar,NULL}; 

        //Pipes
        int pipein[2];
        int pipeout[2];
        pipe(pipein);
        pipe(pipeout);

        //Fork
        pid_t pid = fork();
        if (pid == 0) { //hijo
            close(pipein[WRITE]);  
            dup2(pipein[READ],STDIN_FILENO);  
            close(pipeout[READ]); 
            dup2(pipeout[WRITE],STDOUT_FILENO);     
            execv("./build/vis",args);
            perror("exec ls failed");
            exit(0);
        }
        else{ //padre 
            char precalculo[200];
            char* calculo = (char*) malloc(sizeof(char*)*200);
            close(pipein[READ]);  
            close(pipeout[WRITE]);
            //enviar datos
            char filenamedisc[50];
            strcpy(filenamedisc, tempFileName);
            write(pipein[WRITE],filenamedisc,50);  
            //recibir datos
            read(pipeout[READ],precalculo,200);  
            strcpy(calculo, precalculo);
            writeFile(calculo,outputfile,numerodisco);
            unlink(tempFileName);
            if(cantvisi == 1){
                printf("Soy el hijo de pid %d, procesé %d visibilidades\n",pid,nvis);
            }
            wait(NULL);
        }
    }

	return 0;
}