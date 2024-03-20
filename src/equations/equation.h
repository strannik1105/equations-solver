#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H
#include "../common/list.h"

typedef struct 
{
    List* (* solve)(const void* self);
} Equation;


#define solve_equation(equation)  equation->eq.solve(equation);

#endif
