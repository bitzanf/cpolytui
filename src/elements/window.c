#include "elements/window.h"
#include "vtable.h"
#include "element.h"

#define VTE_ADD(_index, _size, _val) \
    vte = vTableAddProperty(vtable, (_index)); \
    if (!vte) return false; \
    vte->val_size = (_size); \
    vte->val = (void*)(_val);


bool WINDOW_constructor(struct TUIElement *el) {

}

void WINDOW_destructor(struct TUIElement *el) {

}

bool WINDOW_class_init(struct VTABLE *vtable) {
    VTABLEEntry *vte;

    VTE_ADD(VTc_TYPE, 0, TUI_WINDOW);
    VTE_ADD(VTc_SIZE, 0, 64);

    return true;
}

void WINDOW_class_deinit(struct VTABLE *vtable) {

}
