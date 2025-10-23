#include <stdio.h>
int main()
{
    int numeros[10];
    for (int i = 0; i <= 9; i++)
    {
        printf("digite el numero n%d: ", i);
        scanf("%d", &numeros[i]);
    }
    for (int i = 0; i <= 9; i++)
    {
        if (numeros[i] % 2 == 0)
        {
            printf("su numero %d es par", numeros[i]);
        }
        else if (numeros[i] % 2 != 0)
        {
            printf("el numero %d es impar");
        }
    }
    return 0;
}