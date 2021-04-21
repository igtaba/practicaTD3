/*
 * Ejercicio 1 de TP Señales
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


int main ()
{

   sleep(5);
   
   exit(5);
}

/*Cuando compilamos y corremos sig01.c vemos que el exit status al terminar de correr el programa es 127
From gnu.org:
	If a command is not found, the child process created to execute it returns a status of 127. If a command is found but is not executable, the return status is 126. 
*/
