#include <math.h>
#include "src/common/alloc.h"
#include "src/common/list.h"
#include "src/common/utils.h"
#include "quadratic_equation.h"

static void delete_quadratic_equation(void* equation)
{
    free(equation);
}

static inline double discriminant(const QuadraticEquation* equation)
{
    return equation->b*equation->b - 4*equation->a*equation->c;
}


static inline double discriminant_sqrt(const QuadraticEquation* equation)
{
    return sqrt(discriminant(equation));
}

static List* solve_quadratic_equation(const void* equation)
{
    List* solutions = make_list();
    QuadraticEquation* eq = (QuadraticEquation*)equation;

    if(discriminant(eq) < 0)
    {
        /*
            If the discriminant is less than zero, we return an empty list
        */
        return solutions;
    }

    double* solution1 = allocate_typed(double);
    *solution1 = ((-1)*eq->b + discriminant_sqrt(equation))/(2*eq->a);
    append(solutions, solution1);

    double* solution2 = allocate_typed(double);
    *solution2 = ((-1)*eq->b - discriminant_sqrt(equation))/(2*eq->a);
    append(solutions, solution2);
    return solutions;
}

QuadraticEquation* make_quadratic_equation(double a, double b, double c)
{
    QuadraticEquation* equation = allocate_typed(QuadraticEquation);
    equation->eq.solve = solve_quadratic_equation;
    equation->eq.delete = delete_quadratic_equation;

    if(a == 0)
    {
        err_exit("Coefficient a can not be zero");
    }

    equation->a = a;
    equation->b = b;
    equation->c = c;
    return equation;
}

