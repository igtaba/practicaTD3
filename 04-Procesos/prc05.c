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
	}
    exit(0);

}

/* El motivo por el cual la variable X no retorna al valor 0, es que no estamos viendo la misma variable X en pantalla cuando se ejecuta cada case del switch. Lo que sucede es lo siguiente: cuando se ejecuta el programa se crea una variable x=100, pero cuando se ejecuta el fork() se copia toda la informacion (del programa para que sea corrido) en otra alocacion de memoria y este proceso hijo pasaria a tener otra variable x=100 alocada en otro espacion de memoria. Cuando el programa padre corre el switch con un valor que ejecura la opcion default del switch, se incrementa la variable X original y se muestra en pantalla como 101. Pero cuando se ejecuta el hijo, la variable que se decrementa y muestra en pantalla es la ubicada en la nueva aloccion de memoria, por lo tanto esta se disminuye a 99 de 100
*/
