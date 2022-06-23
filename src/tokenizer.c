#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t')
  {
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if (c == ' ' || c == '\t' || c == '\0')
  {
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  for( int i = 0; i < sizeof(str); i++)
  {
    if (non_space_char(str[i]))
    {
      return &str[i];
    }
  }
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  char *str = word_start(word);
  for (int i = 0; i < sizeof(str); i++)
  {
    if (space_char(str[i]))
    {
      return &str[i];
    }
  }
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count = 0;
  for (int i = 0; i<sizeof(str); i++)
  {
    if (space_char(str[i+1]))
      count++;
  }
  return count+1;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *new_string = malloc((len+1) * sizeof(char));  //Declares memory space
  for( int i = 0; i<len; i++)
  {
    new_string[i] = inStr[i];   //Copies string of certain length 
  }
  new_string[len+1] = '\0';    //Insert null terminator
  return new_string;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int tokens = count_words(str);   //Number of words/tokens
  char **result = malloc((tokens+1)*sizeof(char));  //Declares space
  char *start = word_start(str);   //beginning of string
  for(int i=0; i<tokens; i++)
  {
    int len = (word_terminator(start) - word_start(start));   //length for copy_str
    result[i] = copy_str(start, len);  
    start = word_terminator(start);   //moves on to the next word
  }
  return result;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for( int i=0; i<sizeof(tokens); i++)
  {
    printf("\nToken[%d]: ", i);  //Print index
    for(int j=0; j<sizeof(tokens[i]);j++)
    {
      printf(" %s", tokens[i][j]);   //Print value
    }
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  free(tokens);
}
