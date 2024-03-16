#include <stdio.h>
#include "equations/equation.h"
#include "equations/quadratic/quadratic_equation.h"
#include "equations/linear/linear_equation.h"

impl_eq(QuadraticEquation*);
    

int main()
{
    QuadraticEquation* quadratic_equation = make_quadratic_equation(1.0, 1.0, -1.0);
    double solution = quadratic_equation->eq.solve_equation(quadratic_equation);
    printf("%f\n", solution);
    LinearEquation* linear_equation = make_linear_equation(2.0, 10.0);
    solution = linear_equation->eq.solve_equation(linear_equation);
    printf("%f\n", solution);
    solution = solve_equation(quadratic_equation);
    printf("%f\n", solution);
    return 0;
}