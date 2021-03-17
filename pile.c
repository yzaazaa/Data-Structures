//
//  pile.c
//
//
//  Created by El Kahoui on 11/03/2020.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cellule
{
    int element;
    struct cellule * suivant;
};
typedef struct cellule cellule;
typedef cellule * pile;

// Prototypes
int pileVide(pile);
int lire(pile);
void empiler(int,pile *);
int depiler(pile *);
void affichage_pile(pile);
void liberer(pile);


// Pile vide
int pileVide(pile P)
{
    if(P==NULL)
        return 1;
    return 0;
}

// Lecture
int lire(pile P)
{
    if(pileVide(P)==0)
        return P->element;
    else
        exit(EXIT_FAILURE);
}

// Empilement d'une pile
void empiler(int x,pile * P)
{
    pile C=(pile)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=*P;
    *P=C;
}

// Dépilement

int depiler(pile * P)
{
    if(pileVide(*P)==0)
    {
        int res=(*P)->element;
        pile temp=*P;
        *P=(*P)->suivant;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}

// Affichage

void affichage_pile(pile P)
{
    pile temp=P;
    while(temp->suivant!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d\n",temp->element);
}

// Liberation
void liberer(pile P)
{
    while(P!=NULL)
    {
        pile temp=P;
        P=P->suivant;
        free(temp);
    }
}

pile copie_inverse(pile P)
{
    pile temp = P;
    pile COPIE = NULL;
    while(temp !=NULL)
    {
        empiler(temp->element, &COPIE);
        temp = temp->suivant;
    }
    return COPIE;
}

pile copie(pile P)
{
    pile COPIE = NULL;
    pile temp = P;
    unsigned l=0;
    while(temp!=NULL)
    {
        l++;
        temp = temp->suivant;
    }
    temp = P;
    int arr[l];
    for(int i = 0; i<l; i++)
    {
        arr[i] = temp->element;
        temp = temp->suivant;
    }
    for(int i = 0; i<l; i++)
    {
        empiler(arr[l-i-1], &COPIE);
    }
    return COPIE;
}

int parenthese(char * C)
{
    pile P = NULL;
    for(int i = 0; i < strlen(C); i++)
    {
        if(C[i] == '(')
            empiler(1, &P);
        if(C[i] == ')')
        {
            if(pileVide(P) == 1)
                return -1;
            else
                depiler(&P);
        }
    }
    if(pileVide(P) == 1)
        return 0;
    else
        return -1;
}

int main()
{
    pile P = NULL;
    empiler(1, &P);
    empiler(2, &P);
    empiler(3, &P);
    empiler(4, &P);
    empiler(5, &P);
    affichage_pile(P);
    pile R = copie(P);
    affichage_pile(R);
    return 0;
}
