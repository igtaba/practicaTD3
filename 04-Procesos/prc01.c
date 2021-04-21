/*
 * Ejercicio 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main ()
{
	
	printf ("Mi pid es %d y el pid de papa es %d\n", getpid(),getppid());

	exit(0);   
}

/*
El PID es el ID del proceso (del ingles Process Indentificator - Identificador de procesos). Es PID es un numero entero usado por el kernel de un OS para identificar el proceso de forma univoca

El PID del padre siempre es menor en valor respecto al del hijo, ya que uno se crea primero que el otro.
*/
