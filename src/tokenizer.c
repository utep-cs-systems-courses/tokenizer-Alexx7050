#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t' || c == '\0')
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
  if (c == ' ' || c == '\t')
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
  char *pstart;
  for( int i = 0; i < sizeof(str); i++)
  {
    if (non_space_char(str[i]))
    {
      pstart = &str[i];
      return pstart;
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
  char *pstart = word_start(str);
  while (*pstart != 0)
  {
    if (non_space_char(*pstart))
      count+=1;
    pstart = word_terminator(pstart);
    pstart = word_start(pstart);
  }
  return count;  
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
  new_string[len] = '\0';  //Set null terminator
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
  char **result = malloc((tokens+1)*sizeof(char*));  //Declares space
  char *start = word_start(str);
  for(int i=0; i<tokens; i++)
  {
    start = word_start(start);
    int len = (word_terminator(start) - word_start(start));   //length for copy_str
    result[i] = copy_str(start, len);  
    start = word_terminator(start);   //moves on to the next word
  }
  result[tokens] = '\0';  //Null terminator
  return result;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  printf("-----\n");
  for( int i=0; tokens[i]!=0; i++)
  {
    printf("Token[%d]: %s\n", i, tokens[i]);  //Print index
  }
  printf("-----\n");
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i]; i++)
  {
    free(tokens[i]);  // Frees individaul word
  }
  free(tokens);  //Frees token space
}
