/*
 * Ejercicio 3 de TP PIPE
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h> 

#define FRASE_A "AINFORMACION IMPORTANTE"
#define FRASE_B "BINFORMACION IMPORTANTE"
#define BUFF_SIZE 80

void pipe_sign_handler(int a)			// Handler declaration
{
	write (STDOUT_FILENO, "\n Problema con pipeline.\n ", sizeof("\n Problema con pipeline.\n"));
}

int main ()
{
	int ipc[2], proc;
	int leido, success;
	char buff[BUFF_SIZE] = {0};

	signal(SIGPIPE, pipe_sign_handler);	// Handler call
	   					
	pipe(ipc);				// Pipe creation

	switch (fork())			// Process creation and switch #1
	{

		case 0:			// What the Son #1 is going to execute
		close(ipc[0]);			// Closes the lecture side
		strncpy(buff, FRASE_A, sizeof(FRASE_A));	// Copies the string A
		write(ipc[1], buff, sizeof(FRASE_A));		// Writes the string A in the pipe
		exit(0);
		break;
      
		default:			// What the father is going to run
		switch (fork())		// Process creation and switch #2
		{ 
			case 0:		// What the Son #2 is going to execute
			close(ipc[0]);		// Closes the lecture side
			strncpy(buff, FRASE_B, sizeof(FRASE_B));	// Copies the string B
			write(ipc[1], buff,    sizeof(FRASE_B));	// Writes the string A in the pipe
			exit(0);      
        		break;
			
			default:		// What the father is going to run
			close(ipc[1]);		// Closes the writing side
			int i;
			for(i=0; i<2; i++)
			{
				leido = read(ipc[0], buff, sizeof(buff));	//Reads from the pipe and puts it in the buff
				if(leido < 1)
				{
				write (STDOUT_FILENO, "\nError al leer tuberia", sizeof("\nError al leer tuberia"));
				}
				else 
				{
				write (STDOUT_FILENO, "Leido de la tuberia ", sizeof("\nLeido de la tuberia"));
				write (STDOUT_FILENO, buff, leido-1);
				printf(", por el proceso padre, pid %d \n", getpid());
               		}
            		}

		close(ipc[0]);
		wait(NULL);
		wait(NULL);
		exit(0);
		break;
 		}
	}   
}
