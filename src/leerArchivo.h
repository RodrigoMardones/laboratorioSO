#include "leerArchivo.c"

/**
 * @brief Create a Matrix object
 * 
 * @param nfilas 
 * @param nCols 
 * @return char*** 
 */
char*** createMatrix(int nfilas, int nCols);

/**
 * @brief store data in matrix object
 * 
 * @param matrix 
 * @param filename 
 */
void storeData(char*** matrix, char* filename);
/**
 * @brief reads a file, initialize a matrix and store the data
 * 
 * @param filename 
 * @param nfilas 
 * @param ncols 
 * @return char***
 */
char*** readFile(char* filename, int* nfilas, int ncols);

/**
 * @brief setDistance like d(u,v) = (U**2 + v**2) ** 1/2
 * 
 * @param matrix 
 * @param filas 
 */
void setDistance(char*** matrix, int filas);

/**
 * @brief just prints the matrix
 * 
 * @param matrix 
 * @param nfilas 
 * @param ncols 
 */
void printMatrix(char*** matrix,int nfilas,int ncols);

/**
 * @brief retorna valor de argumento entregado si existe
 * 
 * @param argc largo de lista de args
 * @param argv lista de args
 * @param toFind valor a encontrar
 * @return char* 
 */
char* parseArgs(int argc, char* argv[], char* toFind);