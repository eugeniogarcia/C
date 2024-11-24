#include <stdio.h>
#include <tipos.h>
#include <funciones.h>

// el orden es importante. Se procesan las cosas de arriba a abajo
// declara una variable entera constante
const int LEN = 10;

// esto es un array float de LEN elementos que inicializamos con una lista de valores
float X_values[LEN] = {3.1, 3.2, 4.0, 1.0, 3.0, 5.0, -7.0, -8.0, 9.0, 1.0};
float Y_values[LEN] = {-0.2, 3.5, 7.8, -2, 2.3, 3.0, 3.2, 4.0, 1.0, -3.0};

// esto es un array int
int array_input[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int array_output[LEN] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

char texto[100];

struct Point
{
    float X_coord;
    float Y_coord;
};
Point array_point[LEN];

struct Point mean_point;

void function(int *a, int b);

void setup1()
{
    int i;
    // put your setup code here, to run once:
    for (i = 0; i < 10; i++)
    {
        array_point[i].X_coord = X_values[i];
        array_point[i].Y_coord = Y_values[i];
    }
}

void loop1()
{
    int *pc, c;

    c = 22;
    sprintf(texto, "Address of c: %p\n", &c);

    sprintf(texto, "Value of c: %d\n\n", c); // 22

    pc = &c;
    sprintf(texto, "Address of pointer pc: %p\n", pc);

    sprintf(texto, "Content of pointer pc: %d\n\n", *pc); // 22

    c = 11;
    sprintf(texto, "Address of pointer pc: %p\n", pc);

    sprintf(texto, "Content of pointer pc: %d\n\n", *pc); // 11

    *pc = 2;
    sprintf(texto, "Address of c: %p\n", &c);

    sprintf(texto, "Value of c: %d\n\n", c); // 2
}

void loop2()
{
    int *pa, a, b;
    a = 3;
    b = 2;
    pa = &a;
    function(pa, b);
    sprintf(texto, "a=%d b=%d", a, b);
}

void function(int *a, int b)
{
    *a = b + 5;
    b = 0;
}

void loop3()
{
    int *p_ini, *p_end;
    int i;
    p_ini = array_input;
    p_end = array_output + 9;
    for (i = 0; i < 10; i++)
    {
        *p_end = *p_ini;
        p_ini++;
        p_end--;
    }
}

void loop4()
{
    // put your main code here, to run repeatedly:
    Point *p_struct;
    Point mean_point;

    int i;
    mean_point.X_coord = 0;
    mean_point.Y_coord = 0;
    p_struct = &(array_point[0]); // same to p_struct = array_point
    for (i = 0; i < 10; i++)
    {
        mean_point.X_coord += p_struct->X_coord;
        mean_point.Y_coord += p_struct->Y_coord;
        p_struct++;
    }
    mean_point.X_coord /= LEN;
    mean_point.Y_coord /= LEN;
}

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

    printf("\nAdios!!!\n\n");
    return 0;
}
