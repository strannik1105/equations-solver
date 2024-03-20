#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "equations/equation.h"
#include "equations/quadratic/quadratic_equation.h"
#include "equations/linear/linear_equation.h"
#include "common/list.h"


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return -1;
    }
    const char* eq_type = argv[1];
    Equation_t* equation;

    if(strcmp(eq_type,"-h") == 0)
    {
        printf("Available params: \n");
        printf("\t-q: Quadratic equation, requires 3 positional args(a, b, c) \n");
        printf("\t-l: Quadratic equation, requires 2 positional args(a, b) \n");
        printf("\n");
        printf("Ex: ./quadratic-equation -q 1 4 -12\n");
        return 0;
    }
    else if(strcmp(eq_type,"-q") == 0)
    {
        if (argc != 5)
        {
            return -1;
        }
        int a = strtol(argv[2], NULL, 10);
        int b = strtol(argv[3], NULL, 10);
        int c = strtol(argv[4], NULL, 10);
        equation = (void*)make_quadratic_equation(a, b, c);
    }
    else if(strcmp(eq_type,"-l") == 0)
    {
        if (argc != 4)
        {
            return -1;
        }
        int a = strtol(argv[2], NULL, 10);
        int b = strtol(argv[3], NULL, 10);
        equation = (void*)make_linear_equation(a, b);
    }
    else
    {
        return -1;
    }

    // Let's solve equation
    List* solution = solve_equation(equation);
    Node* cursor = solution->root;

    printf("solutions\n");
    while(cursor != NULL)
    {
        printf("%f\n", *(double*)(cursor->data));
        cursor = cursor->next;
    }
    delete_list(solution);
    delete_equation(equation);
    return 0;
}