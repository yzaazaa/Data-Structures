//
//  arbre.c
//
//
//  Created by El Kahoui on 17/04/2021.
//

#include <stdio.h>
#include<stdlib.h>

struct noeud
{
    int cle;
    struct noeud * gauche;
    struct noeud * droit;
};
typedef struct noeud noeud;
typedef struct noeud * arbre;

// Prototypes
arbre arbreVide(); /*Construit un arbre vide*/
int testVide(arbre); /*Teste si un arbre est vide*/
int racine(arbre); /*Extrait la racine de l'arbre*/
arbre gauche(arbre);/*Extrait le sous-arbre gauche*/
arbre droit(arbre); /*Extrait le sous-arbre droit*/
arbre faireArbre(int, arbre,arbre); /* construit un arbre a partir d'une racine et de deux arbres */
void fixerCle(int, arbre *); /*Modifie la racine d'un arbre*/
void fixerGauche(arbre, arbre *); /*Modifie le sous-arbre gauche */
void fixerDroit(arbre, arbre *); /* Modifie le sous-arbre droit*/
void libererArbre(arbre *); /* libere la zone memoire*/

// Implementations
// Arbre vide
arbre arbreVide()
{
    arbre T=NULL;
    return T;
}

// Test à vide d'un arbre
int estVide(arbre T)
{
    if(T==NULL)
        return 1;
    return 0;
}

// Racine
 int racine(arbre T)
{
    if(estVide(T))
       exit(EXIT_FAILURE);
    return T->cle;
}

// Sous-arbre gauche
arbre gauche(arbre T)
{
    if(estVide(T))
        return NULL;
    return T->gauche;
}

// Sous-arbre droit
arbre droit(arbre T)
{
    if(estVide(T))
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
    if(estVide(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->cle=x;
    }
}

// fixerGauche
void fixerGauche(arbre G, arbre * P)
{
    if(estVide(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->gauche=G;
        //return *P;
    }
}

// fixerDroit
void fixerDroit(arbre D, arbre * P)
{
    if(estVide(*P))
        exit(EXIT_FAILURE);
    else
    {
        (*P)->droit=D;
        //return *P;
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

//EX1
    // Question 1
int minimum(int x, int y)
{
    if(x < y)
        return x;
    else
        return y;
}

int min(arbre T)
{
    if(T==NULL)
        exit (EXIT_FAILURE);
    if(T->gauche == NULL && T->droit == NULL)
        return racine(T);
    if(T->gauche != NULL && T->droit != NULL)
        return minimum(T->cle, minimum(min(T->gauche), min(T->droit)));
    if(T->gauche == NULL)
        return minimum(T->cle, min(T->droit));
    if(T->droit == NULL)
        return minimum(T->cle, min(T->gauche));
}

int maximum(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int max(arbre T)
{
    if(T==NULL)
        exit (EXIT_FAILURE);
    if(T->gauche == NULL && T->droit == NULL)
        return racine(T);
    if(T->gauche != NULL && T->droit != NULL)
        return maximum(T->cle, maximum(max(T->gauche), max(T->droit)));
    if(T->gauche == NULL)
        return maximum(T->cle, max(T->droit));
    if(T->droit == NULL)
        return maximum(T->cle, max(T->gauche));
}

    // Question 2
int somme(arbre T)
{
    int sum = 0;
    int sumgauche =0;
    int sumdroit = 0;
    if(T==NULL)
        return 0;
    if(T->gauche !=NULL)
    {
        sumgauche = somme(T->gauche);
    }
    if(T->droit!=NULL)
    {
        sumdroit = somme(T->droit);
    }
    sum = T->cle + sumgauche + sumdroit;
    return sum;
}

//Ex 2
    // Question 1
int taille(arbre T)
{
    if(T == NULL)
        return 0;
    return 1 + taille(T->gauche) + taille(T->droit);
}
    // Question 2
int noeudsInternes(arbre T)
{
    if(T == NULL)
        return 0;
    if(T->gauche == NULL && T->droit == NULL)
        return noeudsInternes(T->gauche) + noeudsInternes(T->droit);
    return 1 + noeudsInternes(T->gauche) + noeudsInternes(T->droit);
}
    //Question 3
int feuilles(arbre T)
{
    return taille(T) - noeudsInternes(T);
}

// Ex 3
int strahler(arbre T)
{
    if(T==NULL)
        return 0;
    if(strahler(T->droit) == strahler(T->gauche))
        return strahler(T->droit) + 1;
    else
        return maximum(strahler(T->droit), strahler(T->gauche));
}

//Ex 4
    // Question 1
int abr(arbre T)
{
    if(T == NULL)
        return 1;
    if(T->gauche != NULL && T->gauche->cle > T->cle)
        return 0;
    if(T->droit != NULL && T->droit->cle < T->cle)
        return 0;
    if(!abr(T->gauche)  || !abr(T->droit))
        return 0;
    return 1;
}
    // Question 2
int recherche(int x, arbre T) {
    arbre temp = T;
    while(temp != NULL) {
        if(x < temp->cle) 
            temp = temp->gauche;
        if(x > temp->cle)
            temp = temp->droit;
        if(x == temp->cle)
            return 1;
    }
    return 0;
}
    // Question 3
int min_ABR(arbre T) {
    arbre temp = T;
    arbre temp2 = NULL;
    while(temp != NULL) {
        temp2 = temp;
        temp = temp->gauche;
    }
    return temp2->cle;
}

int max_ABR(arbre T) {
    arbre temp = T;
    arbre temp2 = NULL;
    while(temp != NULL) {
        temp2 = temp;
        temp = temp->droit;
    }
    return temp2->cle;
}


int main()
{
    arbre T1=NULL;
    arbre T2=NULL;
    T1=faireArbre(1,NULL,NULL);
    T2=faireArbre(2,NULL,NULL);
    arbre T=faireArbre(3,T1,T2);
    printf("\nAffichage : racine, fils gauche, fils droit.\n");
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    printf("\nModification du contenu de la racine.\n");
    fixerCle(5,&T);
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    printf("\nModification du sous-arbre gauche.\n");
    fixerGauche(T2,&T);
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    printf("\nModification du sous-arbre droit.\n");
    fixerDroit(T1,&T);
    printf("%d %d %d\n",T->cle,T->gauche->cle,T->droit->cle);
    arbre S=faireArbre(10,T,T1);
    printf("%d %d %d %d %d\n",S->cle,S->gauche->cle,S->gauche->gauche->cle,S->gauche->droit->cle, S->droit->cle);
    printf("Minimum: \n%d\n%d\n", min(T), min(S));
    printf("Maximum: \n%d\n%d\n", max(T), max(S));
    printf("Somme: \n%d\n%d\n", somme(T), somme(S));
    printf("Taille: \n%d\n%d\n", taille(T), taille(S));
    printf("NoeudsInternes: \n%d\n%d\n", noeudsInternes(T), noeudsInternes(S));
    printf("Feuilles: \n%d\n%d\n", feuilles(T), feuilles(S));
    printf("Strahler: \n%d\n%d\n", strahler(T), strahler(S));
    printf("ABR: \n%d\n%d\n", abr(T), abr(S));
    libererArbre(&T);
    return 0;
}
