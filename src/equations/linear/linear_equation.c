#include <stdlib.h>
#include "linear_equation.h"

LinearEquation* make_linear_equation(double a, double b)
{
    LinearEquation* eq = (LinearEquation*)malloc(sizeof(LinearEquation));
    eq->eq.solve_equation = solve_linear_equation;
    eq->a = a;
    eq->b = b;
    return eq;
}


double solve_linear_equation(const LinearEquation* equation)
{
    return (-1)*(equation->b/equation->a);
}