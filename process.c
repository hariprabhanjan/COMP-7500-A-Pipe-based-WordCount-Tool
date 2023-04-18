
/* 
 * COMP7500, Project 3
 * HariPrabhanjan Lakshminarayana(hzl0151)
 * 03/14/2023
 * This program will be launched in fork_execv (see fork_execv.c).
 * gcc process.c -o process
 */
#include <stdio.h> 
#include <unistd.h>
int main(int argc, char *argv[] )
{
  int waiting;
  sscanf(argv[2], "%u", &waiting);
 // printf("\n%u", waiting);
  sleep(waiting);
//  printf("\n%s", argv[1]);
//  printf(" finished\n");
  return 0;
}
