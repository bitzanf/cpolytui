//
// Created by filip on 23.11.23.
//

#ifndef POLYTUI_ELEMENT_H
#define POLYTUI_ELEMENT_H

#include "vtable.h"

typedef enum eTUIElements {
#include "elements/_enum_defs.inc"

    _TUI_NELEMENTS
} eTUIElements;

typedef struct TUIElement {
    VTABLE *classvars, *local;
} TUIElement;

typedef struct TUIElementChildInfo {
    int xpos, ypos;
    TUIElement *child;
} TUIElementChildInfo;

bool initBackend();
void freeBackend();

TUIElement* elementNew(eTUIElements type);
void elementDestroy(TUIElement* element);
bool elementNewInPlace(eTUIElements type, TUIElement *element);
void elementDestroyInPlace(TUIElement *element);

eTUIElements elementGetType(TUIElement *element);

#endif //POLYTUI_ELEMENT_H
