/*
 Ejercicio 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

/*
void manejador_senial(int a){
   
   write(STDOUT_FILENO,"\nMe rehuso a terminar\n",sizeof("\nMe rehuso a
terminar\n"));
}
*/
int main ()
{

   signal(SIGKILL, SIG_IGN);
   //signal(SIGTSTP, SIG_IGN);  //Ctrl + z
   
   printf("Proceso PID = %d\n", getpid());   
   
   while(1);

   
   exit(0);
}

/*
	 En este caso no tiene sentido la implementacion de un manejador para la señal SIGKILL porque como ya sabemos previamente no se puede ignorar o bloquear a esta señal. El efecto del manejador sera obviado y la señal terminara con el programa
	 
*/
