#include "../../common/alloc.h"
#include "quadratic_equation.h"



QuadraticEquation* make_quadratic_equation(double a, double b, double c)
{
    QuadraticEquation* equation = (QuadraticEquation*)allocate(sizeof(QuadraticEquation));
    equation->eq.solve_equation = solve_quadratic_equation;

    equation->a = a;
    equation->b = b;
    equation->c = c;
    return equation;
}

void delete_quadratic_equation(QuadraticEquation* equation)
{
    free(equation);
}

double solve_quadratic_equation(const QuadraticEquation* equation)
{
    return 1.0 + 2.0;
}