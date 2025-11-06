// Nombre creador: Sebastian Alejandro Saravia Olivares
// Fecha inicio: 29:10:2025
// Fecha termino: 30:10:2025
// Nombre: NaviStellar.c

#include <stdio.h>

// creamos un struct para manejar mejor las coordenadas y otro para los datos globales
typedef struct coordenada
{
    int X;
    int Y;
} coordenada;
typedef struct datosGlobales
{
    int cantidadColumnas;
    int cantidadFilas;
    coordenada posicionNave;
    coordenada posicionPlaneta;
    int cantidadEstrellas;
    int cantidadDestructores;
    char orientacionInicial;
    int cantidadOrdenes;
    char direccionActual;

} datosGlobales;

// declaramos los prototipos de las funciones que usaremos
char cambiarDireccion(char direccionActual, char direccionGiro);
coordenada obtenerNuevaPosicionNave(coordenada posicionActual, char direccionActual);
int CalcularRuta(FILE *puntero_archivo, FILE *archivo_salida, datosGlobales *datos, char mapa[datos->cantidadFilas][datos->cantidadColumnas], char ordenes[]);
void leerDatos(datosGlobales *datos, FILE *puntero_archivo, char mapa[datos->cantidadFilas][datos->cantidadColumnas]);
void entregarResultado(int resultado, FILE *archivo_salida);

int main()
{
    // Inicializamos los punteros de archivo
    FILE *puntero_archivo;
    FILE *archivo_salida;
    puntero_archivo = fopen("situacion_inicial.txt", "r");
    archivo_salida = fopen("situacion_final.txt", "w");

    // Declaramos una variable de tipo datosGlobales para almacenar toda la información relevante
    datosGlobales datos;

    // primero Leemos las dimensiones del mapa desde el archivo
    fscanf(puntero_archivo, "%d;%d", &datos.cantidadColumnas, &datos.cantidadFilas);
    char mapa[datos.cantidadFilas][datos.cantidadColumnas];

    for (int i = 0; i < datos.cantidadFilas; i++)
    {
        for (int j = 0; j < datos.cantidadColumnas; j++)
        {
            mapa[i][j] = ' ';
        };
    };

    leerDatos(&datos, puntero_archivo, mapa);
    char ordenes[datos.cantidadOrdenes];

    int resultado = CalcularRuta(puntero_archivo, archivo_salida, &datos, mapa, ordenes);
    entregarResultado(resultado, archivo_salida);
    fclose(puntero_archivo);
    fclose(archivo_salida);
    return 0;
}

// en esta función se leen todos los datos del archivo txt y se asignan a la struct datos del programa principal
void leerDatos(datosGlobales *datos, FILE *puntero_archivo, char mapa[datos->cantidadFilas][datos->cantidadColumnas]){

    fscanf(puntero_archivo, "%d;%d", &datos->posicionNave.X, &datos->posicionNave.Y);
    mapa[datos->posicionNave.X][datos->posicionNave.Y] = 'H';
    fscanf(puntero_archivo, "%d;%d", &datos->posicionPlaneta.X, &datos->posicionPlaneta.Y);
    mapa[datos->posicionPlaneta.X][datos->posicionPlaneta.Y] = 'T';

    fscanf(puntero_archivo, "%d", &datos->cantidadEstrellas);
    for (int i = 0; i < datos->cantidadEstrellas; i++)
    {
        int x;
        int y;
        fscanf(puntero_archivo, "%d;%d", &x, &y);
        mapa[x][y] = 'E';
    };

    fscanf(puntero_archivo, "%d", &datos->cantidadDestructores);
    coordenada posicionesDestructores[datos->cantidadDestructores];
    for (int i = 0; i < datos->cantidadDestructores; i++)
    {
        int x;
        int y;
        fscanf(puntero_archivo, "%d;%d", &x, &y);
        mapa[x][y] = 'D';
    };

    fscanf(puntero_archivo, "%s\n", &datos->orientacionInicial);
    fscanf(puntero_archivo, "%d\n", &datos->cantidadOrdenes);
}

