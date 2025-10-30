#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10
const int ejex[4] = {-1, 1, 0, 0},
          ejey[4] = {0, 0, -1, 1};

void mostrarLaberinto(char laberinto[FILAS][COLUMNAS]);
int calcularRutas2(char laberinto[FILAS][COLUMNAS], int, int);
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

  calcularRutas2(laberinto, 0, 0);
  mostrarLaberinto(laberinto);
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
    printf("\n\n\n");
}
int calcularRutas2(char laberinto[FILAS][COLUMNAS], int i, int j){
     // Si está fuera de los límites
    if (i < 0 || j < 0 || i >= FILAS || j >= COLUMNAS)
        return 0;

    // Si es una pared o ya visitado
    if (laberinto[i][j] == '#' || laberinto[i][j] == 'X')
        return 0;

    // Si encontramos la meta
    if (laberinto[i][j] == 'B') {
        printf("Camino encontrado!\n");
        return 1;
    }

    // Marcar la posición actual
    if (laberinto[i][j] != 'A')
        laberinto[i][j] = 'X';
    // Probar las 4 direcciones
    for (int k = 0; k < 4; k++) {
        int nuevoX = i + ejex[k];
        int nuevoY = j + ejey[k];

        if(calcularRutas2(laberinto, nuevoX, nuevoY))
            return 1; // Si encontramos un camino, salimos
    }

    // Retroceder (backtracking)
    if (laberinto[i][j] != 'A')
        laberinto[i][j] = ' ';
    return 0;

}
