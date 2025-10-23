// codigo para clase de programacion segundo semestre ucm
// Hecho por sebastian Saravia Olivares
#include <stdio.h>
void descuentos(int *sueldoBA, int nivelEA);
float retonoBono(int sueldoBA, int nivelEA, float *bonoA);
float retornoSueldoFinalt();
int main()
{

    int sueldoB[7], nivelE[7], bono[7];
    for (int i = 1; i <= 8; i++)
    {

        printf("\ningrese el sueldo base del empleado n%d: ", i);
        scanf("%d", &sueldoB[i]);

        printf("\ningrese el nivel del empleado n%d: ", i);
        scanf("%d", &nivelE[i]);
        descuentos(sueldoB[i], nivelE[i]);
        retornoBono(sueldoB[i], nivelE[i], bono);
    }
    for (int i = 1; i <= 8; i++)
    {
    }
}
void descuentos(int *sueldoBA, int nivelEA)
{
    if (nivelEA == 2 || nivelEA == 3)
    {

        *sueldoBA = *sueldoBA * 0.696;
    }
    else if (nivelEA == 0 || nivelEA == 1)
    {

        *sueldoBA = *sueldoBA * 0.81;
    }
    return sueldoBA;
}
float retornoBono(int sueldoBA, int nivelEA, float *bonoA)
{
    if (nivelEA == 0)
    {
        *bonoA = 7000;
    }
    else if (nivelEA == 1)
    {
        *bonoA = sueldoBA * 0.064;
    }
    else if (nivelEA == 2)
    {
        *bonoA = sueldoBA * 0.1394;
    }
    else if (nivelEA == 2)
    {
        *bonoA = sueldoBA * 0.2104;
    }
}
float retornoSueldoFinal(int)
{   
}
