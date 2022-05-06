#include "leerArchivo.h"


int main(int argc, char* argv[]){

    char* input = parseArgs(argc,argv, "-i");
    char* output = parseArgs(argc, argv, "-o");
    char* discs = parseArgs(argc, argv, "-n");
    char* deep = parseArgs(argc, argv, "-d");
    char* flag = parseArgs(argc, argv, "-b");
    printf("%s \n", input);
    printf("%s \n", output);
    printf("%s \n", discs);
    printf("%s \n", deep);
    printf("%s \n", flag);
    
    int filas;
    int cols = 6;
    char*** matrix = NULL;
    matrix = readFile(input, &filas, cols);
    setDistance(matrix, filas);
    printMatrix(matrix, 10,6);
    return 0; 
}