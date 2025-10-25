// codigo creado por Sebastián Saravia 2do semestre IECI
#include <stdio.h>
#define tamano_arr 5
typedef struct guardar_direcciones
{
    int casilla;
    int coordenada_x;
    int coordenada_y;
} guardar_direcciones;
int leer_archivo(int arr[tamano_arr][tamano_arr]);
int encontrar_puntos(int silla[tamano_arr], int arr[tamano_arr][tamano_arr]);
int main()
{
guardar_direcciones silla[tamano_arr];
    int arr[tamano_arr][tamano_arr];
    leer_archivo(arr);
    encontrar_puntos(silla, arr);
}
int leer_archivo(int arr[tamano_arr][tamano_arr])
{
    FILE *puntero_archivo;
    puntero_archivo = fopen("pruebac.txt", "r");

    for (int i = 0; i < tamano_arr; i++)
    {
        for (int j = 0; j < tamano_arr; j++)
        {
            fscanf(puntero_archivo, "%d ", &arr[i][j]);
        }
    }
    fclose(puntero_archivo);
}
int encontrar_puntos(int silla[], int arr[tamano_arr][tamano_arr])
{
    int encontrar = 0;
    for (int i = 0; i < tamano_arr; i++)
    {
        for (int j = 0; j < tamano_arr; j++)
        {
            if (arr[i][j] < arr[i][j + 1])
            {
                encontrar++;
            }
        }
    }
}