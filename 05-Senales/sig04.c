/*
 * Ejercicio 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

/*
void manejador_senial(int a){
   
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
	 Lo que sucede al tener el programa corriendo y ejecutar desde otra consola kill -SIGKILL PID es que el proceso es terminado desde la otra terminal por dicho comando. El exit(status) que devuelve luego de dicha señal de interrupcion es 137
	 Esto nos demuestra que la señal SIGKILL (or SIGSTOP) cannot be ignored!
*/
