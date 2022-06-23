#include <stdio.h>
#include "tokenizer.h"

void main()
{
  char pinput[] = "Hello nice people!";
  char pinput2[] = "hey world\t";
  char pinput3[] = "Hello brother from another mother!";
  char pinput4[] = "I like dancing";
  
  char *x;
  int n;
  x = word_start(pinput);
  printf("The first letter is: %c\n", *x);
  x = word_terminator(pinput);
  printf("The word terminator is: %c\n", *x);
  n = count_words(pinput);
  printf("The number of words are: %d\n", n);
  char **str = tokenize(pinput);
  print_tokens(str);
  printf("\nTest 2\n");
  char **str2 = tokenize(pinput2);
  print_tokens(str2);

  printf("\nTest 3\n");
  char **str3 = tokenize(pinput3);
  print_tokens(str3);

  printf("\nTest 4\n");
  char **str4 = tokenize(pinput4);
  print_tokens(str4);
}
