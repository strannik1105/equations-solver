#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void err_exit(char* message)
{
    printf("%s\n", message);
    exit(1);
}