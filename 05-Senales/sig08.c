/*
 Ejercicio 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handler_sigchild(int x)
{
	//write(STDOUT_FILENO, "\nChild Ended\n",sizeof("\nChild Ended\n"));
}

int main ()
{
	pid_t aux1, aux2, aux3;
	
	//signal(SIGCHLD, handler_sigchild);
	
	aux1 = fork(); // Creation of 1st Son
   	
   	if(aux1 == 0) //Code that Son 1 is going to execute
   	{
   		printf("Son 1 has PID = %d\n", getpid());
   		
   		sleep(2);
   		
   		exit(0);
   	}
   	
   	printf("Entering the 10s sleep in father's else\n");
	
	sleep(10);
	
	//while(1);
   
  	exit(0);
}


/*
	A)
	
	 
*/
