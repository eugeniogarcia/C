#include <stdio.h>
#include <string.h> //para strcpy
#include <c_plus_plus.h>

ClaseBase::ClaseBase(const char *nombre, float num)
{
    this->numero = num;
    sprintf(this->donde, "Wir sind Base");
    sprintf(this->nombre, "%s", nombre);
    sprintf(this->alias, "En Base");
}

void ClaseBase::donde_estoy(char *donde)
{
    sprintf(donde, "%s", this->donde);
}

A::A(const char *nombre, float num) : ClaseBase(nombre, num)
{
    sprintf(this->donde, "Wir sind A");
    sprintf(this->alias, "En A");
}

float A::matematica()
{
    return this->numero;
}

char *A::quien()
{
    return this->nombre;
}

B::B(const char *nombre, float num) : A(nombre, num)
{
    sprintf(this->donde, "Wir sind B");
    sprintf(this->alias, "En B");
}

float B::matematica()
{
    return this->numero * 2;
}

C::C(const char *nombre, long num) : B(nombre, num)
{
    sprintf(this->donde, "Wir sind C");
    sprintf(this->alias, "En C");
}

float C::matematica()
{
    return this->numero * 3;
}

void C::donde_estoy(char *donde)
{
    sprintf(donde, "Donde: %s", this->donde);
}

float calcula(ClaseBase *objeto) // solo se puede usar una clase abstracta como puntero
{
    return objeto->matematica();
}

void donde(ClaseBase *objeto, char *donde)
{
    objeto->donde_estoy(donde);
}

char *quien(ClaseBase *objeto)
{
    return objeto->quien();
}