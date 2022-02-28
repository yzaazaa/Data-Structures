//
//  matrix.h
//
//
//  Created by El Kahoui on 24/02/2021.
//

#ifndef matrix_h
#define matrix_h

#include <stdio.h>
#include<stdlib.h>

#endif /* matrix_h */

                        /* The vector structure */
struct vector
{
    unsigned length;
    double * head;
};
typedef struct vector vector;

/* Prototypes */

/* Construction and destruction */
vector createVector(unsigned);
void freeVector(vector);

/* Printing and scaning */
void printVector(vector);
void scanVector(vector *);

/* Arithmetic operations */
vector sumVector(vector, vector);
vector scaleVector(double, vector);



                        /* The matrix structure */

struct matrix
{
    unsigned row;
    unsigned column;
    double ** head;
};
typedef struct matrix matrix;

/* Prototypes */

/* Construction and destruction */
matrix createMatrix(unsigned, unsigned);
void freeMatrix(matrix);

/* Printing and scaning */
void printMatrix(matrix);
void scanMatrix(matrix *);

/* Arithmetic operations */
matrix sumMatrix(matrix,matrix);
matrix productMatrix(matrix,matrix);
matrix scaleProductMatrix(double,matrix);


/* Echelon forms */
matrix transposeMatrix(matrix);
void rowExchangeMatrix(matrix *M,unsigned i,unsigned j);
void addRowMatrix(matrix *,vector,unsigned);
matrix rowEchelonForm(matrix M);
matrix columnEchelonForm(matrix);
