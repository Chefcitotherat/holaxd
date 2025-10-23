#include <stdio.h>
const int ejex[8] = {-1, -2, -2, -1, 1, 2, 2, 1},
          ejey[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int preguntar_coordenadas(int *, int *);
int movimientos_posibles(int[8][8], int, int *);
int main()
{
    int tablero[8][8];
    int i, j, q;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            tablero[i][j] = 0;
    preguntar_coordenadas(&i, &j);
    return 0;
}
int preguntar_coordenadas(int *i, int *j)
{
    int a, b;
    printf("introducir coordenadas (no deben de ser mayores a 8 ni menores a 1)\n");
    printf("\n introduzca la coordenada horizontal: ");
    scanf("%d", &a);
    printf("\n introduzca la coordenada vertical: ");
    scanf("%d", &b);
    if (a > 8 || b > 8 || a < 1 || b < 1)
    {
        printf("alguna de las coordenadas ingresadas es mayor a 8 o menor a 1.");
    }
    else
        *i = a - 1;
        *j = b - 1;
}