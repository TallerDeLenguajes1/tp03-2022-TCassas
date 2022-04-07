#include <stdio.h>
#include <stdlib.h>

int main() {
    //Linea donde se realiza la reserva de memoria
    char *Buff;
    Buff= (char *) malloc(100*sizeof(char));

    //Ejemplo con int
    int *Numeros;
    Numeros = (int *) malloc(50 * sizeof(int));
    
    printf ("Ingrese una frase\n");
    gets(Buff);
    printf ("%s\n", Buff) ; //forma 1 de escribir
    puts (Buff);            //forma 2 de escribir
    
    free(Buff);
    free(Numeros);

    return 0;
}