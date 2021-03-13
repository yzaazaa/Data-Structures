//
//  liste_simple.c
//
//
//  Created by El Kahoui on 28/02/2021.
//
#include<stdio.h>
#include<stdlib.h>
//#include "liste_simple.h"

struct cellule
{
    int element;
    struct cellule * suivant;

};
typedef struct cellule cellule;
typedef struct cellule * liste;

///////// Prototypes ///////////////////
int testVide(liste);
unsigned longueur(liste);
void affichageListe(liste);
void ajoutDebut(int,liste *);
void ajoutFin(int,liste *);
void suppressionDebut(liste *);
void suppressionFin(liste *);
void liberer(liste);
liste recherche(int, liste);
unsigned occurence(int,liste);
unsigned length(liste);
void supression(liste*, unsigned);
/////////////////////////////////////////

// Test d'une liste vide.
int testVide(liste L)
{
    if(L==NULL)
        return 1;
    return 0;
}

// Longueur d'une liste.
unsigned longueur(liste L)
{
    unsigned l=0;
    if(testVide(L)==0)
    {
        liste temp=L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
    return l;
}

// Affichange d'une liste
void affichageListe(liste L)
{
    if(L==NULL)
        printf("[ ]");
    else
    {
        printf("[");
        liste temp=L;
        while(temp->suivant!=NULL)
        {
            printf("%d, ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%d",temp->element);
        printf("]\n");
    }
}

// Ajout au début d'une liste.
void ajoutDebut(int x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    cellule * C=(cellule *)malloc(sizeof(cellule));
    //Remplissage de la cellule
    C->element=x;
    C->suivant=*L;
    // Ajout de la cellule au début de la liste
    *L=C;
    return;
}

// Ajout à la fin d'une liste
void ajoutFin(int x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    liste C=(liste)malloc(sizeof(cellule));
    //Remplissage de la cellule
    C->element=x;
    C->suivant=NULL;
    // Acces à la fin de la liste L
    if(*L==NULL)
        *L=C;
    else
    {
        liste temp=*L;
        while(temp->suivant!=NULL)
            temp=temp->suivant;
        temp->suivant=C;
    }
    return;
}

// Suppression du début d'une liste.
void suppressionDebut(liste * L)
{
    if(*L!=NULL)
    {
        liste temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}

// Suppresion de la fin d'une liste.
void suppressionFin(liste * L)
{
    if(* L==NULL)
    {
        return;
    }
    if((*L)->suivant==NULL)
    {
        free(*L);
    }
    else
    {
        // Acces à la dernière et à la l'avant dernière cellules
        liste temp=*L;
        liste temp_1=*L;
        while(temp->suivant!=NULL)
        {
            temp_1=temp;
            temp=temp->suivant;
        }
        temp_1->suivant=NULL;
        free(temp);
    }
    return;
}

// destruction d'une liste
void liberer(liste L)
{
    while(L!=NULL)
    {
        liste temp=L;
        L=L->suivant;
        free(temp);
    }
}

liste recherche(int x, liste L)
{
    liste temp = L;
    while(temp != NULL)
    {
              if(temp->element == x)
                 return temp;
        temp = temp->suivant;
    }

    return NULL;
}

unsigned occurence(int x, liste L)
{
    liste temp = L;
    unsigned occ = 0;
    while(temp!= NULL)
    {
        if(temp->element == x)
            occ++;
        temp = temp->suivant;
    }
    return occ;
}

unsigned length(liste L)
{

    liste temp = L;
    liste T = NULL;
    while(temp !=NULL)
    {
        if(recherche(temp->element, T) == NULL)
            ajoutDebut(temp->element, &T);
        temp = temp->suivant;
    }
    unsigned len = longueur(T);
    return len;
}

void supression(liste* L, unsigned i)
{
      if(i >= longueur(*L) || longueur(*L) == 0)
      {
            printf("L'indice entré est superieur à la longueur de la liste");
            return ;
      }
      if(i == longueur(*L) - 1)
      {
            suppressionFin(L);
            return ;
      }
      if(i == 0)
      {
            suppressionDebut(L);
            return ;
      }
      liste temp = *L;
      unsigned j = 0;
      while(j<i-1)
      {
            temp = temp->suivant;
            j++;
      }
      liste temp2 = temp;
      temp = temp->suivant;
      temp2->suivant = temp->suivant;
      free(temp);
      return ;
}

int main()
{
    liste L=NULL;
    ajoutDebut(1,&L);
    ajoutDebut(2,&L);
    ajoutDebut(3,&L);
    ajoutDebut(4,&L);
    ajoutDebut(5,&L);
    ajoutDebut(6,&L);
    ajoutFin(0,&L);
    affichageListe(L);
    printf("Le nombre d'occurences du chiffre 2 est : %u\n", occurence(2, L));
    printf("Length of this list is : %u\n", length(L));
    supression(&L, 6);
    affichageListe(L);
    return 0;

}
