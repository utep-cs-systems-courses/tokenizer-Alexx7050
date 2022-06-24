#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

#define MAX 50

int main()
{
  
  char str[MAX];
  List *list = init_history();
    
  while(1)  //Keeps prompting 
  {
    printf("Tokenizer:\n Quit: 'q'\n History: 'h'\n"); 
    printf("Specific History do '!' followed by a number \n Or simply enter a sentence\n");
    printf("$ ");
    fgets(str, MAX, stdin);   //takes input

    if (str[0] == 'q')  //If user wants to quit
      goto done;

    else if (str[0] == 'h')  //Prints history
    {
      printf("----\n");
      print_history(list);
      printf("----\n");
    }
    
    else if (str[0] == '!')
    {
      int id_num = atoi(str+1);   //Type cast from str to int
      char *history = get_history(list, id_num);  //get history from specific id
      printf("You selected !%d: %s\n", id_num, history);  
      char **tokens = tokenize(history);  //tokenize history
      print_tokens(tokens);
      free_tokens(tokens);  
    }
    else
    {
      char **tokens = tokenize(str);    //tokenizer
      print_tokens(tokens);
      free_tokens(tokens);
      add_history(list, str);   //Adds string to history
    }
  }

  done:   //Program Exit
  printf("Bye!\n");
  return 0;
  
}
