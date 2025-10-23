// codigo creado por Sebastián Saravia 2do semestre IECI
#include <stdio.h>
#define tama_arr 5
typedef struct guardar_direcciones{
   int casilla;
   int coordenada_x;
   int coordenada_y;
}guardar_direcciones;
int leer_archivo(int arr[tama_arr][tama_arr] );
int encontrar_puntos(int guardar_direcciones[tama_arr], int arr[tama_arr][tama_arr]);
int main(){
    int encontrar;
   int guardar_direcciones[tama_arr];
int arr[tama_arr][tama_arr];
leer_archivo(arr);
encontrar = encontrar_puntos(guardar_direcciones, arr);
printf("%d",encontrar);
}
int leer_archivo(int arr[tama_arr][tama_arr]){
   FILE *puntero_archivo;
puntero_archivo = fopen("pruebac.txt", "r");

for(int i = 0; i < tama_arr; i++){
    for(int j = 0; j < tama_arr; j++){
        fscanf(puntero_archivo, "%d", &arr[i][j]);
    }
}
fclose(puntero_archivo);
}
int encontrar_puntos(int guardar_direcciones[tama_arr], int arr[tama_arr][tama_arr]){
    int encontrar = 0;
    for(int i = 0; i < tama_arr; i++){
        for(int j = 0; j < tama_arr; j++){
           if(arr[i][j] < arr[i][j+1]){
            encontrar++;
           }
        }
    }
    return encontrar;
}