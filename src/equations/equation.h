#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H

typedef struct {
    double (* solve_equation)(const void* self);
} Equation;


#define impl_eq(T)                                                                                     \
    static double solve_equation(T equation)                                                                                                 \
    {                                                                                                                  \
        return equation->eq.solve_equation(equation);                                                                    \
    }

#endif