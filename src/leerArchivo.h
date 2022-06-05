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
 * @brief Set the Matrix object
 * 
 * @param matrix 
 * @param nfil 
 * @param ncol 
 * @return double** 
 */
double** setMatrixDouble(double** matrix, int nfil, int ncol);


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

/**
 * @brief Set the Range object
 * 
 * @param deep 
 * @param discs 
 * @return int** 
 */
int** setRange(int deep, int discs);

/**
 * @brief calculates the number of visibilities in a disc
 * 
 * @param matrix 
 * @param nfilas 
 * @param initFilas 
 * @param endFilas 
 * @return int 
 */
int visNumber(char*** matrix, int nfilas, int initFilas, int endFilas);

/**
 * @brief write the info calculating disc visibility on all discs
 * 
 * @param matrix 
 * @param ranges 
 * @param nfilas 
 * @param ncols 
 * @param discs 
 * @param salida 
 */
void writeDiscs(char*** matrix, int** ranges, int nfilas,int ncols,  int discs, char* salida);

/**
 * @brief convert discs info to matrix
 * 
 * @param matrix 
 * @param nfilas 
 * @param initFilas 
 * @param endFilas 
 * @param nvis
 * @return double**
 */
double** discByRange(char*** matrix, int nfilas, int initFilas, int endFilas, int nvis);

