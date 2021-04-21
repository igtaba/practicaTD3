/*
 * Ejercicio 8 de TP Procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid
#include <sys/wait.h>

int main (){

	pid_t pid;
	int i;

	pid = fork();		
	printf ("Mi pid es %d y el pid de papa es %d. fork() devolvio %d\n", getpid(), getppid(), pid);

	switch(pid)
	{
	case 0: 
	{
	printf("El hijo esta ejecutando un proceso diferente y el PID es %d \n",pid);
	sleep(15); 
	printf("\nReference: Termina el sleep ejecutado por el proceso hijo\n");
	}
	default: printf("El padre esta ejecutando y el PID es %d \n", pid);
	wait(NULL);
	}	
		

	exit(0);
}

/*
Lo que podemos ver al analizar como se ejecuta el programa y pstree es que el proceso hijo 
*/
