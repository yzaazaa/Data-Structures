//
//  polynom.h
//  
//
//  Created by El Kahoui on 28/03/2021.
//

#ifndef polynom_h
#define polynom_h

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<math.h>

#endif /* polynom_h */

/* The structure representing a monomial */

struct monom
{
    double coeff;
    unsigned exponent;
    struct monom * next;
};
typedef struct monom monom;

/* The polynomial */
typedef struct monom * polynom;

/* Interface */

/* Construction and destruction of polynomials */
polynom makeMonom(double,unsigned);
void addMonom(polynom *,monom *);
void freePoly(polynom);

/* Printing */
void printPoly(polynom);

/* Arithmetic of polynomials */
int degrePoly(polynom);
polynom sumPoly(polynom,polynom);
polynom oppositePoly(polynom);
polynom substractPoly(polynom,polynom);
polynom productPoly(polynom,polynom);
polynom scalePoly(double,polynom);

/* Calculus */
polynom derivePoly(polynom);
polynom primitivePoly(polynom,double);
double evalPoly(polynom,double);

/* Euclidean division and gcd */
polynom euclidRemainder(polynom,polynom);

