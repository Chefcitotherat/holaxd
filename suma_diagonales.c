#include <stdio.h>

int main(){
    int suma = 0;
    int numero = 1;
    int salto = 2;
    int contador_saltos = 0;

    while (numero <= 1002001)
    {
        suma += numero;
        contador_saltos++;

        if (contador_saltos == 4)
        {-+
            salto + 1;
            contador_saltos = 0;
        }

        numero += salto;
    }

    printf("La suma es: %d\n", suma);

    return 0;
}