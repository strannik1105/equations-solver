#ifndef FUNC_RESULT_FUNC_RESULT_H
#define FUNC_RESULT_FUNC_RESULT_H


enum FuncStatusCode
{
    FUNC_SUCCESS,
    FUNC_FAIL,   // unknow error
    FUNC_DISCRIMINANT_LESS_THAN_ZERO,
    FUNC_DIVIDE_BY_ZERO
};

typedef struct
{
    enum FuncStatusCode status;
    void* result;
} FuncResult;

//constructor
FuncResult* make_func_result(enum FuncStatusCode status, void* exec_result);
//destructor
void delete_func_result(FuncResult* func_result);
//printing erros if status is not FUNC_SUCCESS
void print_status_if_err(FuncResult* func_result);

#endif