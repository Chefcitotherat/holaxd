// Codigo de primer ejercicio profe Philip
// Hecho por Sebastian Saravias O.

#include <stdio.h>

int primo(int numerof);

int main(){
int numero, bandera;
    printf("ingrese un numero: \n");
    scanf("%d", &numero);

    bandera = primo(numero);
    if(bandera = 1){
        printf("el numero %d es primo.", numero);
    }
    else{
        printf("el numero %d no es primo.", numero);
    }


    return 0;
}

int primo(int numerof){
/*
Definicion de las funciones
*/
for(int i = 2;i >= numerof; i++){
    if(numerof%i == 0){
        return 0;
    }
}

}