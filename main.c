
#include <stdio.h>

#include "element.h"
#include "elements/window.h"

/// C Polymorphic Text User Interface

int main() {
    if (!initBackend()) {
        perror("init_backend()");
        return -1;
    } else puts("initialized!");

    TUIElement *root = elementNew(TUI_WINDOW);

    freeBackend();
    return 0;
}
