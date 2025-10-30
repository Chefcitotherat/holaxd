// Nombre creador: Sebastian Alejandro Saravia Olivares
// Fecha inicio: 29:10:2025
// Fecha termino: 
// Nombre: NaviStellar.c

#include <stdio.h>
#include <string.h>

void LeerMatrices(char, int *);
void LeerCoordenadas(coordenadas[], int *);
void Procesar(int, int, int);
void Salida(int, int, int);


typedef struct coordenadas{
   int X;
   int Y;
}coordenadas;
int main(){
int filas, columnas;
int E, D;
char Mapa[filas][columnas];
char PoscicionNave;
char Planeta;
coordenadas Estrellas[E];
coordenadas Destructores[D];
return 0;
}

void leerMatrices(char matriz[], int *PuntoDeControl){
FILE *puntero_archivo;
puntero_archivo = fopen("situacion_inicial.txt", "r");
for(int i; i < 10; i++){
   
}
}