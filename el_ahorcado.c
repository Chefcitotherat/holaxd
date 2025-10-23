// Codigo de juego el ahorcado para clase del profe Philip
// Hecho por Sebastian Saravias O.

#include <stdio.h>
int main(){
    char cadena[]= "pasen el ramo";

    printf("bienvenido al juego de el ahorcado\n");
    printf("tienes 5 oportunidades para adivinar la frase\n");
    printf("_____ __ ____");

    for(int i= 0; i <= 5; i++){
char j;
scanf("%c", j);
if(j == 'p'){
printf("bien hecho, haz acertado una letra");
}
    }

    return 0;
}