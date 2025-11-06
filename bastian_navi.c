// Nombre creador: Baastian Rodriguez Diaz
// Fecha: 29/10/2025
// Nombre: Halcon.c

#include <stdio.h>
// use un struct para guiarme mejor en las coordenadas de las matrises y oubicacciónes
typedef struct coordenada
{
    int X;
    int Y;
} coordenada;

// declaramos las funciones que a futuro nos servira
char cambiar_Direccion(char, char);
int Fuera_De_Orbita(coordenada, int, int);
coordenada Nueva_Posicion_Nave(coordenada, char);
void ordenar_datos(FILE *, char[50][50], int *, int *, int *, int *, char *, int *, coordenada *, coordenada *, int *);

// en el in main se trabaja con la ejecuccion de los archivos txt tanto para leer lo que contiene un archivo txt como crear un txt con un texto
int main()
{
    FILE *archivo_inicio;
    FILE *archivo_salida;
    archivo_inicio = fopen("texto.txt", "r");
    archivo_salida = fopen("situacion_final.txt", "w");

    int Filasx;
    int Columnasy;
    coordenada Nave;
    coordenada Planeta;
    int estrellas;
    int destructores;
    char orientacion;
    int c_Ordenes;
    char mapa[50][50];
    int error = 0;

    ordenar_datos(archivo_inicio, mapa, &Filasx, &Columnasy, &estrellas, &destructores, &orientacion, &c_Ordenes, &Nave, &Planeta, &error);

    if(error == 1){  
            printf("Error:problrmas en destructores o estrellas se recomienda revisar");
            return 0;
           
          

    }else

    for (int x = 0; x < Filasx; x++){

        for (int y = 0; y < Columnasy; y++)
        {
            printf("%c", mapa[x][y]);
        }
        printf("\n");
    }

    char ordenes[c_Ordenes];
    printf("orientacion inicial: %c\n", orientacion);
    char direccionActual = orientacion;

    for (int k = 0; k < c_Ordenes; k++){

        ordenes[k] = fgetc(archivo_inicio);
        char ordenActual = ordenes[k];

        if (mapa[Nave.X][Nave.Y] == 'D' || mapa[Nave.X][Nave.Y] == 'E'){

            printf("¡FWOOOOSH-KRSHHH!:(\n");
            fprintf(archivo_salida, "Nave destruida");
            break;
        }

        if (Fuera_De_Orbita(Nave, Filasx, Columnasy))
        {
            printf("ERROR 404: LINK LOST:(\n");
            printf("\nSe a perdido la conexion");
            fprintf(archivo_salida, "Nave perdida");
            break;
        }

        if (ordenActual == 'I' || ordenActual == 'D')
        {
            direccionActual = cambiar_Direccion(direccionActual, ordenActual);
            printf("cambio de rumbo => %c\n", direccionActual);
        }

        if (ordenActual == 'A')
        {
            Nave = Nueva_Posicion_Nave(Nave, direccionActual);
            printf("posicion => %d,%d\n", Nave.X, Nave.Y);
        }

        if (Nave.X == Planeta.X && Nave.Y == Planeta.Y)
        {
            printf("El Halcon Milenario ha aterrizado\n");
            fprintf(archivo_salida, "Llegamos a salvo");
            break;
        };
    }

    fclose(archivo_inicio);
    fclose(archivo_salida);
    return 0;
}

// en esta función se asigna y ordena todo los valores del archivo txt
void ordenar_datos(FILE *archivo_inicio,
                   char mapa[50][50], int *Filasx,
                   int *Columnasy, int *estrellas,
                   int *destructores, char *orientacion,
                   int *c_Ordenes,
                   coordenada *Nave, coordenada *Planeta, int *error)
{

    fscanf(archivo_inicio, "%d;%d", Filasx, Columnasy);

    for (int x = 0; x < *Filasx; x++)
    {
        for (int y = 0; y < *Columnasy; y++)
        {
            mapa[x][y] = '-';
        }
    }

    fscanf(archivo_inicio, "%d;%d", &Nave->X, &Nave->Y);
    mapa[Nave->X][Nave->Y] = 'H';

    fscanf(archivo_inicio, "%d;%d", &Planeta->X, &Planeta->Y);
    mapa[Planeta->X][Planeta->Y] = 'T';

   
    fscanf(archivo_inicio, "%d", estrellas);
    for (int k = 0; k < *estrellas; k++)
    {
        int x, y;
        if(fscanf(archivo_inicio, "%d;%d", &x, &y)){ 
        mapa[x][y] = 'E';
        }     
    }

    int xe_extras, ye_extras;
    if(fscanf(archivo_inicio, "%d;%d", &xe_extras, &ye_extras) == 2){ 

        *error = 1;
        return;
    }

    fscanf(archivo_inicio, "%d", destructores);
    coordenada posicionesDestructores[*destructores];
    for (int k = 0; k < *destructores; k++){
        int x, y;
        if(fscanf(archivo_inicio, "%d;%d", &x, &y) == 2){ 
        mapa[x][y] = 'D';
        }
    }
    int xd_extras, yd_extras;
    if(fscanf(archivo_inicio, "%d;%d", &xd_extras, &yd_extras) == 2){ 

        *error = 1;
        return;
    }


    fscanf(archivo_inicio, "%s\n", orientacion);
    fscanf(archivo_inicio, "%d\n", c_Ordenes);
}

// en esta función es para mover la nave y rederigirla
char cambiar_Direccion(char d_Actual, char d_Giro)
{

    if (d_Actual == 'N')
    {

        if (d_Giro == 'D')
        {
            return 'E';
        }
        if (d_Giro == 'I')
        {
            return 'O';
        }
    }

    if (d_Actual == 'E')
    {

        if (d_Giro == 'D')
        {
            return 'S';
        }
        if (d_Giro == 'I')
        {
            return 'N';
        }
    }

    if (d_Actual == 'O')
    {
        if (d_Giro == 'D')
        {
            return 'N';
        }
        if (d_Giro == 'I')
        {
            return 'S';
        }
    }

    if (d_Actual == 'S')
    {
        if (d_Giro == 'D')
        {
            return 'O';
        }
        if (d_Giro == 'I')
        {
            return 'E';
        }
    }
    return ' ';
}

// en esta funcción se asigna el rumbo de la nave (a caso va al este, oeste surn o norte);
coordenada Nueva_Posicion_Nave(coordenada posicion_A, char direccion_A)
{
    coordenada Nueva_Posicion = {posicion_A.X, posicion_A.Y};
    if (direccion_A == 'N')
    {
        Nueva_Posicion.X = posicion_A.X - 1;
    }
    if (direccion_A == 'S')
    {
        Nueva_Posicion.X = posicion_A.X + 1;
    }
    if (direccion_A == 'E')
    {
        Nueva_Posicion.Y = posicion_A.Y + 1;
    }
    if (direccion_A == 'O')
    {
        Nueva_Posicion.Y = posicion_A.Y - 1;
    }
    return Nueva_Posicion;
}

// una mini funcion que nos detecta si la nave salio de los limites de la matris
int Fuera_De_Orbita(coordenada Nave, int Filasx, int Columnasy)
{
    return (Nave.X >= Filasx || Nave.Y >= Columnasy || Nave.X < 0 || Nave.Y < 0);
}