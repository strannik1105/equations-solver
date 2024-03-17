#include <stdio.h>
#include "equations/equation.h"
#include "equations/quadratic/quadratic_equation.h"
#include "equations/linear/linear_equation.h"
#include "common/list.h"

    
int main()
{
    QuadraticEquation* quadratic_equation = make_quadratic_equation(1, 4, -12);
    List* solution = quadratic_equation->eq.solve_equation(quadratic_equation);
    Node* cursor = solution->root;
    printf("solutions\n");
    while(cursor != NULL)
    {
        printf("%f\n", *(double*)(cursor->data));
        cursor = cursor->next;
    }
    delete_list(solution);
    return 0;
}