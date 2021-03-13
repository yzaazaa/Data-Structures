//
//  point.c
//  
//
//  Created by El Kahoui on 23/02/2021.
//

#include <stdio.h>


struct point
{
    double absc;
    double ord;
};
typedef struct point point;


/* Prototypes des fonctions */
point somme(point,point);
point soustraction(point, point);
point produit(double, point);
void affichage(point);
void saisie(point *);


void affichage(point p)
{
	printf("( %lf , %lf)\n",p.absc,p.ord);
	return ;
}

void saisie(point * p)
{
	scanf("%lf%lf",&p->absc,&p->ord);
	return;
}

point somme(point p,point q)
{
	point r;
	r.absc=p.absc+q.absc;
	r.ord=p.ord+q.ord;
	return r;
}

point soustraction(point p, point q)
{
	point r;
	r.absc = p.absc - q.absc;
	r.ord = p.ord - q.ord;
	return r;
}

point produit(double a, point p)
{
	point r;
	r.absc = a * p.absc;
	r.ord = a * p.ord;
	return r;
}
/* La fonction principale */

int main()
{
	point p,q;
	saisie(&p);
	saisie(&q);
	point r=somme(p,q);
	point g=soustraction(p,q);
	double a= 5.5;
	point z=produit(a, p);
	affichage(r);
	affichage(g);
	affichage(z);
    return 0;
}

