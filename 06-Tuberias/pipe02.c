/*
 * Ejercicio 2 de TP PIPE
 * 
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h> 

#define DATA "INFORMACION IMPORTANTE"
#define BUFF_SIZE 80

int main (){

	int ipc[2], proc; //Pipe descriptors var.
	int leido, success;
	char buff[BUFF_SIZE] = {0};

	if (pipe(ipc) == -1)	//If pipe creation gives an error, then
  	{ 
		exit(-1);		//Exit Program
	}
	
	switch (fork()) //Creates a child process and given the return value, either write or wait to read if possible from pipe
	{ 
		case 0:
		close(ipc[1]);
		strncpy(buff, DATA, sizeof(DATA)); 
		write(ipc[1], buff, sizeof(DATA));
		exit(0);
		 
		default:
		printf("Leyendo tuberia... \n");
		leido = read(ipc[0], buff, sizeof(buff));
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
		wait(NULL);

		exit(0);
	}
}

/*
	The problem could be that, given that the pipe is created inside an IF, maybe the fork can't have the descriptors values?
*/
