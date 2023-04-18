/* ---------------------------------------------- */


/* Project 2: PWordCount: A Pipe-based WordCount Tool*/
/* Advanced Operating System*/
/* HariPrabhanjan Lakshminarayana */
/* hzl0151@auburn.edu*/
/* 02/05/2023*/

/* ---------------------------------------------- */

/* C Program Begin Libraries */

#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h>
#include<sys/wait.h>
#include <string.h>
#include <stdlib.h>

/* C Program End Libraries */

/* ---------------------------------------------- */

/* Local Libraries for Program Begins */

#include "helper.h"

/* Local Libraries for the Program Ends */

/* ---------------------------------------------- */

/* Local Definitions for the Program Begins */

#define BUFFER_SIZE 25000
#define READ_END	0
#define WRITE_END	1

/* Local Definitions for the Program Ends */

/* ---------------------------------------------- */

/* To read in the files and count the number of words in them, create the Pipes and run them. */

/* The project specification document's source code served as the insight for this idea. */

/* Main Begins */

int main(int argc, char *argv[])
{
    /* Variable for Pipe Begins */

    int int_msg;
    char char_msg[BUFFER_SIZE];
    pid_t pid;
    int fd1[2]; // Pipe 1
    int fd2[2]; // Pipe 2
    
    /* Variable for Pipe Ends */

    /* Variables for Function Begins */

    FILE * file;
    char buffer[BUFFER_SIZE];
    char new_char;
    int count = 0;

    /* Variables for Funtion Ends */

    /* Verifying Errors: */

    /* Verify whether the correct number of command-line arguments was provided. */

    if (argc < 2 || argc > 2)
    {
      /* Print the appropriate error message, then quit. */
      err_msg(0);
      exit(1);
    }

    /* Create the pipes */

    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        fprintf(stderr,"One of the Pipes had a failure.");
        return 1;
    }


    /* Now fork a child process */

    pid = fork();

    /* Fork error message */

    if (pid < 0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }

    /* Parent process Begins */
    /* Read in file, send to child process, and recieve wordcount result using pipes */
    
    if (pid > 0) 
    {
      /* Process 1 which is the parent should read the file. */
      /* Open file */
 
      printf("\nProcess 1 is reading file \"%s\" now ... \n", argv[1]);
      file = fopen(argv[1], "r");

      /* Verify whether the file has successfully opened. */

      if (file == NULL)
      {
        /* Print the proper error message, then quit.*/
        err_msg(1);
        exit(EXIT_FAILURE);
      }

      /* Read file data into a char array. */

      while ((new_char = fgetc(file)) != EOF)
      {
        /* Add char into char array */
        buffer[count] = new_char;
        count++;
      }
      
      /* Close the unused end of the pipes */
      close(fd2[WRITE_END]);
      close(fd1[READ_END]);

      /* The data from the file should now be passed through the pipe by Process 1 (parent to child) */
      /* The write end of the pipe should then be closed since it is no longer in use. */
  
      printf("\nProcess 1 starts sending data to Process 2 ....\n");
      write(fd1[WRITE_END], buffer, BUFFER_SIZE);
    
      close(fd1[WRITE_END]);

      /* Waits for child to end */

      int child_status;
      waitpid(pid, &child_status, 0);

      /* Read the word-count output from pipe 2. */
      /* The read end of the pipe should then be closed since it is no longer in use. */
 
      read(fd2[READ_END], &int_msg, sizeof(int_msg));
      close(fd2[READ_END]);

      printf("\nProcess 1: The total number of words is %d. \n", int_msg);
 
    }

    /* Child process Begins */
    /* Use pipes to receive file information from the parent, count the words, and send the result of the count to the parent. */

    else
    {
      /* Close the unused end of pipe1 write and pipe2 read */
      
      close(fd1[WRITE_END]);
      close(fd2[READ_END]);
 
      /* Read from pipe1, then close the read end of the pipe that will no longer be used. */

      read(fd1[READ_END], char_msg, BUFFER_SIZE);
      close(fd1[READ_END]);

      printf("\nProcess 2 finishes receiving data from Process 1 .....\n");

      /* Count words and write to pipe2 */

      printf("\nProcess 2 is counting words now ...\n");
      int_msg = count_words(char_msg);

      printf("\nProcess 2 is sending the result back to Process 1 ...\n");
      write(fd2[WRITE_END], &int_msg, sizeof(int_msg));
     
      /*Closing the unused end of the pipe */
      
      close(fd2[WRITE_END]);  
    }

    /* Closing the file */
    fclose(file);

    return 0;
}
