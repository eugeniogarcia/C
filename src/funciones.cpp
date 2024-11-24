float suma(float a, float b)
{
    return a + b;
}

void inicia(int *ptr, int largo, int valor)
{
    for (int j = 0; j < largo; j++)
    {
        *ptr = valor; // escribe en la memoria el valor
        ptr++;        // se mueve a la siguiente posición de memoria
    }
}

void por_valor(float valor)
{
    valor = (valor) * 2;
}

void por_puntero(float *valor)
{
    *valor = (*valor) * 2;
}
