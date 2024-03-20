#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H
#include "../common/list.h"


/*
    Interface providing functions peculiar to equations
*/
typedef struct 
{
    /*
        Function solving an equation and returning the set of its solutions 
    */
    List* (* solve)(const void* self);
} Equation;

typedef struct
{
    Equation eq;
} Equation_t;


#define solve_equation(equation)  equation->eq.solve(equation);

#endif
