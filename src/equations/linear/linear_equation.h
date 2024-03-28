#ifndef LINEAR_EQUATION_LINEAR_EQUATION_H
#define LINEAR_EQUATION_LINEAR_EQUATION_H
#include "src/equations/equation.h"
#include "src/common/list.h"


typedef struct {
    Equation eq;
    
    double a;
    double b;
} LinearEquation;

//constructor
LinearEquation* make_linear_equation(double a, double b);

#endif
