//
// Created by filip on 23.11.23.
//

#include "memoryManagement.h"
#include <stdlib.h>

void *mm_alloc(int nBytes) {
    return malloc(nBytes);
}

void mm_free(void *mem) {
    if (mem) free(mem);
}
