#include<stdio.h>
#include<stdlib.h>

/* Structure de données : Tableau */

struct tableau
{
	unsigned taille;
	double *tete;
};
typedef struct tableau tableau;

/* Prototype de fonctions */
tableau creer(unsigned);
void affichageTableau(tableau);
void saisie(tableau);
tableau concatener(tableau, tableau);
tableau removee(tableau,int);
tableau add(tableau, int);
void liberer(tableau);
tableau affectation(tableau, tableau);
void triInsertion(tableau);
tableau triBulles(tableau);


/* Fonctions */

tableau creer(unsigned n)
{
	tableau T ;
	T.taille=n;
	T.tete=(double *) malloc(n * sizeof(double));
	return T;
}

void affichageTableau(tableau T)
{
	int i;
	printf("[");
	for(i=0; i<T.taille - 1; i++){
		printf("%lf, ", T.tete[i]);
	};
	printf("%lf]\n", T.tete[T.taille-1]);
	return ;
}

void saisie(tableau T)
{
	int i;
	for(i = 0; i<T.taille; i++){
		scanf("%lf", T.tete + i);
	}
	return ;
}

tableau concatener(tableau T, tableau L)
{
	int i;
	tableau R = creer(T.taille + L.taille);
	for(i=0; i<T.taille; i++){
		R.tete[i] = T.tete[i];
	};	
	for(i = 0; i < L.taille; i++){
		R.tete[T.taille + i] = L.tete[i]; 
	}
	return R;
}

tableau removee(tableau T, int index)
{
	int i,j;
	tableau R = creer(index);	
	tableau L = creer(T.taille-1-index);
	for(i=0;i<R.taille;i++){
		R.tete[i] = T.tete[i];
		
	}
	for(j=0 ;j<L.taille ;j++){
		L.tete[j] = T.tete[index + j + 1];
	}
		
	tableau H = concatener(R,L);
	return H;
}

tableau add(tableau T, int num)
{
	int i;
	tableau H = creer(T.taille + 1);
	for(i=0; i<T.taille; i++){
		H.tete[i] = T.tete[i];
	}
	H.tete[T.taille] = num;
	return H;
}

void liberer(tableau T){
	if(T.tete!=NULL)
		free(T.tete);
	return ;
}

tableau affectation(tableau S, tableau T)
{
	if(T.tete==NULL)
	{
		if(S.tete != NULL)
			liberer(S);
		S.taille = 0;
		S.tete = NULL;
		return S;
	}
	if(S.taille != T.taille)
	{
		liberer(S);
		S = creer(T.taille);
	}
	int i;
	for(i=0; i<T.taille;i++)
	{
		S.tete[i] = T.tete[i];
	}
	return S;
}

void triInsertion(tableau T)
{
	int i,j,z;
	for(i=0;i<T.taille;i++)
	{
		for(j=0;j<i;j++)
		{
			if(T.tete[i] < T.tete[j])
			{
				z = T.tete[i];
				T.tete[i] = T.tete[j];
				T.tete[j] = z;
			}	
		}
	}
	return ;
}

tableau triBulles(tableau T)
{
	tableau S = creer(T.taille);
	int i,j,z;
	for(i=0;i<T.taille;i++)
	{
		S.tete[i] = T.tete[i];
	}
	for(i=0;i<T.taille-1;i++)
	{
		for(j=0;j<T.taille-1-i;j++)
		{
			if(S.tete[j] > S.tete[j+1])
			{
				z = S.tete[j];
				S.tete[j] = S.tete[j+1];
				S.tete[j+1] = z;
			}
		}
	}
	return S;
}


/* La fonction principale */

int main()
{
	tableau T = creer(5);
	saisie(T);
	affichageTableau(T);
	tableau S = affectation(S,T);
	affichageTableau(S);
	return 0;
}
