#include "src/common/alloc.h"
#include "src/common/utils.h"
#include "src/common/func_result.h"
#include "src/equations/equation.h"
#include "linear_equation.h"

static void delete_linear_equation(void* equation)
{
    free(equation);
}

static FuncResult* solve_linear_equation(const void* equation)
{
    List* equation_solution = make_list();
    LinearEquation* le = (LinearEquation*)equation;

    if(le->a == 0)
    {
        /*
            Becouse it raise devide by zero exception
        */
        return make_func_result(FUNC_DEVIDE_BY_ZERO, NULL);
    }

    double* result = (double*)allocate(sizeof(double));
    *result = (-1)*(le->b/le->a);
    append(equation_solution, result);
    return make_func_result(FUNC_SUCCESS, equation_solution);
}

LinearEquation* make_linear_equation(double a, double b)
{
    LinearEquation* eq = allocate_typed(LinearEquation);
    eq->eq.solve = solve_linear_equation;
    eq->eq.delete = delete_linear_equation;

    eq->a = a;
    eq->b = b;
    return eq;
}
