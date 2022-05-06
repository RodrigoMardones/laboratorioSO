#include "leerArchivo.h"

int main(){
    int filas;
    int cols = 6;
    char*** matrix = NULL;
    matrix = readFile("./src/uvplaneco1.csv", &filas, cols);
    setDistance(matrix, filas);
    // printMatrix(matrix, filas,6);
    return 0;
}