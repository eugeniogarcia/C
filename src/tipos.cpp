#include <stdio.h>

void tipos()
{
    printf("\nTipos\n");

    short v_short = 10;
    int v_int = 10;
    long v_long = 10;
    printf("Espacio ocupado por enteros\n sort: %lu, int:%lu, y long: %lu\n", sizeof(v_short), sizeof(v_int), sizeof(v_long));

    unsigned short v_ushort = 10;
    unsigned int v_uint = 10;
    unsigned long v_ulong = 10;
    printf("Los enteros sin signo ocupan lo mismo\n unsingned short: %lu, unsingned int: %lu y unsingned short: %lu\n", sizeof(v_ushort), sizeof(v_uint), sizeof(v_ulong));

    char v_char = 'e';
    // estos son arrays
    char v_texto1[] = "hola como estas";
    char v_texto2[20] = "hola como estas";
    printf("Espacio ocupado por chars\n char: %lu, char[]: %lu y char[20]: %lu\n", sizeof(v_char), sizeof(v_texto1), sizeof(v_texto2));

    float v_float = 0.0;
    double v_double = 0.0;
    long double v_ldouble = 0.0;
    printf("Espacio ocupado por decimales\n float: %lu, double: %lu y long double: %lu\n", sizeof(v_float), sizeof(v_double), sizeof(v_ldouble));

    bool v_boleana = true;
    printf("Espacio ocupado por buleano\n bool: %lu\n", sizeof(v_boleana));

    //constante
    const float pi=3.141516;
}

void cast()
{
    printf("\nCast\n");

    // cast es la conversión de un tipo a otro
    char car = 'a';
    short i1 = car;
    int i2 = car;
    long i3 = car;
    unsigned short u1 = car;
    unsigned int u2 = car;
    unsigned long u3 = car;

    printf("valores:\n%c\t%hd\t%d\t%ld\t%hu\t%u\t%lu\n", car, i1, i2, i3, u1, u2, u3);
    // ver warnings al compilar. El casteo de long a c
    printf("casteo implicito:\n%c\t%c\t%c\t%c\t%c\n", car, i1, i2, u1, u2);
    printf("distintos formatos:\ndecimal: %d\toctal: %o\thexadecimal: %x\n", i1, i1, i1);
}

void tipos_arrays()
{
    printf("\nArrays\n");

    // como estamos pasando la lista de valores, el compilador ya sabe el tamaño del array, no hace falta indicarselo
    // inicializa con una lista
    float valores[] = {0, 1.1, 2.2, 3.3, 4.4};
    // reserva espacio, con el valor por defecto de float
    float valores1[10];
    // reserva espacio, con el valor por defecto de float en todos los elementos, menos el primero que vale 2.2
    float valores2[10] = {2.2};

    // tamaño del array
    int espacio_ocupado = sizeof(valores);
    int espacio_elto = sizeof(valores[0]);
    int tamano = espacio_ocupado / espacio_elto;

    printf("Espacio ocupado por el array: %d\nEspacio ocupado por un elemento del array: %d\nNumero de elementos del array: %d\n", espacio_ocupado, espacio_elto, tamano);

    // en los arrays podemos hacer un foreach
    printf("\nun foreach:\n");
    for (float a : valores)
    {
        printf("%f\t", a);
    }

    // podemos hacer un loop
    printf("\nun for:\n");
    for (int i = 0; i < tamano; i++)
    {
        printf("%f\t", valores[i]);
    }

    // un while
    printf("\nun while:\n");
    int i = 0;
    while (i < tamano)
    {
        printf("%f\t", valores[i]);
        i++;
    };

    // un do while
    printf("\nun do while:\n");
    i = 0;
    do
    {
        printf("%f\t", valores[i]);
        i++;
    } while (i < tamano);

    // podemos acceder a cualquier elemento del array
    valores[0] = valores[4] * 2;
}

void punteros()
{
    printf("\nPunteros\n");
    int valores[5];
    int *p_int;

    // inicializamos el array
    for (int i = 4; i >= 0; i--)
        valores[i] = i;

    printf("\nContenido del array\n");
    for (int v : valores)
        printf(" %d ", v);

    p_int = valores;
    *p_int = 44;
    p_int++;
    *p_int = 88;

    printf("\nContenido del array\n");
    for (int v : valores)
        printf(" %d ", v);

    p_int = &valores[4];
    *p_int = 11;
    p_int--;
    *p_int = 33;

    printf("\nContenido del array\n");
    for (int v : valores)
        printf(" %d ", v);

    int valor = 100;
    p_int = &valor;
    *p_int = *p_int / 2;
    printf("\nEl puntero apunta a: %p y su valor es %d. El entero vale %d\n", p_int, *p_int, valor);

    // referencias. Al declararla es obligatorio referenciar a algo
    int &ref = valor;

    printf("\nReferencia\n");
    printf("%d\t", valor);
    ref *= 2;
    printf("%d\n", valor);

    ref = valores[3]; // cambiar el valor de la referencia (contenido)
    printf("%d\t%d\t%d\n", valores[3], ref, valor);
    valores[3] *= 2; // esto no tiene que ver con la referencia
    printf("%d\t%d\t%d\n", valores[3], ref, valor);

    printf("\nNo cambia el array:");
    // foreach con referencia
    for (int a : valores)
        a = 1;
    for (int v : valores)
        printf(" %d ", v);

    printf("\nUsamos la referencia, cambia el array:");
    for (int &a : valores)
        a = 1;
    for (int v : valores)
        printf(" %d ", v);
}
