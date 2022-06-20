#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <stdlib.h>

#define MAX 50

int main()
{
  while(1) //Loop to keep inputting
  {
    char str[MAX];
    printf("$ ");
    fgets(str, MAX, stdin);   //takes input
    printf("%s\n", str);   //outputs
  }
}
