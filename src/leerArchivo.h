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
 * @param nfilas
 * @return char*** 
 */
char*** fillMatrix(char* filename, char*** matrix,int nfilas);

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
 * @brief save matrix info to file
 * 
 * @param matrix 
 * @param nfilas
 * @param filename 
 * @return void
 */
void storeData(char*** matrix,int nfilas, char* filename);


/**
 * @brief create temporal file with disc info
 * 
 * @param matrix 
 * @param nfilas 
 * @param initFilas 
 * @param endFilas 
 * @param nvis
 * @param numdisco
 * @return char*
 */
char* discByRange(char*** matrix, int nfilas, int initFilas, int endFilas, int nvis,int numdisco);


/**
 * @brief save disc visbility to file
 * 
 * @param calculo 
 * @param outputfile 
 * @param numdisc
 * @return void
 */
void writeFile(char* calculo,char* outputfile,int numdisc);