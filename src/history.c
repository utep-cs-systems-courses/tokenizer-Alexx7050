#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *pl = (struct node*)malloc(sizeof(struct node));  //Declare enough space for list
  return pl;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *item = (struct node*)malloc(sizeof(Item));  //declare space for item
  Item *temp = list->root;   //Temp variable for traversing linked list
  int id = 1;

  while (temp->next != NULL)  //Checks for end of list
  {
    temp = temp->next;
    ++id;
  }
  //End of list
  //Adds new item with a string and id
  temp->next = item;
  item->id = id;
  item->str = str;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list->root;  //Temp variable for traversing list

  if (temp->id == id)
    return temp->str
  get_history(temp->next, id);
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp = list->root;
  while (temp != NULL)    //Traverses entire list
  {
    printf("%d: %s\n", temp->id, temp->str);
    temp = temp->next
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  
}
