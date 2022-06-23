#include <stdio.h>
#include "tokenizer.h"

void main()
{
  char pinput[] = "Hello world !";

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
}
