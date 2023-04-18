/* ------------------------------------------------ */

/* Project 2: PWordCount: A Pipe-based WordCount Tool*/
/* Advanced Operating System*/
/* HariPrabhanjan Lakshminarayana */
/* hzl0151@auburn.edu*/
/* 02/05/2023*/

/* ------------------------------------------------ */

/* Libraries for C program Begins */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/* Libraries for C program Ends */

/* Local Libraries for the program Begins */

#include "helper.h"

/* Local libraries for the program Ends */

/* -------------------------------------- */

/* Error Message : err_msg */

/* -------------------------------------- */

/* Different error messages can be printed by error message printers depending on the results. */

void err_msg(int err)
{

  /* Incorrect function usage */
  /* Use of too few or too many arguments */
  
  if (err == 0)
  {
    printf("\nPlease enter a file name.\n\nUsage: ./pwordcount <filename>\n");
  }

  /* Incorrect use of the pwordcount function; only accept one argument */

  if (err == 1)
  {
    printf("\nUnable to open file.\n");
    printf("Please verify that the file exists and that you have read access....\n\n");
  }

  /* Nothing to return */
  return;
}

/* ------------------------------------------ */

/* Counting Words: count_words */

/* ------------------------------------------ */

/* Count all the words in a given char array */

int count_words(char* arr)
  {
    /* Local variables */
    char words = 0;
    int i;
    
    /* Loop through the char array */

    for (i=0; i<strlen(arr); i++)
    {
      
      /* Checking for the spaces */

      if (arr[i] == ' ' ||
          arr[i] == '\t' ||
          arr[i] == '\n' ||
          arr[i] == '\0')
      {
        words++;
      }
    }

    /* Total words in the fiile should be returned. */
    return words;
  }
