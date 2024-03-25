#include <math.h>
#include "src/common/alloc.h"
#include "src/common/list.h"
#include "src/common/utils.h"
#include "src/common/func_result.h"
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

static FuncResult* solve_quadratic_equation(const void* equation)
{
    List* solutions = make_list();
    QuadraticEquation* eq = (QuadraticEquation*)equation;

    if(eq->a == 0)
    {
        /*
            Becouse it raise devide by zero exception
        */
        return make_func_result(FUNC_DEVIDE_BY_ZERO, NULL);
    }

    if(discriminant(eq) < 0)
    {
        /*
            If the discriminant is less than zero, we return an empty list
        */
        return make_func_result(FUNC_DISCRIMINANT_LESS_THAN_ZERO, NULL);
    }

    double* solution1 = allocate_typed(double);
    *solution1 = ((-1)*eq->b + discriminant_sqrt(equation))/(2*eq->a);
    append(solutions, solution1);

    double* solution2 = allocate_typed(double);
    *solution2 = ((-1)*eq->b - discriminant_sqrt(equation))/(2*eq->a);
    append(solutions, solution2);
    return make_func_result(FUNC_SUCCESS, solutions);
}

QuadraticEquation* make_quadratic_equation(double a, double b, double c)
{
    QuadraticEquation* equation = allocate_typed(QuadraticEquation);
    equation->eq.solve = solve_quadratic_equation;
    equation->eq.delete = delete_quadratic_equation;

    equation->a = a;
    equation->b = b;
    equation->c = c;
    return equation;
}

