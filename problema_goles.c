#include <stdio.h>
#include <string.h>
#define MAX_JUGADORES (100 * 100)
#define NOMBRES_LONGITUD 10
void entrada_vimeros(int *, char vimeros[MAX_JUGADORES][NOMBRES_LONGITUD]);
void entrada_emacneanos(int *, char emacneanos[MAX_JUGADORES][NOMBRES_LONGITUD]);
void goles(int *, char ngoles[MAX_JUGADORES][NOMBRES_LONGITUD]);
int comparar_nombres(const char *, const char *);
void contar_goles(int, char vimeros[MAX_JUGADORES][NOMBRES_LONGITUD], int, char emacneanos[MAX_JUGADORES][NOMBRES_LONGITUD], int, char ngoles[MAX_JUGADORES][NOMBRES_LONGITUD], int *, int *);
void mostrar_resultados(int, int);
int main()
{
    int goles_vimeros;
    int goles_emacneanos;
    int a, b, c;
    char vimeros[MAX_JUGADORES][NOMBRES_LONGITUD];
    char emacneanos[MAX_JUGADORES][NOMBRES_LONGITUD];
    char ngoles[MAX_JUGADORES][NOMBRES_LONGITUD];
    entrada_vimeros(&a, vimeros);
    entrada_emacneanos(&b, emacneanos);
    goles(&c, ngoles);
    contar_goles(a, vimeros, b, emacneanos, c, ngoles, &goles_vimeros, &goles_emacneanos);
    mostrar_resultados(goles_vimeros, goles_emacneanos);
    return 0;
}
void entrada_vimeros(int *a, char vimeros[MAX_JUGADORES][NOMBRES_LONGITUD])
{

    printf("\nIntroduzca la cantidad de integrantes del equipo Vimeros: ");
    scanf("%d", a);
    getchar();
    for (int i = 0; i < *a; i++)
    {
        printf("\nintroduzca el nombre del jugador N°%d: ", i + 1);
        fgets(vimeros[i], NOMBRES_LONGITUD, stdin);
        vimeros[i][strcspn(vimeros[i], "\n")] = 0; // Eliminar el salto de línea
    }
}
void entrada_emacneanos(int *b, char emacneanos[MAX_JUGADORES][NOMBRES_LONGITUD])
{
    printf("\nIntroduzca la cantidad de integrantes del equipo Emacneanos: ");
    scanf("%d", b);
    getchar();
    for (int i = 0; i < *b; i++)
    {
        printf("\nintroduzca el nombre del jugador N°%d: ", i + 1);
        fgets(emacneanos[i], NOMBRES_LONGITUD, stdin);
        emacneanos[i][strcspn(emacneanos[i], "\n")] = 0; // Eliminar el salto de línea
    }
}
void goles(int *c, char ngoles[MAX_JUGADORES][NOMBRES_LONGITUD])
{

    printf("\nIntroduzca la cantidad de goles anotados en el partido: ");
    scanf("%d", c);
    getchar();
    for (int i = 0; i < *c; i++)
    {
        printf("\nintroduzca el nombre del jugador que anoto el gol N°%d: ", i + 1);
        fgets(ngoles[i], NOMBRES_LONGITUD, stdin);
        ngoles[i][strcspn(ngoles[i], "\n")] = 0;
    }
}
int comparar_nombres(const char *nombre1, const char *nombre2)
{
    return strcmp(nombre1, nombre2) == 0;
}
void contar_goles(int a, char vimeros[MAX_JUGADORES][NOMBRES_LONGITUD], int b, char emacneanos[MAX_JUGADORES][NOMBRES_LONGITUD], int c, char ngoles[MAX_JUGADORES][NOMBRES_LONGITUD], int *goles_vimeros, int *goles_emacneanos)
{
    *goles_vimeros = 0;
    *goles_emacneanos = 0;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (comparar_nombres(ngoles[i], vimeros[j]))
            {
                (*goles_vimeros)++;
            }
        }
        for (int k = 0; k < b; k++)
        {
            if (comparar_nombres(ngoles[i], emacneanos[k]))
            {
                (*goles_emacneanos)++;
            }
        }
    }
}
void mostrar_resultados(int goles_vimeros, int goles_emacneanos)
{
    printf("\nGoles Vimeros: %d", goles_vimeros);
    printf("\nGoles Emacneanos: %d", goles_emacneanos);

    if (goles_vimeros > goles_emacneanos)
    {
        printf("\nEl equipo ganador es Vimeros");
    }
    else if (goles_emacneanos > goles_vimeros)
    {
        printf("\nEl equipo ganador es Emacneanos");
    }
    else if(goles_emacneanos == goles_vimeros){
        printf("\nEl partido termino en empate");
    }
    else{
        printf("\nHa ocurrido un error con el conteo de goles.");
    }
}