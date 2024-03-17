#include <math.h>
#include "../../common/alloc.h"
#include "../../common/list.h"
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

static inline double discriminant_sqrt(const QuadraticEquation* equation)
{
    return sqrt(equation->b*equation->b - 4*equation->a*equation->c);
}

List* solve_quadratic_equation(const void* equation)
{
    List* solutions = make_list();
    QuadraticEquation* eq = (QuadraticEquation*)equation;

    double* solution1 = allocate_typed(double);
    *solution1 = ((-1)*eq->b + discriminant_sqrt(equation))/(2*eq->a);
    double* solution2 = allocate_typed(double);
    *solution2 = ((-1)*eq->b - discriminant_sqrt(equation))/(2*eq->a);
    append(solutions, solution1);
    append(solutions, solution2);
    return solutions;
}