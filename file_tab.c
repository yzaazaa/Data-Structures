#include<stdio.h>
#include<stdlib.h>

typedef struct file
{
	int taille;
	int tailleFile;
	int * tete;
} file;

file fileVide(size_t taille)
{
	file F;
	F.taille = taille;
	F.tailleFile = 0;
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
	if((*F).tailleFile < (*F).taille)
	{
		(*F).tete[(*F).tailleFile] = element;
		(*F).tailleFile++;
		return ;
	}
	printf("La file est pleine.\n");
}

int defiler(file * F)
{
	int debut = (*F).tete[0];
	F->tailleFile--;
	for(int i = 1; i<F->taille; i++)
		(*F).tete[i-1] = (*F).tete[i];
	return debut;
}

void affichageFile(file F)
{
	printf("[");
	int i = 0;
	while(i < F.tailleFile-1)
	{
		printf("%d, ", F.tete[i]);
		i++;
	}
	printf("%d]", F.tete[i]);
	printf("\n");
}

int main()
{
	file F = fileVide(4);
	enfiler(&F, 0);
	enfiler(&F, 1);
	enfiler(&F, 2);
	enfiler(&F, 3);
	lire(F);
	affichageFile(F);
	enfiler(&F, 4);
	defiler(&F);
	defiler(&F);
	affichageFile(F);
	return 0;
}
