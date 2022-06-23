#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

#define MAX 50

int main()
{
  
  char str[MAX];
  List *linkedlist = init_history();
    
  while(1)  //Keeps prompting 
  {
    printf("Tokenizer:\n Quit: 'q'\n History: 'h'\n"); 
    printf("Specific History do '!' followed by a number 1-9 \n Or simply enter a sentence\n");
    printf("$ ");
    fgets(str, MAX, stdin);   //takes input
    printf("%s\n", str);   //outputs

    if (str[0] == 'q' && str[1] == '\0')  //If user wants to quit
      goto done;

    else if (str[0] == 'h' && str[1] == '\0')  //Prints history
    {
      print_history(linkedlist);
    }

    else if (str[0] == '!' && str[1] == '\0')
    {
      int id_num = atoi(str+1);   //Type cast from str to int
      char *history = get_history(linkedlist, id_num);
      printf("You selected !%d: %s", history);
    }
    else
    {
      char **tokens = tokenize(str);
      print_tokens(tokens);
      add_history(linkedlist, str);
	free_tokens(tokens);
    }
  }

  done:
  printf("\nBye!");
  return 0;
}
