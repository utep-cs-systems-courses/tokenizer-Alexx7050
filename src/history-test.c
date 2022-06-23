#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void main() {
    List* list = init_history();
    add_history(list, "happy");
    if (strcmp(list->root->str, "happy") == 0)
      printf("True");
    add_history(list, "joy");
    if (strcmp(list->root->next->str, "joy") == 0)
      printf("True");

    List* list2 = init_history();
    add_history(list2, "happy");
    if (strcmp(get_history(list2, 1), "happy") == 0)
      printf("True");
    add_history(list2, "day!");
    if (strcmp(get_history(list2, 1), "day!") == 0)
      printf("True");
}
