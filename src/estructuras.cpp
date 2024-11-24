#include <stdio.h>
#include <estructuras.h>
const int tamano = 5;

float X_values[tamano] = {3.1, 3.2, 4.0, 1.0, 3.0};
float Y_values[tamano] = {-0.2, 3.5, 7.8, -2, 2.3};

Punto array_point[tamano];

Punto estructuras()
{
    Punto mean_point;
    float x = 0, y = 0; // incializamos al tiempo que declararamos las variables

    for (int i = 0; i < tamano; i++)
    {
        array_point[i].X_coord = X_values[i];
        x += X_values[i];
        array_point[i].Y_coord = Y_values[i];
        y += Y_values[i];
    }
    mean_point.X_coord = x / tamano;
    mean_point.Y_coord = y / tamano;
    return mean_point;
}

void add(Punto *punto, float x, float y)
{
    punto->X_coord = (punto->X_coord + x) / 2;
    punto->Y_coord = (punto->Y_coord + y) / 2;
}

void add(Punto punto, float x, float y)
{
    punto.X_coord = (punto.X_coord + x) / 2;
    punto.Y_coord = (punto.Y_coord + y) / 2;
}

Punto add1(Punto punto, float x, float y)
{
    Punto val;
    val.X_coord = (punto.X_coord + x) / 2;
    val.Y_coord = (punto.Y_coord + y) / 2;
    return val;
}

Punto add2(Punto punto, float x, float y)
{
    return {(punto.X_coord + x) / 2, (punto.Y_coord + y) / 2};
}

void imprime(Punto coord_media)
{
    char texto[50];
    sprintf(texto, "El punto esta en (%f,%f)", coord_media.X_coord, coord_media.Y_coord);
    printf("%s\n", texto);
}