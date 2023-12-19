//
// Created by filip on 23.11.23.
//

#include "vtable.h"
#include "memoryManagement.h"

bool vTableInit(int initialCapacity, VTABLE *vtable) {
    vtable->size = 0;
    vtable->capacity = initialCapacity;
    vtable->entries = mm_alloc(initialCapacity * sizeof(VTABLEEntry));
    return vtable->entries != nullptr;
}

// serazene pole => vyhledavani binarnim pulenim
VTABLEEntry * vTableGetProperty(VTABLE* vtable, int propertyIdx) {

}

VTABLEEntry* vTableAddProperty(VTABLE* vtable, int propertyIdx) {

}

void vTableDestroy(VTABLE *vtable) {
    if (vtable && vtable->entries) {
        if (vtable->capacity > 0) mm_free(vtable->entries);
        vtable->size = vtable->capacity = 0;
        vtable->entries = nullptr;
    }
}
