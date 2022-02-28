//
//  parcours.c
//
//
//  Created by El Kahoui on 14/01/2021.
//

#include "abrAvl.h"

/* Implemnatation de liste */

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
        printf("[ ]\n");
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
    if(L!=NULL)
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
    if(L==NULL)
    {
        return;
    }
    if((*L)->suivant==NULL)
    {
        free(*L);
        *L=NULL;
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

/* Implementation de l'arbre*/
// Arbre vide
arbre arbreVide()
{
    arbre T=NULL;
    return T;
}

// Test à vide d'un arbre
int estVideArbre(arbre T)
{
    if(T==NULL)
        return 1;
    return 0;
}

// Racine
 int racine(arbre T)
{
    if(estVideArbre(T))
       exit(EXIT_FAILURE);
    return T->cle;
}


// Sous-arbre gauche
arbre gauche(arbre T)
{
    if(estVideArbre(T))
        return NULL;
    return T->gauche;
}

// Sous-arbre droit
arbre droit(arbre T)
{
    if(estVideArbre(T))
        return NULL;
    return T->droit;
}

// faireArbre

arbre faireArbre(int x,arbre T_1,arbre T_2)
{
    arbre T=(arbre)malloc(sizeof(noeud));
    T->cle=x;
    T->gauche=T_1;
    T->droit=T_2;
    return T;
}

// fixerCle
void fixerCle(int x,arbre * P)
{
    if(estVideArbre(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->cle=x;
        //return *P;
    }
}

// fixerGauche
void fixerGauche(arbre G, arbre * P)
{
    if(estVideArbre(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->gauche=G;
        return;
    }
}

// fixerDroit
void fixerDroit(arbre D, arbre * P)
{
    if(estVideArbre(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->droit=D;
        return;
    }
}

// Liberer
void libererArbre(arbre *T)
{
    arbre temp=*T;
    if(temp==NULL)
        return;
    if(temp->gauche!=NULL)
        libererArbre(&temp->gauche);
    if(temp->droit!=NULL)
        libererArbre(&temp->droit);
    free(temp);
    *T=NULL;
}
=

/* Implementation de la file d'arbres*/

int estVideFile(file_arbre F)
{
    if(F.longueur==0)
        return 1;
    return 0;
}

void enfiler(arbre T, file_arbre * F)
{
    if(F->longueur==N)
    {
        printf("File pleine !\n");
        return;
    }
    F->tete[F->longueur]=T;
    F->longueur+=1;
    return;
}

arbre defiler(file_arbre * F)
{
    if(estVideFile(*F))
    {
        return NULL;
    }
    arbre T=F->tete[0];
    int i;
    for(i=1;i<F->longueur;i++)
        F->tete[i-1]=F->tete[i];
    F->longueur-=1;
    return T;
}


/* Implementation de la pile d'arbres*/

int estVidePile(pile_arbre P)
{
    if (P.longueur ==0)
        return 1;
    return 0;
}

void empiler(arbre T,pile_arbre * P)
{
    if(P->longueur==N)
    {
        printf("Pile vide.\n");
        return;
    }
    P->tete[P->longueur]=T;
    P->longueur+=1;
}

arbre depiler(pile_arbre * P)
{
    if(estVidePile(*P))
        return NULL;
    arbre T=P->tete[P->longueur-1];
    P->longueur-=1;
    return T;
}

/* Implementation du tableau */
tableau  creer(unsigned n)
{
    tableau T;
    T.taille=n;
    T.tete=(int *)malloc(n*sizeof(int));
    return(T);
}

//La procédure affichage

void affichageTableau(tableau T)
{

    if(T.tete==NULL)
    printf("[]");
    else
    {
        unsigned n=T.taille;
        printf("[");
        for(int i=0;i<n-1;i++)
            printf("%d,",T.tete[i]);
        printf("%d]",T.tete[n-1]);
    }
    printf("\n");
    return;
}

//La procédure saisie
void saisieTableau(tableau T)
{
    if(T.tete==NULL)
        printf("Tableau vide !\n");
    else
    {
        for(int i=0;i<T.taille;i++)
            scanf("%d",T.tete+i);
    }
    return;
}

//La procédure liberer
void libererTableau(tableau T)
{
    if(T.tete!=NULL)
        free(T.tete);
    return;
}


                        /****** Parcours ****/

// Affichage avec parcours en largeur

void affichageLargeur(arbre T)
{
    if(T==NULL)
        return;
    file_arbre F={NULL,0};
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        printf("%d",temp->cle);
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    printf("\n");
}

void affichagePrefixe(arbre T)
{
    if(T==NULL)
        return;
    pile_arbre P={NULL,0};
    arbre temp=T;
    empiler(T,&P);
    while(estVidePile(P)==0)
    {
        temp=depiler(&P);
        printf("%d\t",temp->cle);
        if(temp->droit!=NULL)
            empiler(temp->droit,&P);
        if(temp->gauche!=NULL)
            empiler(temp->gauche,&P);
    }
    return;
}

unsigned tailleLargeur(arbre T)
{
    if(T==NULL)
        return 0;
    unsigned n=0;
    file_arbre F={NULL,0};
    arbre temp=T;
    enfiler(T,&F);
    while(estVideFile(F)==0)
    {
        temp=defiler(&F);
        n+=1;
        if(temp->gauche!=NULL)
            enfiler(temp->gauche,&F);
        if(temp->droit!=NULL)
            enfiler(temp->droit, &F);
    }
    return n;
}

tableau arbreTableauInfixe(arbre T)
{
    if(T==NULL)
    {
        tableau T={0,NULL};
        return T;
    }
    unsigned n=tailleLargeur(T);
    tableau L=creer(n);
    unsigned i=0;
    pile_arbre P={NULL,0};
    arbre temp=T;
    while(estVidePile(P)==0 || temp!=NULL)
    {
        if(temp!=NULL)
        {
            empiler(temp,&P);
            temp=temp->gauche;
        }
        else
        {
            temp=depiler(&P);
            L.tete[i]=temp->cle;
            i+=1;
            temp=temp->droit;
        }
    }
    return L;
}

int testAbrInfixe(arbre T)
{
    if(T==NULL)
        return 1;
    tableau L=arbreTableauInfixe(T);
    for(int i=0;i<L.taille-1;i++)
    {
        if(L.tete[i+1]<=L.tete[i])
            return 0;
    }
    return 1;
}

/* Calcul de la hauteur d'un arbre : Version très naïve */

int maximum(int x, int y)
{
    if(x>y)
        return x;
    return y;
}
int hauteur(arbre T)
{
    if(T==NULL)
        return -1;
    return 1+maximum(hauteur(gauche(T)),hauteur(droit(T)));
}

/* Insertion dans un arbre binaire de recherche */

void insererAbrRecursive(int val,arbre * T)
{
    if(*T==NULL)
    {
        *T=faireArbre(val,NULL,NULL);
        return;
    }
    if(val==(*T)->cle)
        return;
    if(val<(*T)->cle)
    {
        insererAbrRecursive(val,&(*T)->gauche);
    }
    if(val>(*T)->cle)
    {
        insererAbrRecursive(val,&(*T)->droit);
    }
}

/* Rotation gauche */

void rotationGauche(arbre *T)
{
    if(*T==NULL||(*T)->droit==NULL)
        return;
    arbre temp=(*T)->droit;
    (*T)->droit=temp->gauche;
    temp->gauche=*T;
    *T=temp;
    return;
}

void rotationDroite(arbre *T)
{
    if(*T==NULL||(*T)->gauche==NULL)
        return;
    arbre temp=(*T)->gauche;
    (*T)->gauche=temp->droit;
    temp->droit=*T;
    *T=temp;
    return;
}

void insererAvl(int val,arbre * T)
{
    insererAbrRecursive(val,T);
    if(hauteur(gauche(*T)) - hauteur(droit(*T))==-2)
    {
        if(hauteur(droit(droit(*T))) < hauteur(gauche(droit(*T))))
        {
            rotationDroite(&(*T)->droit);
            rotationGauche(T);
            return ;
        }
        else
        {
            rotationGauche(T);
            return;
        }
    }
    if(hauteur(gauche(*T)) - hauteur(droit(*T))==2)
    {
        if(hauteur(gauche(gauche(*T))) < hauteur(droit(gauche(*T))))
        {
            rotationGauche(&(*T)->gauche);
            rotationDroite(T);
            return ;
        }
        else
        {
            rotationDroite(T);
            return;
        }
    }
    return;
}

int testAVL(arbre T)
{
    if(T==NULL)
        return 1;
    if(abs(hauteur(T->gauche)-hauteur(T->droit))>1)
        return 0;
    return testAVL(T->gauche) && testAVL(T->droit);
}

int testAbrAvl(arbre T)
{
    if(testAVL(T) == 1 || testAbrInfixe(T) == 1)
        return 1;
    return 0;
}

arbre successeur(arbre T, int x)
{
    if(T = NULL)
        return NULL;
    pile_arbre P = {NULL, 0};
    arbre temp = T;
    while(estVidePile(P) == 0 || temp != NULL)
    {
        if(temp != NULL)
        {
            empiler(temp, &P);
            temp = gauche(temp);
        }
        else
        {
            temp = depiler(&P);
            if(temp->cle > x)
                return temp;
            temp = temp->droit;
        }
    }
    return NULL;
}

liste codePositionnel(arbre T, int x)
{
    if(estVideArbre(T) == 1)
        return NULL;
    liste T = NULL;
    arbre temp = T;
    while(estVideArbre(temp) == 0)
    {
        if(temp->cle = x)
            return L;
        if(temp->cle > x)
        {
            ajoutFin(1, L);
            temp = temp->gauche;
        }
        if(temp->cle < x)
        {
            ajoutFin(0, L);
            temp = temp->droit;
        }
    }
    return NULL;
}

arbre codeInverse(liste L, arbre T)
{
    if(estVideArbre(T) == 1)
        return NULL;
    liste temp = L;
    arbre temp2 = T;
    while(temp != NULL)
    {
        if(temp->element == 0)
        {
            temp = temp->suivant;
            temp2 = temp->gauche;
        }
        if(temp->element == 1)
        {
            temp = temp->suivant;
            temp2 = temp->droit;
        }
    }
    return temp2;
}

arbre abrTableau(tableau L)
{
    arbre T = NULL;
    for(int i = 0; i<L.taille; i++)
    {
        insererAbrRecursive(L.tete[i], &T);
    }
    return T;
}

tableau triAbr(tableau L)
{
    arbre T = abrTableau(L);
    tableau S = arbreTableauInfixe(T);
    libererArbre(&T);
    return S;
}


int main()
{
    arbre T=NULL;
    insererAvl(1,&T);
    printf("%d\n\n",testAVL(T));
    insererAvl(2,&T);
    printf("%d\n\n",testAVL(T));
    insererAvl(3,&T);
    printf("%d\n\n",testAVL(T));
    insererAvl(4,&T);
    //rotationGauche(&T);
    //insererAvl(0,&T);
    insererAvl(5,&T);
    printf("%d\n\n",testAVL(T));
    insererAvl(6,&T);
    tableau L=arbreTableauInfixe(T);
    affichageTableau(L);
    affichageLargeur(T);
    libererArbre(&T);
    libererTableau(L);
    return 0;
}
