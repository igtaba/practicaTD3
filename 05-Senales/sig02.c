/*
 * Ejercicio 2 de TP Señales
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

/*Cuando compilamos y corremos sig02.c pero no dejamos que el programa termine y lo que hacemos es cortar su ejecuccion con ctrl+C, vemos que el exit status esta vez es 130. Este valor es correspondiente para Ctrl+C que ejecuta un SIGKILL sobre el proceso
Si bien los codigos varian, algunos se encuentran con valores reservados para ciertos casos:

#	Meaning 				Comments
1 	Catchall for general errors 		Miscellaneous errors, such as “divide by zero” and other impermissible operations
2 	Misuse of shell builtins 		Missing keyword or command, missing permission problem
126 	Command invoked cannot execute 	Permission problem or command is not an executable
127 	“command not found” 			Possible problem with $PATH or a typo
128 	Invalid argument to exit 		exit takes only integer args in the range 0 – 255 (see first footnote)
128+n 	Fatal error signal “n” 		$? returns 137 (128 + 9)
130 	Script terminated by Control-C 	Control-C is fatal error signal 2, (130 = 128 + 2, see above)
255* 	Exit status out of range 		exit takes only integer args in the range 0 – 255

*/
