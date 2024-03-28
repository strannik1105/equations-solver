#include <stdio.h>
#include "alloc.h"
#include "func_result.h"


FuncResult* make_func_result(enum FuncStatusCode status, void* exec_result)
{
    FuncResult* func_result = allocate_typed(FuncResult);
    func_result->status = status;
    func_result->result = exec_result;
    return func_result;
}

void delete_func_result(FuncResult* func_result)
{
    free(func_result);
}

void print_status_if_err(FuncResult* func_result)
{
    switch (func_result->status)
    {
    case FUNC_FAIL:
        printf("Unknow error\n");
        break;
    case FUNC_DIVIDE_BY_ZERO:
        printf("Divide by zero\n");
        break;
    case FUNC_DISCRIMINANT_LESS_THAN_ZERO:
        printf("Discriminant less than zero\n");
        break;
    default:
        break;
    }
}
