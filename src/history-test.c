#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void main() {
    List* list = init_history();
    add_history(list, "happy");
    strcmp(list->root->str, "happy") == 0;
    add_history(list, "joy");
    strcmp(list->root->next->str, "joy") == 0;

    List* list2 = init_history();
    add_history(list2, "happy");
    strcmp(get_history(list2, 1), "happy") == 0;
    add_history(list2, "day!");
    strcmp(get_history(list2, 1), "day!") == 0;
}
