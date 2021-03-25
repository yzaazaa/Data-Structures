#include <stdio.h>
#include <stdlib.h>

typedef struct pile
{
	unsigned taille;
	unsigned taillePile;
	int * tete;
} pile;

pile pileVide(pile P, int taille)
{
	P.tete = (int *)malloc(taille * sizeof(int));
	P.taillePile = 0;
	P.taille = taille;
	return P;
}

int estVide(pile P)
{
	if(P.taillePile == 0)
		return 1;
	return 0;
}

void lire(pile P)
{
	if(estVide(P) == 1)
	{
		printf("La pile est vide.\n");
		return ;
	}
	else
		printf("L'élément au sommet de la pile est: %d.\n", P.tete[P.taillePile - 1]);
}

void empiler(int element, pile * P)
{
	(*P).tete[(*P).taillePile] = element;
	(*P).taillePile++;
}

int depiler(pile * P)
{
	int tete = (*P).tete[0];
	(*P).taillePile--;
	return tete;
}

void affichagePile(pile P)
{
	printf("[");
	for(int i = 0; i<P.taillePile-1; i++)
	{
		printf("%d, ", P.tete[i]);
	}
	printf("%d]\n", P.tete[P.taillePile-1]);
}

int main()
{
	pile P = pileVide(P, 4);
	empiler(1, &P);
	empiler(2, &P);
	empiler(3, &P);
	empiler(4, &P);
	affichagePile(P);
	lire(P);
	depiler(&P);
	affichagePile(P);
	return 0;
}
