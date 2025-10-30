#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10

int c;
const int ejex[4] = {0, 0, 1, -1},
          ejey[4] = {-1, 1, 0, 0};



void mostrarLaberinto(char laberinto[FILAS][COLUMNAS]);
void recorrerLaberinto(char laberinto[FILAS][COLUMNAS], int filaActual, int columnaActual);

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
    recorrerLaberinto(laberinto, 0, 0);
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


void recorrerLaberinto(char laberinto[FILAS][COLUMNAS], int filaActual, int columnaActual){
    if (laberinto[filaActual + 1][columnaActual] == 'B'){
        laberinto[FILAS - 2][COLUMNAS - 1] = 'A';
       printf("encontrado\n");
       return;
    }
    laberinto[filaActual][columnaActual] = 'A';
    mostrarLaberinto(laberinto);

    laberinto[filaActual][columnaActual] = 'X';
    if((filaActual + 1) < FILAS && laberinto[filaActual + 1][columnaActual] == ' '){
        recorrerLaberinto(laberinto, filaActual + 1, columnaActual);
        return;
    }
    if((filaActual - 1) >= 0 && laberinto[filaActual - 1][columnaActual] == ' '){
        recorrerLaberinto(laberinto, filaActual - 1, columnaActual);
        return;
    }
    if((columnaActual + 1) < COLUMNAS && laberinto[filaActual][columnaActual + 1] == ' '){
        recorrerLaberinto(laberinto, filaActual, columnaActual + 1);
        return;
    }
    if((columnaActual - 1) >= 0 && laberinto[filaActual][columnaActual - 1] == ' '){
        recorrerLaberinto(laberinto, filaActual, columnaActual - 1);
        return;
    }

    laberinto[filaActual][columnaActual] = 'R';
    if((filaActual + 1) < FILAS && laberinto[filaActual + 1][columnaActual] == 'X'){
        recorrerLaberinto(laberinto, filaActual + 1, columnaActual);
        return;
    }
    if((filaActual - 1) >= 0 && laberinto[filaActual - 1][columnaActual] == 'X'){
        recorrerLaberinto(laberinto, filaActual - 1, columnaActual);
        return;
    }
    if((columnaActual + 1) < COLUMNAS && laberinto[filaActual][columnaActual + 1] == 'X'){
        recorrerLaberinto(laberinto, filaActual, columnaActual + 1);
        return;
    }
    if((columnaActual - 1) >= 0 && laberinto[filaActual][columnaActual - 1] == 'X'){
        recorrerLaberinto(laberinto, filaActual, columnaActual - 1);
        return;
    }

    return;
}