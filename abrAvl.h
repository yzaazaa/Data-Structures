//
//  parcours.h
//
//
//  Created by El Kahoui on 14/01/2021.
//

#ifndef abrAvl_h
#define abrAvl_h

#include <stdio.h>
#include<stdlib.h>

#endif /* avlAbr_h */


/* La liste simplement chainée */
struct cellule
{
    int element;
    struct cellule * suivant;
};
typedef struct cellule cellule;
typedef struct cellule * liste;

/* La structure arbre*/
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
int estVideArbre(arbre); /*Teste si un arbre est vide*/
int racine(arbre); /*Extrait la racine de l'arbre*/
arbre gauche(arbre);/*Extrait le sous-arbre gauche*/
arbre droit(arbre); /*Extrait le sous-arbre droit*/
arbre faireArbre(int, arbre,arbre); /* construit un arbre a partir d'une racine et de deux arbres */
void fixerCle(int, arbre *); /*Modifie la racine d'un arbre*/
void fixerGauche(arbre, arbre *); /*Modifie le sous-arbre gauche */
void fixerDroit(arbre, arbre *); /* Modifie le sous-arbre droit*/
void libererArbre(arbre *); /* libere la zone memoire*/
int hauteur(arbre); /* Calcule la hauteur d'un arbre */

#define N 200
/* La file d'arbres implementée à l'aide d'un tableau*/
struct file_arbre
{
    arbre tete[N];
    unsigned longueur;
};
typedef struct file_arbre file_arbre;

// Prototypes
int estVideFile(file_arbre);
void enfiler(arbre, file_arbre *);
arbre defiler(file_arbre *);

/* La pile d'arbres implementée à l'aide d'un tableau*/
struct pile_arbre
{
    arbre tete[N];
    unsigned longueur;
};
typedef struct pile_arbre pile_arbre;

// Prototypes
int estVidePile(pile_arbre);
void empiler(arbre,pile_arbre *);
arbre depiler(pile_arbre *);

/* Le tableau dynamique */
struct tableau
{
    unsigned taille;
    int *tete;
};
typedef struct tableau tableau;

                        /* Interface Prototypes */
tableau creer(unsigned);
void affichageTableau(tableau);
void saisieTableau(tableau);
void libererTableau(tableau);
