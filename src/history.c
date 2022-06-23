#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *LL = malloc(sizeof(List));  //Declare enough space for list
  LL->root = malloc(sizeof(Item));
  return LL;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof(Item));  //declare space for new item
  Item *temp = list->root;   //Temp variable for traversing linked list
  int id = 1;

  while (temp->next != 0)  //Checks for end of list
  {
    temp = temp->next;
    ++id;
  }
  //End of list
  //Adds new item with a string and id
  temp->next = item;
  item->id = id;
  item->str = copy_str(str,sizeof(str));
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list->root;  //Temp variable for traversing list

  while (temp->id != id)
    temp = temp->next;
  return (temp->str) ? temp->str : "Not found";   //retrieves string 
  
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp = list->root;
  while (temp != 0)    //Traverses entire list
  {
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *temp = list->root;
  while(temp->next!=0)
  {
    Item *curr = temp;  //Current item
    free(curr->str);  //Free string in current item
    free(curr);  //Free current item
    temp = temp->next;  //Moves on to next item
  }
  free(temp->str);  //Free string in last item
  free(temp);  //Free last item
  free(list);   //Free linkedlist
}
