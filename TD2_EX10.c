#include <stdlib.h>
#include<stdio.h>

typedef struct cellule
{
	int numero;
	int nombre;
	struct cellule *suivant;
} cellule;

typedef struct file
{
	cellule * debut;
	cellule * fin;
} file;

void ajout(int numero, file * F)
{
	file temp = *F;
	cellule * C = (cellule *)malloc(sizeof(cellule));
	C->nombre = 0;
	C->numero = numero;
	C->suivant = NULL;
	if((*F).debut==NULL)
	{
		(*F).debut = C;
		(*F).fin = C;
		return ;
	}
	while(temp.debut != NULL)
	{
		if(temp.debut->numero == numero)
		{
			temp.debut->nombre ++;
			return ;
		}
		temp.debut = temp.debut->suivant;
	}
	(*F).fin->suivant = C;
	(*F).fin = C;
}

void retirer(file * F)
{
	cellule * temp = (*F).debut;
	(*F).debut = (*F).debut->suivant;
	free(temp);
}

void affichage(file F)
{
	file temp = F;
	if(F.debut == NULL)
	{
		printf("[]\n");
		return ;
	}
	printf("[");
	while(temp.debut->suivant != NULL)
	{
		printf("(%d , %d) ,", temp.debut->numero, temp.debut->nombre);
		temp.debut = temp.debut->suivant;
	}
	printf("(%d , %d)]\n", temp.debut->numero, temp.debut->nombre);
}

int main()
{
	file F = {NULL, NULL};
	ajout(0, &F);
	ajout(1, &F);
	ajout(2, &F);
 	ajout(1, &F);
	ajout(0, &F);
	ajout(0, &F);
	affichage(F);
	retirer(&F);
	affichage(F);
	retirer(&F);
	affichage(F);
	retirer(&F);
	affichage(F);
	return 0;
}
