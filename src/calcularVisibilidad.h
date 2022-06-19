#include "calcularVisibilidad.c"

/**
 * @brief Set the Matrix object
 * 
 * @param matrix 
 * @param nfil 
 * @param ncol 
 * @return char*** 
 */
char*** setMatrix(char*** matrix, int nfil, int ncol);

/**
 * @brief fill the matrix with file info
 * 
 * @param filename 
 * @param matrix 
 * @param nfilas
 * @return char*** 
 */
char*** fillMatrix(char* filename, char*** matrix,int nfilas);

/**
 * @brief calculates disc visbility in a certain range
 * 
 * @param matrix 
 * @param nfilas 
 * @return char*
 */
char* calculateDiscVisibility(char*** matrix, int nfilas);

