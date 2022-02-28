//
//  polynom.c
//
//
//  Created by El Kahoui on 28/03/2021.
//

#include "polynom.h"

/* The function degrePoly */

int degrePoly(polynom P)
{
    if(P!=NULL)
        return P->exponent;
    return -INT_MAX;
}

/* The function makeMonomial*/

polynom makeMonom(double c,unsigned e)
{
    polynom P=NULL;
    if(c!=0)
    {
        P=(polynom)malloc(sizeof(monom));
        P->coeff=c;
        P->exponent=e;
        P->next=NULL;
    }
    return P;
}

/* The function addMonomial */

void addMonom(polynom *P,monom *M)
{
    /* The case M==0 */
    if(M->coeff==0)
        return;
    /* The case P is empty */
    if(*P==NULL)
    {
        polynom Q=makeMonom(M->coeff,M->exponent);
        *P=Q;
        return;
    }
    /* The case no monomial needs to be created */

    if((*P)->exponent==M->exponent)
    {
        if((*P)->coeff==-M->coeff)
        {
            polynom temp=*P;
            *P=(*P)->next;
            free(temp);
        }
        else
            (*P)->coeff=(*P)->coeff+M->coeff;
        return;
    }

    /* Make the monomial to be added */

    polynom Q=makeMonom(M->coeff,M->exponent);

    /* The case the monomial should be added at the beginning */
    if((*P)->exponent<M->exponent)
    {
        Q->next=*P;
        *P=Q;
        return;
    }
    /* The general case */
    polynom temp=*P;
    polynom temp1=*P;
    while(temp!=NULL)
    {
        if(temp->exponent==M->exponent)
        {
            if(temp->coeff==-M->coeff)
            {
                temp1->next=temp->next;
                free(temp);
            }
            else
                temp->coeff=temp->coeff+M->coeff;
            return;
        }
        if(temp->exponent>M->exponent)
        {
            temp1=temp;
            temp=temp->next;
        }
        else
            break;
    }
    Q->next=temp;
    temp1->next=Q;
    return;
}

/* The function freePoly */
void freePoly(polynom P)
{
    while(P!=NULL)
    {
        polynom temp=P;
        P=P->next;
        free(temp);
    }
    return;
}

/* The function printPoly*/
void printPoly(polynom P)
{
    if(P==NULL)
    {
        printf("%d\n",0);
        return;
    }
    polynom temp=P;
    while(temp!=NULL)
    {
        if(temp->exponent>1)
            printf("%lf X^%u",temp->coeff,temp->exponent);
        else
        {
            if(temp->exponent==1)
                printf("%lf X",temp->coeff);
            else
                printf("%lf",temp->coeff);
        }
        if(temp->next!=NULL)
        {
            if(temp->next->coeff>0)
                printf(" + ");
            else
                printf(" ");

        }
        temp=temp->next;
    }
    printf("\n");
    return;
}

/* The function sumPoly */

polynom sumPoly(polynom P1,polynom P2)
{
    polynom R=NULL;
    polynom temp=P1;
    while(temp!=NULL)
    {
        addMonom(&R,temp);
        temp=temp->next;
    }
    temp=P2;
    while(temp!=NULL)
    {
        addMonom(&R,temp);
        temp=temp->next;
    }
    return R;
}

/* The function oppositePoly */

polynom oppositePoly(polynom P)
{
    polynom R=NULL;
    polynom temp=P;
    monom M={0,0,NULL};
    while(temp!=NULL)
    {
        M.coeff=-temp->coeff;
        M.exponent=temp->exponent;
        addMonom(&R,&M);
        temp=temp->next;
    }
    return R;
}

/* The function substractPoly */

polynom substractPoly(polynom P,polynom Q)
{
    return sumPoly(P,oppositePoly(Q));
}

/* The function productPoly */

