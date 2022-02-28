//
//  matrix.c
//
//
//  Created by El Kahoui on 24/02/2021.
//

#include "matrix.h"

                            /* Implementation of the vector data structure */

/* The function create*/
vector createVector(unsigned n)
{
    vector V;
    V.length=n;
    V.head=(double *)malloc(n*sizeof(double));
    return V;
}

/* The function freeVector*/

void freeVector(vector V)
{
    if(V.head!=NULL)
        free(V.head);
    V.head=NULL;
}

/* Printing */
void printVector(vector V)
{
    if(V.length==0 || V.head==NULL)
    {
        printf("( )");
        return ;
    }
    printf("(");
    for(int i=0;i<V.length-1;i++)
    {
        printf("%lf, ",V.head[i]);
    }
    printf("%lf)",V.head[V.length-1]);
    printf("\n");
}

/* The function scanVector */
void scanVector(vector * V)
{
    if(V->head==NULL)
        return ;
    for(int i=0;i<V->length;i++)
        scanf("%lf",V->head+i);
    return;
}

/* The function sumVector*/
vector sumVector(vector U,vector V)
{
    if(U.length!=V.length)
        exit(EXIT_FAILURE);
    vector W=createVector(U.length);
    for(int i=0;i<W.length;i++)
        W.head[i]=U.head[i]+V.head[i];
    return W;
}

/* The function scaleVector */
vector scaleVector(double a,vector V)
{
    vector W=createVector(V.length);
    for(int i=0;i<W.length;i++)
        W.head[i]=a*V.head[i];
    return W;
}


                        /* Implementation of the matrix data structure */

/* The function createMatrix */
matrix createMatrix(unsigned r,unsigned c)
{
    matrix M={0,0,NULL};
    M.row=r;
    M.column=c;
    M.head=(double **)malloc(r*sizeof(double *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(double *)malloc(c*sizeof(double));
    return M;
}

/* The function freeMatrix */
void freeMatrix(matrix M)
{
    if(M.head!=NULL)
    {
        for(int i=0;i<M.row;i++)
        {
            if(M.head[i]!=NULL)
                free(M.head[i]);
        }
        free(M.head);
    }
    return;
}

/* The function printMatrix */
void printMatrix(matrix M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    for(int i=0;i<M.row;i++)
    {
        printf("| ");
        for(int j=0;j<M.column-1;j++)
            printf("%lf ",M.head[i][j]);
        printf("%lf |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}

/* The function scanMatrix */
void scanMatrix(matrix * M)
{
    if(M->head==NULL)
        return;
    for(int i=0;i<M->row;i++)
    {
        for(int j=0;j<M->column;j++)
            scanf("%lf",M->head[i]+j);
    }
    return;
}

/* The function sumMatrix */
matrix sumMatrix(matrix M,matrix N)
{
    if(M.row!=N.row || M.column!=N.column)
    {
        exit(EXIT_FAILURE);
    }
    matrix R=createMatrix(M.row,M.column);
    for(int i=0;i<R.row;i++)
    {
        for(int j=0;j<R.column;j++)
            R.head[i][j]=M.head[i][j]+N.head[i][j];
    }
    return R;
}

/* The function productMatrix */
matrix productMatrix(matrix M,matrix N)
{
    if(M.column!=N.row)
        exit(EXIT_FAILURE);
    matrix R=createMatrix(M.row,N.column);
    for(int i=0;i<R.row;i++)
    {
        for(int j=0;j<R.column;j++)
        {
            R.head[i][j]=0;
            for(int k=0;k<M.column;k++)
            {
                //printf("ICI\n");
                R.head[i][j]+=M.head[i][k]*N.head[k][j];
            }
        }
    }
    return R;
}

/* The function scaleProductMatrix */
matrix scaleProductMatrix(double a,matrix M)
{
    matrix R={0,0,NULL};
    if(M.head==NULL)
        return R;
    R=createMatrix(M.row,M.column);
    for(int i=0;i<M.row;i++)
    {
        for(int j=0;j<M.column;j++)
            R.head[i][j]=a*M.head[i][j];
    }
    return R;
}

/* The function transposeMatrix */
matrix transposeMatrix(matrix M)
{
    matrix R={0,0,NULL};
    if(M.head==NULL)
        return R;
    R=createMatrix(M.column,M.row);
    for(int i=0;i<R.row;i++)
    {
        for(int j=0;j<R.column;j++)
            R.head[i][j]=M.head[j][i];
    }
    return R;
}

/* The function rowExchangeMatrix */
void rowExchangeMatrix(matrix *M,unsigned i,unsigned j)
{
    if(i>=M->row || j>=M->row)
        return;
    if(M==NULL)
        return;
    double x;
    for(int k=0;k<M->column;k++)
    {
        x=M->head[i][k];
        M->head[i][k]=M->head[j][k];
        M->head[j][k]=x;
    }
    return;
}

/* The function addRowMatrix */
void addRowMatrix(matrix * M,vector V,unsigned i)
{
    if(M==NULL || V.head==NULL)
        return ;
    if(M->column!=V.length)
        exit(EXIT_FAILURE);
    if(i>=M->column)
        return ;
    for(int j=0;j<M->column;j++)
        M->head[i][j]+=V.head[j];
    return ;
}



matrix rowEchelonForm(matrix M)
{
    matrix P=createMatrix(M.row,M.column);
    for(int i=0; i<P.row; i++)
    {
        for (int j=0; j<P.column; j++)
            P.head[i][j]=M.head[i][j];
    }
    int temp=0;
    for(int i=0; i<P.row - 1; i++)
    {
        if(P.head[i][i]==0)
        {
            temp=0;
            for(int j=i; j<P.row; j++)
            {
                if(P.head[j][i]!=0)
                {
                    rowExchangeMatrix(&P, j, i);
                    break;
                }
                temp+=1;
            }
        }
        if(temp==P.row - i)
            continue;
        for(int j=i+1; j<P.row;j++)
        {
            double inv = (P.head[j][i]) / (P.head[i][i]);
            vector V=createVector(P.column);
            for(int k=0; k<V.length; k++)
                V.head[k] = - (P.head[i][k]) * inv;
                addRowMatrix(&P, V, j);
                freeVector(V);
        }
    }
    return P;
}




int main()
{
    /*printf("Testing the vector functions.\n");
    vector V=createVector(4);
    scanVector(&V);
    printVector(V);
    vector W=createVector(4);
    scanVector(&W);for(int i=0;i<V->length;i++)
        scanf("%lf",V->head+i
    printVector(W);
    vector Z=sumVector(V,W);
    vector T=scaleVector(3,W);
    printVector(T);*/
    /*printf("Testing the matrix functions.\n");
    matrix M=createMatrix(3,2);
    scanMatrix(&M);
    printMatrix(M);
    matrix N=createMatrix(2,3);
    scanMatrix(&N);
    printMatrix(N);
    matrix R=productMatrix(M,N);
    printMatrix(R);
    //printMatrix(transposeMatrix(R));
    rowExchangeMatrix(&R,1,2);
    printMatrix(R);
    vector V=createVector(3);
    scanVector(&V);
    addRowMatrix(&R,V,0);
    printMatrix(R);
    matrix H=rowEchelonForm(R);
    printMatrix(H);
    freeMatrix(M);
    freeMatrix(N);
    freeMatrix(R);*/
    matrix P=createMatrix(3,3);
    scanMatrix(&P);
    printMatrix(P);
    matrix Q=rowEchelonForm(P);
    printMatrix(Q);
    freeMatrix(P);
    return 0;
}
