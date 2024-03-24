#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/common/alloc.h"
#include "src/equations/quadratic/quadratic_equation.h"
#include "src/equations/linear/linear_equation.h"
#include "cmd.h"



CMDParseResult* make_cmd_parse_result(enum ParseStatus status, void* equation)
{
    CMDParseResult* ptr = allocate_typed(CMDParseResult);
    ptr->status = status;
    ptr->equation = equation;
    return ptr;
}

CMDParseResult* parse_cmd(int argc, char *argv[])
{
    if(argc < 2)
    {
        return make_cmd_parse_result(TOO_LOW_ARGS, NULL);
    }
    const char* eq_type = argv[1];
    enum ParseStatus status = SUCCESS;
    void* equation = NULL;

    if(strcmp(eq_type,"-h") == 0)
    {
        printf("Available params: \n");
        printf("\t-q: Quadratic equation, requires 3 positional args(a, b, c) \n");
        printf("\t-l: Quadratic equation, requires 2 positional args(a, b) \n");
        printf("\n");
        printf("Ex: ./quadratic-equation -q 1 4 -12\n");
        status = SUCCESS;
    }
    else if(strcmp(eq_type,"-q") == 0)
    {
        if (argc != 5)
        {
            status = TOO_LOW_ARGS;
        }
        else
        {
            double a = strtof(argv[2], NULL);
            double b = strtof(argv[3], NULL);
            double c = strtof(argv[4], NULL);
            equation = (void*)make_quadratic_equation(a, b, c);
        }
    }
    else if(strcmp(eq_type,"-l") == 0)
    {
        if (argc != 4)
        {
            status = TOO_LOW_ARGS;
        }
        else
        {
            double a = strtof(argv[2], NULL);
            double b = strtof(argv[3], NULL);
            equation = (void*)make_linear_equation(a, b);
        }
    }
    else
    {
        status = INCORRECT_ARGS;
    }
    return make_cmd_parse_result(status, equation);
}

void raise_from_result(CMDParseResult* result)
{
    switch (result->status)
    {
    case SUCCESS:
        if(result->equation == NULL)
        {
            exit(0);
        }
        break;
    case INCORRECT_ARGS:
        printf("Incorrect args provided\n");
        exit(1);
    case TOO_LOW_ARGS:
        printf("Too low args provided\n");
        exit(1);
    case TOO_MANY_ARGS:
        printf("Too many args provided\n");
        exit(1);
    }
}