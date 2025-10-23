#include <stdio.h>
int main()
{
    int inicio, fin;

    printf("digite el numero de inicio:");
    scanf("%d", &inicio);
    printf("digite el numero de fin:");
    scanf("%d", &fin);

    for (int i = inicio; i <= fin; i++)
    {
        int n = i;
        printf("%d, ", n);
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = 3 * n + 1;
            }
            printf("%d, ", n);
        }
        printf("\n");
    }
}