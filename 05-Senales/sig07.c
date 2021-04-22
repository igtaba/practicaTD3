/*
 Ejercicio 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handler_sigchild(int x)
{
	write(STDOUT_FILENO, "\nChild Ended\n",sizeof("\nChild Ended\n"));
}

int main ()
{
	pid_t aux1, aux2, aux3;
	pid_t PIDson1, PIDson2, PIDson3; //I CANNOT USE THE PID's TO END THE PROCESS IN THE FATHER COZ THEY'RE NOT IN THE FATHER (have rubbish value), THEY ASSUME THE PID VALUE ONLY IN THE SON MEMORY 
	
	signal(SIGCHLD, handler_sigchild);
   
  	printf("Proceso PID = %d\n", getpid());   
   
   	aux1 = fork(); // Creation of 1st Son
   	
   	if(aux1 == 0) //Code that Son 1 is going to execute
   	{
   		PIDson1 = getpid();
   		printf("sSon 1 has PID = %d\n", PIDson1);
   		while (1);
   	}
   	else 
   	{
	   	aux2 = fork();  // Creation of 2nd Son
	   	
	   	if(aux2 == 0) //Code that Son 2 is going to execute
	   	{
	   		PIDson2 = getpid();
	   		printf("Son 2 has PID = %d\n", PIDson2);
	   		while (1);
	   	}
   		else
   		{
		   	aux3 = fork();  // Creation of 3rd Son
		   	
		   	if(aux3 == 0) //Code that Son 3 is going to execute
		   	{
		   		PIDson3 = getpid();
		   		printf("Son 3 has PID = %d\n", PIDson3);
		   		while (1);
		   	}
			else //Code that the Father is going to execute
			{
		   		sleep(2);

				kill(aux1, SIGKILL);
				   	
			   	sleep(2);
				   	
				kill(aux2, SIGKILL);
				
				sleep(2);
				   	
				kill(aux3, SIGKILL);
				   	
		   	}

		}

	}
  	while(1);
   
  	exit(0);
}


/*
	
	 
*/
