#include <stdio.h>
#include <tipos.h>
#include <funciones.h>
#include <estructuras.h>
#include <memoria.h>
#include <c_plus_plus.h>

int main(int argc, char const *argv[])
{
    tipos();
    cast();
    tipos_arrays();
    punteros();

    printf("\n\nFunciones\n");
    float a = 2, b = 4, c;
    c = suma(a, b);
    printf("\nSuma de %f y %f es %f\n", a, b, c);
    int valores[5];
    inicia(valores, 5, 33);

    por_valor(c);
    printf("Tras llamar a funcion: %f\n", c);
    por_puntero(&c);
    printf("Tras llamar a funcion (pasando puntero): %f\n", c);

    printf("\n\nEstructuras\n");
    Punto coord_media = estructuras();
    imprime(coord_media);
    printf("Pasamos un puntero; Debe cambiar el valor\n");
    add(&coord_media, 1.5, 0.5);
    imprime(coord_media);
    printf("Pasamos un valor; NO Debe cambiar el valor\n");
    add(coord_media, 1.5, 0.5);
    imprime(coord_media);
    printf("Pasamos un valor; NO Debe cambiar el valor\n");
    Punto punto1 = add1(coord_media, 1.5, 0.5);
    imprime(coord_media);
    printf("Pasamos un valor; NO Debe cambiar el valor\n");
    Punto punto2 = add2(coord_media, 1.5, 0.5);
    imprime(coord_media);
    printf("Los valores que hemos obtenido si deben ser diferentes\n");
    imprime(punto1);
    imprime(punto2);

    printf("\n\nmemoria\n");

    int tam = 10;

    char *buf_base = asigna(tam + 1); // reservamos una posición para el caracter de fin
    char *buf = buf_base;
    for (int i = 0; i < tam; i++)
    {
        *buf = i + 97; // el ascii 97 es la letra a
        buf++;
    }
    *buf = '\0'; // fin de cadena

    printf("\nEl contenido del buffer es: %s\n", buf_base);
    buf_base = reasigna(tam + 11);
    for (int i = tam; i < (tam + 11); i++)
    {
        *buf = i + 97; // el ascii 97 es la letra a
        buf++;
    }
    *buf = '\0'; // fin de cadena

    printf("\nEl contenido del buffer es: %s\n", buf_base);

    printf("\nAdios!!!\n\n");
    return 0;
}
