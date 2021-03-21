//
//  file.c
//
//
//

#include<stdio.h>
#include<stdlib.h>

struct cellule_double
{
    int element;
    struct cellule_double * suivant;
    struct cellule_double * precedent;
};
typedef struct cellule_double cellule_double;

struct file
{
    cellule_double * debut;
    cellule_double * fin;
};
typedef struct file file;

// Prototypes
int fileVide(file);
int lire(file);
void enfiler(int,file *);
int defiler(file *);
void liberer(file);
void affichage_file(file);

// Test à vide d'une file
int fileVide(file F)
{
    if(F.debut==NULL)
        return 1;
    else
        return 0;
}

// Lecture du début d'une file
int lire(file F)
{
    if(fileVide(F)==0)
        return F.debut->element;
    else
        exit(EXIT_FAILURE);
}

// Enfilage d'un element dans une file

void enfiler(int x,file * F)
{
    cellule_double * C=(cellule_double *)malloc(sizeof(cellule_double));
    C->element=x;
    C->suivant=NULL;
    if(fileVide(*F)==1)
    {
        C->precedent=NULL;
        (*F).debut=C;
        (*F).fin=C;
    }
    else
    {
        C->precedent=(*F).fin;
        (*F).fin->suivant=C;
        (*F).fin=C;
    }
}

// Défilage d'une file

int defiler(file * F)
{
    if(fileVide(*F)==0)
    {
        int res=F->debut->element;
        cellule_double * temp=F->debut;
        (*F).debut=F->debut->suivant;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}

// Destruction d'une file
// Liberation
void liberer(file F)
{
    while(F.debut!=NULL)
    {
        cellule_double * temp=F.debut;
        F.debut=F.debut->suivant;
        free(temp);
    }
    if(F.fin!=NULL)
        free(F.fin);
}

// Affichage d'une file
void affichage_file(file F)
{
    /* Si la file est vide */
    if(fileVide(F)==1)
    {
        printf("[]\n");
        // On sort de la fonction
        return;
    }
    /* On continue si la file st non vide */
    cellule_double *temp=F.debut;
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

file copie(file F)
{
    file COPIE=(file){NULL, NULL};
    file temp = F;
    while(temp.debut!=NULL)
    {
        enfiler(temp.debut->element, &COPIE);
        temp.debut = temp.debut->suivant;
    }
    return COPIE;
}

int main()
{
    file F={NULL,NULL};
    enfiler(1,&F);
    enfiler(2,&F);
    enfiler(3,&F);
    enfiler(6,&F);
    affichage_file(F);
    file R = copie(F);
    affichage_file(R);
    return 0;
}
