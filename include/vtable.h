//
// Created by filip on 23.11.23.
//

#ifndef POLYTUI_VTABLE_H
#define POLYTUI_VTABLE_H

typedef enum eClassVTABLE {
    VTc_TYPE = 0,
    VTc_SIZE,
    VTc_RENDER,
    VTc_ONEVENT,

    _VTc_NVARS
} eClassVTABLE;

typedef enum eLocalVTABLE {
    VTl_PARENT = 0,
    VTl_EVTCTX,
    VTl_CHILDREN,
    VTl_WIDTH,
    VTl_HEIGHT,

    _VTl_NVARS
} eLocalVTABLE;

typedef struct VTABLEEntry {
    int key;
    int val_size;
    void* val;
} VTABLEEntry;

typedef struct VTABLE {
    int size;
    int capacity;
    VTABLEEntry* entries;
} VTABLE;

VTABLEEntry* vTableGetProperty(VTABLE* vtable, int propertyIdx);
VTABLEEntry* vTableAddProperty(VTABLE* vtable, int propertyIdx);
bool vTableInit(int initialCapacity, VTABLE *vtable);
void vTableDestroy(VTABLE *vtable);


#endif //POLYTUI_VTABLE_H
