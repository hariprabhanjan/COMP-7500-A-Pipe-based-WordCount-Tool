# COMP-7500-A-Pipe-based-WordCount-Tool

A Pipe-based Word Count Tool
COMP 7500Advanced Operating Systems
Hari Prabhanjan Lakshminarayana

________________________________________
	Overview

This project aims to create a system that uses Unix Pipes to communicate between two processes in order to produce the desired output. Using a C program as a base, two processes are created, with the parent process reading the When running the program, an input file is passed in the argument line, and the child process receives its contents via Unix Pipes. The child process then reads the piped input and uses the word count function to calculate the number of words. Now the child process sends the data back to the parent process using a different pipe, including the word count. Following receipt from the child process, the parent process is then in charge of printing the word count.

1)	Step 1: Creating A Child Process in A Parent Process
This project's first step was to figure out how to create two cooperating processes. So, using the fork() system call, I created two cooperating processes: a parent process and a child process. If fork() is positive, the parent process is returned, and if fork() is zero, the child process is called. If fork() is negative, the pipe creation will fail.

2)	Step 2: Create Unix Pipes
The pipe (int fd[]) function, which creates a pipe that is accessible through the fd[] file descriptor, was used in this step to build two pipes in following the instructions provided in the project description. Assume that the read-end and write-end of the pipe are fd[0] and f[1], respectively. The read() and write() system calls can be used to access that newly created pipe. Like files, the write-end and read-end of pipes must be closed when not in use.
 
3)	Step 3: Loading an Input File
The parent process's responsibility is to read an input file and send data to the child process. In this step, I implemented the parent process, which can successfully load the file and deliver data to process 2, also known as the child process.

   
Following that, the child process calls the wordcount function after receiving the data written to the pipe via the read() system call. Helper. C contains the function's definition. The wordcount function gives the total amount of words. The child process uses the write() system call to send the output to pipe2.
 













4)	Step 4: Counting Words
In this step, we're supposed to implement a wordcount function. In the file helper, I've added a wordcount function. C
 

5)	Step 5: Integrating the wordcount Function.
The main purpose of this step was to connect the wordcount function to two pipes. So, the first pipe provides the input to the wordcount function and the output of the wordcount function feeds the second pipe.

6)	Step 6: Testing
After all the components had been integrated into the program, testing was carried out.
The following image shows the program's output.

 

I considered a file “input.txt”, which contains the following text – 
“This is the second project of COMP7500 class.”
Errors:
 

 
 
 
 

I have attached the script file for this project in the Project2 folder.




DFD
 


 Conclusion
The application pwordcount will take a file as input from command line argument. Using Unix Pipes two process communicate between each other, the parent process reads the file and sends the content to child process, while child process performs word count and returns the value to parent, finally parent process prints the word count.
