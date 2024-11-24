#include <stdlib.h> //para malloc, realloc y free
#include <stdio.h>

char *buffer;

char *asigna(int numero)
{
    buffer = (char *)malloc(numero * sizeof(char));
    if (buffer == NULL)
    {
        printf("\nNo se pudo asignar la memoria!!\n");
        return NULL;
    }
    return buffer;
}

char *reasigna(int numero)
{
    buffer = (char *)realloc(buffer, numero * sizeof(char));
    if (buffer == NULL)
    {
        printf("\nNo se pudo re-asignar la memoria!!\n");
        return NULL;
    }
    return buffer;
}

void libera()
{
    free(buffer);
}