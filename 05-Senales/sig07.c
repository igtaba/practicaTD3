/*
 Ejercicio 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


void manejador(int a)
{
	write(STDOUT_FILENO,"\nMe rehuso a terminar\n",sizeof("\nMe rehuso a terminar\n"));  
}

int main ()
{

   //signal(SIGKILL, SIG_IGN);
   signal(SIGUSR1, manejador);  //Ejecutamos el manejador para SIGUSR1
   
   printf("Proceso PID = %d\n", getpid());   
   
   while(1);
   
   exit(0);
}

/*
	 En este caso la señal SIGUSR1 si es manejable y es ignorada por el proceso cuando es enviada desde otra terminal. En ese caso se imprime por pantalla el mensaje deseado pero el proceso se mantiene corriendo.
	 
*/
