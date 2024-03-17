#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H
#include "../common/list.h"

typedef struct 
{
    List* (* solve_equation)(const void* self);
} Equation;


#define impl_eq(T)                                                                                     \
    List* solve_equation(T equation)                                                                                                 \
    {                                                                                                                  \
        return equation->eq.solve_equation(equation);                                                                    \
    }


#endif
