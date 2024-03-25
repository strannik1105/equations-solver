#include <stdio.h>
#include <stdlib.h>
#include "common/list.h"
#include "common/cmd.h"
#include "common/func_result.h"
#include "equations/equation.h"
#include "equations/quadratic/quadratic_equation.h"
#include "equations/linear/linear_equation.h"


int main(int argc, char *argv[])
{
    // parse args
    CMDParseResult* parse_result = parse_cmd(argc, argv);
    raise_from_result(parse_result);

    void* equation = parse_result->equation;

    // Let's solve equation
    FuncResult* solve_result = solve_equation(equation);
    int status = solve_result->status;
    if(status == FUNC_SUCCESS)
    {
        List* solution = solve_result->result;
        void* cursor = pop(solution);

        if(cursor == NULL)
        {
            printf("Equation has no solutions\n");
        }
        else
        {
            printf("Solutions: \n");
            while(cursor != NULL)
            {
                printf("\t%f\n", *(double*)(cursor));
                free(cursor);
                cursor = pop(solution);
            }
        }
        delete_list(solution);
    }

    print_status_if_err(solve_result);
    delete_func_result(solve_result);
    free(parse_result);
    delete_equation(equation);
    return status;
}