#ifndef LINEAR_EQUATION_LINEAR_EQUATION_H
#define LINEAR_EQUATION_LINEAR_EQUATION_H
#include <complex.h>
#include "../equation.h"
#include "../../common/list.h"


/*

*/


typedef struct {
    Equation eq;
    
    double a;
    double b;
} LinearEquation;

LinearEquation* make_linear_equation(double a, double b);

void delete_linear_equation(LinearEquation* equation);

List* solve_linear_equation(const void* equation);


#endif
