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

   //signal(SIGKILL, SIG_IGN);
   signal(SIGTSTP, SIG_IGN);  //Ctrl + z
   
   printf("Proceso PID = %d\n", getpid());   
   
   while(1);
   
   exit(0);
}

/*
	 Por un lado podemos ver en este caso que al ejecutar ctrl+C y ctrl+Z para terminar el proceso que ejecuta ./sig04, tenemos distintos codigos de exit(status):
			 Ctrl+C -> Exit(Status)=130
			 Ctrl+Z -> Exit(Status)=148
	 Esto se debe a que ctrl+Z no envia una señal para matar el proceso, como ctrl+C que envia un SIGINT, sino que envia una SIGTSTP ($ kill -TSTP $PID_OF_PROCESS) , que en vez de interrumpir el programa, lo suspende, y luego se puede a travez del command: $ kill -CONT $PID_OF_PROCESS
	 
	 Por otro lado, vemos que la señal SIGTSTP por otro lado puede ser ignorada mediante el manejamiento de señal, mientras que el caso donde la señal que queremos ignorar es SIGKILL no podemos.
*/
