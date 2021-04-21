/*
 * Ejercicio 6 de TP Procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>    // Define pid_t
#include <unistd.h>       // Define fork, getpid y getppid

int main ()
{
	int x = 100;
	
	printf("Soy el proceso: %d y el valor de x es: %d\n ",getpid(),x);
	
	switch (fork())
	{
		case -1:   // No pudo crear el proceso
			printf ("Error. No se crea proceso hijo");
			break;

		case 0:   //proceso hijo
			printf ("Soy el proceso hijo, pid: %d , x = %d \nLa ubicacion en memoria es %p \n", getpid(), --x, (void*)&x);
			break;

		default:  //proceso padre
			printf ("Soy el proceso padre, pid: %d , x = %d\nLa ubicacion de memoria es %p \n", getpid(), ++x, (void*)&x);
	}
    exit(0);

}

/* 

*/