polynom productPoly(polynom P,polynom Q)
{
    polynom R=NULL;
    polynom temp1=P;
    polynom temp2=Q;
    monom M={0,0,NULL};
    while(temp1!=NULL)
    {
        temp2=Q;
        while(temp2!=NULL)
        {
            M.coeff=temp1->coeff*temp2->coeff;
            M.exponent=temp1->exponent+temp2->exponent;
            addMonom(&R,&M);
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return R;
}

/* The function scalePoly */

polynom scalePoly(double a,polynom P)
{
    if(a==0)
    {
        return NULL;
    }
    polynom R=NULL;
    polynom temp=P;
    monom M={0,0,NULL};
    while(temp!=NULL)
    {
        M.coeff=a*temp->coeff;
        M.exponent=temp->exponent;
        addMonom(&R,&M);
        temp=temp->next;
    }
    return R;
}

/* The function derivePoly */

polynom derivePoly(polynom P)
{
    polynom R=NULL;
    polynom temp=P;
    monom M={0,0,NULL};
    while(temp!=NULL)
    {
        if(temp->exponent>0)
        {
            M.coeff=temp->coeff*temp->exponent;
            M.exponent=temp->exponent-1;
            addMonom(&R,&M);
        }
        temp=temp->next;
    }
    return R;
}

/* The function primitivePoly */

polynom primitivePoly(polynom P, double c)
{
    polynom R=NULL;
    polynom temp=P;
    monom M={c,0,NULL};
    addMonom(&R,&M);
    while(temp!=NULL)
    {
        M.exponent=temp->exponent +1;
        M.coeff=temp->coeff/M.exponent;
        addMonom(&R,&M);
        temp=temp->next;
    }
    return R;
}

/* The function evalPoly */
/* Naive method */
double evalPoly(polynom P,double a)
{
    double v=0;
    if(P==NULL)
        return v;
    polynom temp=P;
    while(temp!=NULL)
    {
        v+=temp->coeff*pow(a,temp->exponent);
        temp=temp->next;
    }
    return v;
}

/* Euclidean division */
polynom euclideRemainder(polynom P,polynom Q)
{
    if(Q==NULL)
    {
        printf("Divion by zero.\n");
        exit(EXIT_FAILURE);
    }
    if(degrePoly(Q)==0)
        return NULL;
    polynom R=sumPoly(NULL,P);
    while(degrePoly(R)>=degrePoly(Q))
    {
        double c=-R->coeff/Q->coeff;
        unsigned e=R->exponent-Q->exponent;
        monom M={0,0,NULL};
        polynom temp=Q;
        while(temp!=NULL)
        {
            M.coeff=c*temp->coeff;
            M.exponent=e+temp->exponent;
            addMonom(&R,&M);
            temp=temp->next;
        }
    }
    return R;
}

/* The main function */

int main()
{
    //system("clear");
    polynom P=NULL;
    monom M={3,4,NULL};
    monom M1={1,1,NULL};
    monom M2={-1,0,NULL};
    monom M3={2,5,NULL};
    monom M4={2,2,NULL};
    monom M5={3,5,NULL};
    addMonom(&P,&M);
    printPoly(P);
    addMonom(&P,&M1);
    printPoly(P);
    addMonom(&P,&M2);
    printPoly(P);
    polynom Q=NULL;
    polynom S = euclideRemainder(P, Q);
    /*addMonom(&Q,&M);
    printPoly(Q);
    addMonom(&Q,&M4);
    printPoly(Q);
    addMonom(&Q,&M5);
    printPoly(Q);
    printf("\n\n");
    printPoly(P);
    printPoly(Q);
    polynom R=sumPoly(P,Q);
    printPoly(R);
    printf("Debut\n\n");
    polynom A=NULL;
    polynom B=NULL;
    monom M6={1,1,NULL};
    monom M7={-1,0,NULL};
    monom M8={1,2,NULL};
    monom M9={1,0,NULL};
    addMonom(&A,&M6);
    addMonom(&A,&M7);
    addMonom(&B,&M8);
    addMonom(&B,&M6);
    addMonom(&B,&M9);

    printPoly(A);
    printPoly(B);
    polynom C=productPoly(A,B);
    printPoly(C);
    polynom D=primitivePoly(C,3);
    printPoly(D);
    printf("Division\n");
    printPoly(euclideRemainder(D,C));
    printf("%lf\n",evalPoly(C,1));
    freePoly(D);*/


    return 0;

}
