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
    /*
        Equation desctructor
    */
    void (* delete)(void* self);
} Equation;

typedef struct
{
    Equation eq;
} Equation_t;

// macro for easy use
#define solve_equation(equation)  equation->eq.solve(equation);
#define delete_equation(equation)  equation->eq.delete(equation);

#endif
