#ifndef QUADRATIC_EQUATION_QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_QUADRATIC_EQUATION_H
#include "src/equations/equation.h"


typedef struct {
    Equation eq;
    
    double a;
    double b;
    double c;
} QuadraticEquation;

//constructor
QuadraticEquation* make_quadratic_equation(double a, double b, double c);

#endif
