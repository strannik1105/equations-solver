#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H
#include "src/common/list.h"
#include "src/common/func_result.h"

/*
    Interface providing functions peculiar to equations
*/
typedef struct 
{
    /*
        Function solving an equation and returning the set of its solutions 
    */
    FuncResult* (* solve)(const void* self);
    /*
        Equation desctructor
    */
    void (* delete)(void* self);
} Equation;


// macro for easy use
#define solve_equation(equation)  ((Equation*)equation)->solve(equation);
#define delete_equation(equation) ((Equation*)equation)->delete(equation);

#endif
