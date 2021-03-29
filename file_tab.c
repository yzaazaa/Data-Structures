#include<stdio.h>
#include<stdlib.h>

typedef struct file
{
	int taille;
	int tailleFile;
	int * tete;
	unsigned l;
} file;

file fileVide(file F, int taille)
{
	F.taille = taille;
	F.tailleFile = 0;
	F.l = 0;
	F.tete = (int *)malloc(taille * sizeof(int));
	return F;
}

int estVide(file F)
{
	if(F.tailleFile == 0)
		return 1;
	return 0;
}

void lire(file F)
{
	if(estVide(F) == 1)
	{
		printf("La file est vide.\n");
		return ;
	}
	printf("L'élément au début de la file est: %d.\n", F.tete[0]);
}

void enfiler(file * F, int element)
{
	(*F).tete[(*F).tailleFile] = element;
	(*F).tailleFile++;
}

int defiler(file * F)
{
	(*F).l++;
	int debut = (*F).tete[0];
	(*F).tailleFile--;
	return debut;
}

void affichageFile(file F)
{
	printf("[");
	for(int i = F.l; i<F.tailleFile; i++)
	{
		printf("%d, ", F.tete[i]);
	}
	printf("\n");
}

int main()
{
	file F = fileVide(F, 4);
	enfiler(&F, 0);
	enfiler(&F, 1);
	enfiler(&F, 2);
	enfiler(&F, 3);
	lire(F);
	affichageFile(F);
	defiler(&F);
	affichageFile(F);
	return 0;
}
