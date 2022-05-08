#include "leerArchivo.c"
/**
 * @brief returns number of row in matrix
 * 
 * @param filename 
 * @return int 
 */
int rowNumber(char* filename);

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
 * @return char*** 
 */
char*** fillMatrix(char* filename, char*** matrix);

/**
 * @brief Set the Disc object
 * 
 * @param matriz 
 * @param nfil 
 * @return char*** 
 */
char*** setDisc(char*** matriz, int nfil);
