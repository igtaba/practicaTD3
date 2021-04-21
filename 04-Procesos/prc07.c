/*
 * Ejercicio 7 de TP Procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main (){

	pid_t pid;
	int i=0;


	for(i; i<5; i++)
	{
		
	printf ("El ciclo del bucle for actual corresponde a i=%d.\n", i);

	pid = fork();		
	printf ("Mi pid es %d y el pid de papa es %d. fork() devolvio %d\n", getpid(), getppid(), pid);
	
	}
		
	sleep(5); 

	exit(0);

}
