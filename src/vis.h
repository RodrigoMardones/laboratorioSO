#include "vis.c"

/**
 * @brief Set the Range object
 * 
 * @param deep 
 * @param discs 
 * @return int** 
 */
int** setRange(int deep, int discs);

/**
 * @brief calculates disc visbility in a certain range
 * 
 * @param matrix 
 * @param nfilas 
 * @param initFilas 
 * @param endFilas 
 * @param nvis 
 * @param numdisco 
 * @param salida 
 */
void calculateDiscVisibility(char*** matrix, int nfilas, int initFilas, int endFilas, int nvis, int numdisco, char* salida);

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