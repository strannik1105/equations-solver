#ifndef ALLOC_H
#include <stdlib.h>


void* allocate(const size_t size);

#define allocate_typed(T)   (T*)allocate(sizeof(T))

#endif