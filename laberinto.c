#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10
int c;
    const int ejex[4] = {1, 1, -1, -1},
              ejey[4] = {-1, 1, -1, 1};
void mostrarLaberinto(char laberinto[FILAS][COLUMNAS]);
void calcularRutas(int ejeX, int ejeY, char laberinto[FILAS][COLUMNAS], int *);
int main(){
    int q;
    char laberinto[FILAS][COLUMNAS] = {
        {'A', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' '},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', ' ', '#', '#', '#', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' '},
        {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' '},
        {' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'B'}};
    printf("----- BUSCANDO EL CAMINO DEL LABERINTO RECURSIVO ---\n");
    printf("Buscando el camino desde A hasta B \n");

    calcularRutas(0, 0, laberinto, &q);
        mostrarLaberinto(laberinto);
        printf("Cantidad de movimientos realizados: %d\n", c);
    return 0;
}
void mostrarLaberinto(char laberinto[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%c ", laberinto[i][j]);
        }
        printf("\n");
    }
}
void calcularRutas(int ejeX, int ejeY, char laberinto[FILAS][COLUMNAS], int *q)
{
    c++;
    int k, u, v;
    k = 0;
    *q = 0;
    do
    {
        u = ejeX + ejex[k];
        v = ejeY + ejey[k]; /* seleccionar candidato */
        if (u >= 0 && u < FILAS && v >= 0 && v < COLUMNAS)
        { /* esta dentro de los limites? */
            if (laberinto[u][v] == ' ')
            {                      /* es valido? */
                laberinto[u][v] = 'X'; /* anota el candidato */
                if (u != FILAS - 1 || v != COLUMNAS - 1)
                { /* llega al final del recorrido? */
                    calcularRutas(u, v, laberinto, q);
                    if (!*q)
                        laberinto[u][v] = ' '; /* borra el candidato */
                }
                else
                    *q = 1; /* hay solucion */
            }
        }
        printf("Intento en la posicion (%d, %d)\n", u, v);
        k++;
    } while (!*q && k < 8);
}