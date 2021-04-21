/*
 * Ejercicio 5 de TP Procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main ()
{
	int x = 100;
	int i = 1;
	
	printf("Soy el proceso: %d y el valor de x es: %d\n ",getpid(),x);
	
	switch (fork())
	{
		case -1:   // No pudo crear el proceso
			printf ("Error. No se crea proceso hijo");
			break;

		case 0:   //proceso hijo
			printf ("Soy el proceso hijo, pid: %d , x = %d \n", getpid(), --x);
			break;

		default:  //proceso padre
			printf ("Soy el proceso padre, pid: %d , x = %d\n", getpid(), ++x);
			while(i=1)
			{
			printf(".\n");
			}
			
	}
    exit(0);

}

/*
Stops with ^C (Ctrl+C).

*/
