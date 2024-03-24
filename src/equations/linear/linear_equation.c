#include "src/common/alloc.h"
#include "src/equations/equation.h"
#include "linear_equation.h"


LinearEquation* make_linear_equation(double a, double b)
{
    LinearEquation* eq = (LinearEquation*)allocate(sizeof(LinearEquation));
    eq->eq.solve = solve_linear_equation;
    eq->eq.delete = delete_linear_equation;

    eq->a = a;
    eq->b = b;
    return eq;
}

void delete_linear_equation(void* equation)
{
    free((LinearEquation*)equation);
}

List* solve_linear_equation(const void* equation)
{
    List* equation_solution = make_list();
    LinearEquation* le = (LinearEquation*)equation;
    double* result = (double*)allocate(sizeof(double));
    *result = (-1)*(le->b/le->a);
    append(equation_solution, result);
    return equation_solution;
}