#include <stdio.h>
#include <stdlib.h>

typedef struct patient
{
	char nom[15];
	char prenom[15];
	int rdv;
} patient;

typedef struct cellule
{
	patient patient;
	struct cellule * suivant;
} cellule;

typedef struct cellule * liste;

void ajoutPatient(patient P, liste * L)
{
	liste temp = *L;
	cellule * C = (cellule *)malloc(sizeof(cellule));
	C->patient = P;
	if(*L == NULL)
	{
		*L = C;
		C->suivant = NULL;
		return ;
	}
	if(P.rdv == 1)
	{
		if(temp->patient.rdv == 0)
		{
			C->suivant = *L;
			*L = C;
			return ;
		}
		while(temp->suivant != NULL && temp->suivant->patient.rdv != 0)
		{
			temp = temp->suivant;
		}
		C->suivant = temp->suivant;
		temp->suivant = C;
		return ;
	}
	if(P.rdv == 0)
	{
		while(temp->suivant != NULL)
		{
			temp = temp->suivant;
		}
		C->suivant = NULL;
		temp->suivant = C;
		return ;
	}
}

void extrairePatient(liste * L)
{
	liste temp = *L;
	*L = (*L)->suivant;
	free(temp);
	return ;
}

void affichageListe(liste L)
{
	liste temp = L;
	if(L==NULL)
	{
		printf("Liste vide.\n");
		return ;
	}
	while(temp != NULL)
	{
		printf("(%s %s, %d)\n", temp->patient.nom, temp->patient.prenom, temp->patient.rdv);
		temp = temp->suivant;
	}
	return ;
}

void saisie(patient * P)
{
	printf("Veuillez saisir le nom, le prenom, \'1\' si la personne a un rendez-vous, et \'0\' s'il n'en a pas.\n");
	scanf("%s%s%d", P->nom, P->prenom, &P->rdv);
}

int main()
{
	patient A;
	patient B;
	patient C;
	saisie(&A);
	saisie(&B);
	saisie(&C);
	liste L = NULL;
	ajoutPatient(A, &L);
	ajoutPatient(B, &L);
	ajoutPatient(C, &L);
	affichageListe(L);
	printf("\n\n");
	extrairePatient(&L);
	affichageListe(L);
	printf("\n\n");
	extrairePatient(&L);
	extrairePatient(&L);
	printf("\n\n");
	affichageListe(L);
	return 0;
}
