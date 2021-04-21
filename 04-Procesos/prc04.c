/*
 * Ejercicio 4 de TP Procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main (){

	pid_t pid;
	int i;

	pid = fork();		
	printf ("Mi pid es %d y el pid de papa es %d. fork() devolvio %d\n", getpid(), getppid(), pid);

	switch(pid)
	{
	case 0: printf("El hijo esta ejecutando un proceso diferente y el PID es %d \n",pid);
	default: printf("El padre esta ejecutando y el PID es %d \n", pid);
	}	
		
	sleep(30); 
	exit(0);
}

/*Se implementa el uso de switch, dado que de esta manera, podemos facilmente diferenciar el caso donde el fork() nos devuelve el valor "0" cuando tenemos el hijo ejecutandose (o diferentes valores si hay errores), y con el "default" podemos reconocer cuando el pid es del hijo sin preocuparnos en saber el valor que toma (ya que cambia cada vez que lo ejecutamos y dificultaria su reconocimiento por valores exactos) */
