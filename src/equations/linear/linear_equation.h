#ifndef LINEAR_EQUATION_LINEAR_EQUATION_H
#define LINEAR_EQUATION_LINEAR_EQUATION_H
#include <complex.h>
#include "../equation.h"


typedef struct {
    Equation eq;
    
    double a;
    double b;
} LinearEquation;

LinearEquation* make_linear_equation(double a, double b);


// void delete_quadratic_equation(QuadraticEquation* equation);

double solve_linear_equation(const LinearEquation* equation);


#endif
