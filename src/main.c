#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "equations/equation.h"
#include "equations/quadratic/quadratic_equation.h"
#include "equations/linear/linear_equation.h"
#include "common/list.h"
#include "common/cmd.h"


int main(int argc, char *argv[])
{
    // parse args
    CMDParseResult* parse_result = parse_cmd(argc, argv);
    raise_from_result(parse_result);
    void* equation = parse_result->equation;

    // Let's solve equation
    List* solution = solve_equation(equation);
    void* cursor = pop(solution);
    printf("solutions\n");
    while(cursor != NULL)
    {
        printf("%f\n", *(double*)(cursor));
        free(cursor);
        cursor = pop(solution);
    }
    delete_list(solution);
    delete_equation(equation);
    return 0;
}