// codigo hecho por: Sebastián Saravia Olivares
// Fecha inicio: 05/11/2025
// Fecha termino: 
// Nombre: Tragamonedas.c

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int menu(int);
int giro(int numero_aleatorio[3]);

int main(){
   int numero_aleatorio[3];

giro(numero_aleatorio);

return 0;
}

int giro(int numero_aleatorio[3]){
srand(time(0));
for(int i = 0; i < 3; i++){ 

numero_aleatorio[i] = (rand() % 100) + 1;

if(numero_aleatorio[i] > 0 && numero_aleatorio[i] < 3 ){
 printf("[7] ");
}
if(numero_aleatorio[i] > 2 && numero_aleatorio[i] < 6 ){
 printf("[6] ");    
}
if(numero_aleatorio[i] > 5 && numero_aleatorio[i] < 11 ){
 printf("[5] ");    
}
if(numero_aleatorio[i] > 10 && numero_aleatorio[i] < 21 ){
 printf("[4] ");    
}
if(numero_aleatorio[i] > 20 && numero_aleatorio[i] < 31 ){
 printf("[3] ");    
}
if(numero_aleatorio[i] > 30 && numero_aleatorio[i] < 51 ){
 printf("[2] ");    
}
if(numero_aleatorio[i] > 50 && numero_aleatorio[i] < 71 ){
 printf("[1] ");    
}
if(numero_aleatorio[i] > 70 && numero_aleatorio[i] < 101 ){
 printf("[0] ");    
}
}
}

int menu(int){
int opcion;
int monto;
printf("ingrese el monto inicial: ");
scanf("%d", &monto);
printf("cuanto desea apostar?($100, $500, $1000): ");

do{
printf(" ");

}while(opcion != 2);


}