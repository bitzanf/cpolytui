#ifndef POLYTUI_WINDOW_H
#define POLYTUI_WINDOW_H

#define WINDOW_N_CLS_PROPERTIES 4 /* count */
#define WINDOW_N_LOCAL_PROPERTIES 5 /* count */

struct TUIElement;
struct VTABLE;
bool WINDOW_constructor(struct TUIElement *el);
void WINDOW_destructor(struct TUIElement *el);

bool WINDOW_class_init(struct VTABLE *vtable);
void WINDOW_class_deinit(struct VTABLE *vtable);

#endif //POLYTUI_WINDOW_H