// en esta función es para mover la nave y redirigirla
char cambiarDireccion(char direccionActual, char direccionGiro)
{
    if (direccionActual == 'N')
    {
        if (direccionGiro == 'D')
        {
            return 'E';
        }
        if (direccionGiro == 'I')
        {
            return 'O';
        }
    }
    if (direccionActual == 'E')
    {
        if (direccionGiro == 'D')
        {
            return 'S';
        }
        if (direccionGiro == 'I')
        {
            return 'N';
        }
    }
    if (direccionActual == 'O')
    {
        if (direccionGiro == 'D')
        {
            return 'N';
        }
        if (direccionGiro == 'I')
        {
            return 'S';
        }
    }
    if (direccionActual == 'S')
    {
        if (direccionGiro == 'D')
        {
            return 'O';
        }
        if (direccionGiro == 'I')
        {
            return 'E';
        }
    }
    return ' ';
}

// en esta función se obtiene la nueva posición de la nave según su dirección actual
coordenada obtenerNuevaPosicionNave(coordenada posicionActual, char direccionActual)
{
    coordenada nuevaCoordenada = {posicionActual.X, posicionActual.Y};
    if (direccionActual == 'N')
    {
        nuevaCoordenada.X = posicionActual.X - 1;
    }
    if (direccionActual == 'S')
    {
        nuevaCoordenada.X = posicionActual.X + 1;
    }
    if (direccionActual == 'E')
    {
        nuevaCoordenada.Y = posicionActual.Y + 1;
    }
    if (direccionActual == 'O')
    {
        nuevaCoordenada.Y = posicionActual.Y - 1;
    }
    return nuevaCoordenada;
}

// en esta función se calcula la ruta de la nave según las órdenes recibidas
int CalcularRuta(FILE *puntero_archivo, FILE *archivo_salida, datosGlobales *datos, char mapa[datos->cantidadFilas][datos->cantidadColumnas], char ordenes[datos->cantidadOrdenes])
{
    datos->direccionActual = datos->orientacionInicial;
    for (int i = 0; i < datos->cantidadOrdenes; i++)
    {
        ordenes[i] = fgetc(puntero_archivo);
        char ordenActual = ordenes[i];

        if (mapa[datos->posicionNave.X][datos->posicionNave.Y] == 'D' || mapa[datos->posicionNave.X][datos->posicionNave.Y] == 'E')
        {
            return 0;
            break;
        }

        if (datos->posicionNave.X >= datos->cantidadFilas || datos->posicionNave.Y >= datos->cantidadColumnas || datos->posicionNave.X < 0 || datos->posicionNave.Y < 0)
        {
            return 1;
            break;
        }

        if (ordenActual == 'I' || ordenActual == 'D')
        {
            datos->direccionActual = cambiarDireccion(datos->direccionActual, ordenActual);
        }
        if (ordenActual == 'A')
        {
            datos->posicionNave = obtenerNuevaPosicionNave(datos->posicionNave, datos->direccionActual);
        }
        if (datos->posicionNave.X < 0 || datos->posicionNave.Y < 0 ||
            datos->posicionNave.X >= datos->cantidadFilas ||
            datos->posicionNave.Y >= datos->cantidadColumnas)
        {
            return 1;
        }
        if (datos->posicionNave.X == datos->posicionPlaneta.X && datos->posicionNave.Y == datos->posicionPlaneta.Y)
        {
            return 2;
            break;
        };
    }
}

// en esta función se entrega el resultado final al archivo de salida
void entregarResultado(int resultado, FILE *archivo_salida){
    if (resultado == 0)
    {
        fprintf(archivo_salida, "Nave destruida.");
    }
    if (resultado == 1)
    {
        fprintf(archivo_salida, "Nave perdida.");
    }
    if (resultado == 2)
    {
        fprintf(archivo_salida, "Llegamos a salvo");
    }
}