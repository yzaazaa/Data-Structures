//
//  listeDouble.c
//
//
//  Created by El Kahoui on 11/03/2021.
//

//#include "listeDouble.h"
#include<stdio.h>
#include<stdlib.h>

// Defintion d'une cellule double
struct celluleDouble
{
    int element;
    struct celluleDouble * suivant;
    struct celluleDouble * precedent;
};
typedef struct celluleDouble celluleDouble;
// Fin de la definition d'une cellule double

// Defintion d'une liste doublement chainee
struct listeDouble
{
    celluleDouble * debut;
    celluleDouble * fin;
    unsigned longueur;
};
typedef struct listeDouble listeDouble;
// Fin de la definition d'une liste double

// Prototypes
int listeDoubleVide(listeDouble);
void affichageListeDouble(listeDouble);
void ajoutDebut(int, listeDouble *);
void ajoutFin(int,listeDouble *);
void suppressionDebut(listeDouble *);
void suppressionFin(listeDouble *);
void libererListeDouble(listeDouble);

/************************ Implementation des fonctions ***********************/

// La fonction test_vide_listeDouble

int listeDoubleVide(listeDouble L)
{
    if(L.debut==NULL)
        return 1;
    return 0;
}

// La fonction affichage

void affichageListeDouble(listeDouble L)
{
    /* Si la liste est vide */
    if(listeDoubleVide(L)==1)
    {
        printf("[]\n");
        // On sort de la fonction
        return;
    }
    /* On continue si la liste st non vide */
    celluleDouble *temp=L.debut;
    printf("[");
    while(temp->suivant!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d",temp->element);
    printf("]\n");
}


// La fonction ajourDebut()

void ajoutDebut(int x,listeDouble * L)
{
    /* Declaration et initialisation de la cellue a ajouter */
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->suivant=L->debut;
    C->precedent=NULL;
    /* Fin initialisation de la cellule double */

    /* Cas ou la liste L est vide */
    if(listeDoubleVide(*L)==1)
    {
        L->debut=C;
        L->fin=C;
        L->longueur=1;
        return;
    }
    /* Si la liste L n'est pas vide */
    L->debut->precedent=C;
    L->debut=C;
    L->longueur+=1;
    return;
}

// La fonction ajourFin()

void ajoutFin(int x,listeDouble *L)
{
    /** Declaration et initialisation de la cellue a ajouter **/
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->precedent=L->fin;
    C->suivant=NULL;
    /** Fin initialisation de la cellule double **/

    /* Si la liste L est vide on ajoute au debut */
    if(listeDoubleVide(*L)==1)
    {
        ajoutDebut(x,L);
        return;
    }
    /* Si la liste n'est pas vide */
    L->fin->suivant=C;
    L->fin=C;
    L->longueur+=1;
    return;
}

// La fonction suppressionDebut()
void suppressionDebut(listeDouble * L)
{
    /* Cas d'une liste vide */
    if(listeDoubleVide(*L)==1)
        return;
    /* Cas d'une liste a un seul element */
    if(L->longueur==1)
    {
        L->longueur=0;
        if(L->debut!=NULL)
            free(L->debut);
        L->debut=NULL;
        return;
    }
    /* declaration d'un pointeur temporaire vers la premiere celluleDouble */
    celluleDouble * temp=L->debut;
    /* Deplacement du debut de la liste vers la celluleDouble suivante */
    L->debut=L->debut->suivant;
    L->longueur-=1;
    /* Liberation de la premiere celluleDouble*/
    free(temp);
    return;
}

// La fonction suppressionFin()

void suppressionFin(listeDouble * L)
{
    if(listeDoubleVide(*L)==1)
        return;
    /* Cas d'une liste a un seul element */
    if(L->longueur==1)
    {
        suppressionDebut(L);
        return;
    }
    /* declaration d'un pointeur temporaire vers la derniere celluleDouble */
    celluleDouble * temp=L->fin;
    /* Deplacement de la fin de la liste vers la celluleDouble precedente */
    L->fin=L->fin->precedent;
    L->fin->suivant=NULL;
    L->longueur-=1;
    free(temp);
    return;
}

// La fonction librer

void libererListeDouble(listeDouble L)
{
    while(L.debut!=NULL)
    {
        celluleDouble * temp=L.debut;
        L.debut=L.debut->suivant;
        free(temp);
    }
}

/* Exercice 5, question 2.*/

/* Ecrire ici la fonction de concatenation. */
listeDouble concatener(listeDouble L1, listeDouble L2)
{
    listeDouble temp1 = L1;
    listeDouble temp2 = L2;
    listeDouble L =  {NULL, NULL, 0};
    while(temp1.debut != NULL)
    {
        ajoutFin(temp1.debut->element, &L);
        temp1.debut = temp1.debut->suivant;
    }
    while(temp2.debut != NULL)
    {
        ajoutFin(temp2.debut->element, &L);
        temp2.debut = temp2.debut->suivant;
    }
    return L;
}


/** La fonction principale main() **/

int main()
{
    listeDouble L={NULL,NULL,0};
    ajoutDebut(1,&L);
    affichageListeDouble(L);
    //printf("%u\n",L.longueur);
    ajoutDebut(2,&L);
    affichageListeDouble(L);
    ajoutFin(3,&L);
    affichageListeDouble(L);
    ajoutDebut(1,&L);
    affichageListeDouble(L);
    ajoutDebut(2,&L);
    affichageListeDouble(L);
    ajoutFin(3,&L);
    affichageListeDouble(L);
    suppressionDebut(&L);
    affichageListeDouble(L);
    suppressionFin(&L);
    affichageListeDouble(L);
    //printf("\n\n");
    listeDouble K = {NULL, NULL,0};
    ajoutFin(1,&K);
    ajoutFin(2,&K);
    ajoutFin(3,&K);
    ajoutFin(4,&K);
    ajoutFin(5,&K);
    ajoutFin(6,&K);
    affichageListeDouble(K);
    listeDouble R = concatener(L, K);
    affichageListeDouble(R);
    libererListeDouble(L);
}
