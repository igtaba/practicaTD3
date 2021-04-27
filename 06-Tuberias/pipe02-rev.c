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

	int ipc[2], proc; 	//Pipe descriptors var.
	int leido, success;
	char buff[BUFF_SIZE] = {0};

	if (pipe(ipc) == -1)	//If pipe creation gives an error, then
  	{ 
		exit(-1);	//Exit Program
	}
	
	printf ("	ipc[0] = %d ipc[1] =%d \n", ipc[0], ipc[1]);	//Printing the descriptores values
	
	switch (fork()) 	//Creates a child process and given the return value, either write or wait to read if possible from pipe
	{ 
		case 0: 	//This is what the child is going to execute
		close(ipc[0]);	// Here we change the ipc[1] for ipc [0] given that if we want to write, first we should the read side
		strncpy(buff, DATA, sizeof(DATA)); 
		write(ipc[1], buff, sizeof(DATA));	//Here we rightly close the writing side
		exit(0);
		 
		default:	//This is what the father should run
		printf("	Leyendo tuberia... \n");
		sleep(2);	// I added a sleep just to show that a delay between the last message and the info being displayed
		leido = read(ipc[0], buff, sizeof(buff));
		if(leido < 1)
		{
			write (STDOUT_FILENO, "\nError al leer tuberia", sizeof("\nError al leer tuberia"));
	 	}
		else		// The content of the buff is put out through the stdout (terminal screen)
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
