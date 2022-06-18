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
    double** matrixbyrange = NULL;
    int** rangos = NULL;
    char *inputfile, *outputfile,*inputf, *outputf, *deep, *ndisc;
    int nfilas, ncolumnas, ancho, numdiscos,nvis;

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
    matrix = fillMatrix(inputfile, matrix);
    matrix = setDisc(matrix, nfilas);
    rangos = setRange(ancho,numdiscos);
    // matriz con matrices chicas cortadas por rangos 
    unlink(outputfile);

    //prueba para un disco
    nvis = visNumber(matrix, nfilas, rangos[1][0], rangos[1][1]);
    char *temporalFileName = discByRange(matrix, 3, rangos[1][0], rangos[1][1], nvis);
    
    //disco 1 rangos [1][x] = rango [i][x]

    char* nvischar = (char*) malloc(sizeof(char*)*50);
    sprintf(nvischar, "%d", nvis);
    char* args[3] = {"./build/vis",nvischar, temporalFileName,NULL}; 

    //Pipes
    int pipein[2];
    int pipeout[2];
    pipe(pipein);
    pipe(pipeout);


    //Fork
    pid_t pid = fork();
    if (pid == 0) { //hijo
        //esto funciona
        close(pipein[WRITE]);  
        dup2(pipein[READ],STDIN_FILENO);  
        close(pipeout[READ]); 
        dup2(pipeout[WRITE],STDOUT_FILENO);     
        execv("./build/vis",args);
        perror("exec ls failed");
        exit(0);
    }
    else{ //padre 
        char nvisc[100];
        int status;
        close(pipein[READ]);  
        close(pipeout[WRITE]);
        //enviar datoa
        write(pipein[WRITE], "hola",4);  
        //recibir datos
        read(pipeout[READ], nvisc,sizeof(nvisc));  
        printf("%s\n",nvisc);
        waitpid(pid, &status,0);
    }

    
    //Escribir archivo
    //FILE* f = fopen(outputfile, "a");
    //fprintf(f,"Disco %i:\n",(i+1));
    //fprintf(f,"Media real: %f \n", mediaReal);
	//fprintf(f,"Media imaginaria: %f \n", mediaImaginaria);
	//fprintf(f,"Potencia: %f \n", potencia);
    //fprintf(f,"Ruido total: %f \n \n",ruidoTotal);
    //fclose(f);



	return 0;
}


