#include <stdio.h>
#include <string.h>

#define M 5

int main() {
    char * Buff = (char *) malloc(100*sizeof(char));
    char ** nombres = (char **) malloc(100*sizeof(char *));

    int i;
    printf("Ingrese 5 nombres:\n");
    for(i = 0; i < M; i++) {
        gets(Buff);
        nombres[i] = (char *) malloc((strlen(Buff) + 1) * sizeof(char));
        strcpy(nombres[i], Buff);
    }

    for(i = 0; i < M; i++) {
        printf("\nNombre %d: %s\n", i + 1, nombres[i]);
    }

    free(Buff);
    free(i); //No se si debería hacer free por cada variable que tenga

    return 0;
}