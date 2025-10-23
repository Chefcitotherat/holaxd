#include <stdio.h>
int preguntar_coordenadas(int *, int *);
int movimientos_posibles(int, int, int [8][8]);
int mostrar_tablero(int[8][8]);
int main()
{
    int tablero[8][8];
    int i, j;
    for (int m = 0; m < 8; m++)
        for (int n = 0; n < 8; n++)
            tablero[m][n] = 0;
    preguntar_coordenadas(&i, &j);
    movimientos_posibles(i, j, tablero);
    mostrar_tablero(tablero);
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
int movimientos_posibles(int i, int j, int tablero[8][8])
{
    int k, u, v;
    //
    const int ejex[8] = {-1, -2, -2, -1, 1, 2, 2, 1},
              ejey[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    /* inicializa el tablero a cero */
    for (int m = 0; m < 8; m++)
        for (int n = 0; n < 8; n++)
            tablero[m][n] = 0;
    tablero[i][j] = 1; // pone la posicion inicial del caballo
    k = 0;
    printf("los posibles movimientos del caballo son:\n");
    do
    {
        u = i + ejex[k];
        v = j + ejey[k]; /* seleccionar candidato */
        if (u >= 0 && u < 8 && v >= 0 && v < 8)
        { /* esta dentro de los limites? */
            if (tablero[u][v] == 0)
            {                      /* es valido? */
                tablero[u][v] = 1; /* anota el candidato */
                printf("(%d,%d)\n", u + 1, v + 1);
                tablero[u][v] = 0; /* borra el candidato */
            }
        }
        k++;
    } while (k < 8);
}
int mostrar_tablero(int tablero[8][8])
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            printf("[%3d] ", tablero[i][j]);
        putchar('\n');
    }
}