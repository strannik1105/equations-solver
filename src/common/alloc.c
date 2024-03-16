#include <stdio.h>
#include "alloc.h"


void* allocate(const size_t size)
{
    void* ptr = malloc(size);
    if(ptr == NULL)
    {
        perror("Can't allocate");
        exit(-1);
    }
    return ptr;
}
