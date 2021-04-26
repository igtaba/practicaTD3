/*
 * Ejercicio 1 de TP PIPE
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include<sys/wait.h> 


int main (){

   int ipc[2], proc; //El arreglo de 2 posiciones es para usar en el pipe, donde estaran los descriptores
   int leido;
   char buff[80];

   pipe(ipc); // Creamos una tuberia, que si se crea correctamente nos deja los 2 descriptores (read & write) en el arreglo

   printf ("ipc[0] = %d ipc[1] =%d \n ", ipc[0], ipc[1]);   

   proc = fork(); //Al crear el proceso hijo despues de la tuberia, hereda los dos descriptores de la tuberia y por ello, puede usarla

   if (proc == 0 ) //Todo lo que ejecuta el hijo
   { 
      // Se cierra el lado de escritura del hijo
      close(ipc[1]);
      
      leido = read(ipc[0], buff, sizeof(buff)); //lee de la tuberia y lo leido lo guarda en buff, con el tamaño maximo dado por el buff
      
      if(leido < 1)
      {
         write (STDOUT_FILENO, "\nError al leer tuberia", sizeof("\nError al leer tuberia"));
      }
      else 
      {

         // Escribir en la salida estandar de la consola, que es la pantalla
         write (STDOUT_FILENO, "\nLeido de la tuberia: ", sizeof("\nLeido de la tuberia: "));
         write (STDOUT_FILENO, buff, leido-1);
         printf(", por el proceso hijo, pid %d \n", getpid());
      }
      exit(0);
   
   }
   // Se cierra el lado de lectura del padre
   close(ipc[0]);
   
   printf("\nIngrese una cadena de caracteres por consola:\n");
   // Se lee por la entrada estandar de la consola, que es el teclado, y lo guarda en buff
   leido = read(STDIN_FILENO, buff,  sizeof(buff));

   // Se escribe en la tuberia, que lo que estaba guardado en buff
   write(ipc[1], buff, leido);
   
   // Se cierra el lado de escritura. 
   close(ipc[1]);

   wait(NULL); //Espera que el hijo termine   
   write (STDOUT_FILENO, "\nEscrito en la tuberia: ", sizeof("\nEscrito en la tuberia: "));
   write (STDOUT_FILENO, buff, leido-1);
   printf(", por el proceso padre, pid %d \n", getpid());

   exit(0);

}

/* 
	El pipe solo se puede usar en procesos que esten relacionados, porque se debe conocer los descriptores para poder read or write en ellos. Para que 2 procesos conozcan esto, la unica manera es que al creer un proceso herede del padre los valores de estos descriptores.

*/







