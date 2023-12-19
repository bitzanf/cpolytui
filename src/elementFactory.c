//
// Created by filip on 23.11.23.
//

#include <stddef.h>
#include "element.h"
#include "elementFunctions.h"
#include "memoryManagement.h"

#define INIT_CLASS_VTABLE(type) vTableInit(type##_N_CLS_PROPERTIES, &ClassVTables[TUI_##type])
#define INIT_CLASS_VARS(type) type##_class_init(&ClassVTables[TUI_##type])
#define DEINIT_CLASS_VARS(type) type##_class_deinit(&ClassVTables[TUI_##type])
#define INIT_CLASS_CDTORS(type) \
    elementConstructors[TUI_##type] = & type##_constructor; \
    elementDestructors[TUI_##type] = & type##_destructor;

VTABLE ClassVTables[_TUI_NELEMENTS];

bool TUIBackendInitialized = 0;

typedef bool (*element_constructor_t)(TUIElement *el);
typedef void (*element_destructor_t)(TUIElement *el);
element_constructor_t elementConstructors[_TUI_NELEMENTS];
element_destructor_t elementDestructors[_TUI_NELEMENTS];


bool initBackend() {
    if (TUIBackendInitialized) return 0;

#include "elements/_init_funcs.inc"

    TUIBackendInitialized = 1;
    return 1;
}

void freeBackend() {
    if (!TUIBackendInitialized) return;

#include "elements/_deinit_funcs.inc"

    TUIBackendInitialized = 0;
}

TUIElement* elementNew(eTUIElements type) {
    if (!TUIBackendInitialized || type >= _TUI_NELEMENTS) return NULL;

    VTABLEEntry *vte = vTableGetProperty(&ClassVTables[type], VTc_SIZE);
    if (!vte) return NULL;

    TUIElement *el = mm_alloc(*(int*)vte->val);
    if (!el) return NULL;

    if (!elementConstructors[type](el)) {
        mm_free(el);
        return NULL;
    } else return el;
}

void elementDestroy(TUIElement* element) {
    if (element && TUIBackendInitialized) {
        VTABLEEntry *vte = vTableGetProperty(element->classvars, VTc_TYPE);
        if (vte) {
            eTUIElements type = *(eTUIElements*)vte->val;
            elementDestructors[type](element);
        }
        mm_free(element);
    }
}

eTUIElements elementGetType(TUIElement *element) {
    if (!TUIBackendInitialized) return -1;
    VTABLEEntry *vte = vTableGetProperty(element->classvars, VTc_TYPE);
    if (vte) return *(eTUIElements*)vte->val;
    else return -1;
}

bool elementNewInPlace(eTUIElements type, TUIElement *element) {
    if (type >= _TUI_NELEMENTS || !TUIBackendInitialized) return 0;
    else return elementConstructors[type](element);
}

void elementDestroyInPlace(TUIElement *element) {
    if (!element || !TUIBackendInitialized) return;
    elementDestructors[elementGetType(element)](element);
}
