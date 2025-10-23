#include <stdio.h>
#include <string.h>
#define MAX_NOMBRES 100000
#define NOMBRES_LONGITUD 10
int main(){
    char nombres[MAX_NOMBRES][NOMBRES_LONGITUD];
    int cantidad;
    printf("Ingrese la cantidad de elementos a almacenar: ");
    scanf("%d", &cantidad);
    getchar();
    for(int i = 0; i < cantidad; i++){
        printf("Ingrese el elemento %d: ", (i + 1));
        fgets(nombres[i], NOMBRES_LONGITUD, stdin);
    }
    for(int i = 0; i < cantidad; i++){
        printf("Elemento %d: %s\n", (i + 1), nombres[i]);
    }

    return 0;
}