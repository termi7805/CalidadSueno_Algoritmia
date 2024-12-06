#include "listaordenadavecinos.h"
#include "algoritmoWilson.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    calidadDelSueño CalidadDelSueño;
    listaEstudiantes lista;
    listaOrdenadaVecinos listaVecinos;

    int numVecinos_K;
    char salir;
    char fichero[100];
    FILE *fd;

    printf("Este algoritmo calcula la calidad de sueño de estudiantes universitarios\n");

    printf("Por favor, introduce el dataset: ");
    scanf("%s", fichero);
    while ((fd = fopen(fichero, "r")) == NULL)
    {
        printf("Error al abrir el fichero, introduce el nombre correcto: ");
        scanf("%s", fichero);
    }
    lista = cargarDatos(fd);
    printf("El dataset ha sido cargado correctamente\n\n");


    do
    {
        printf("A continuacion, le haremos una encuesta para descubrir su calidad del sueño\n");
        leerCalidadDelSueño(&CalidadDelSueño);
        printf("Muchas gracias, has respondido a todas las preguntas!\n\n");


        //NORMALIZACION DE LOS DATOS
        printf("Ahora procederemos a normalizar todos los datos obtenidos\n");
        sleep(2);
        normalizar(&lista, &CalidadDelSueño);
        imprimeListaEntera(lista);
        printf("Datos normalizados correctamente\n\n");


        //K-NN
        printf("Introduce un valor para k (k > 0) que representa el numero de vecinos: ");
        scanf("%d", &numVecinos_K);
        while(numVecinos_K <= 0)
        {
            printf("ERROR - Introduce un valor mayor que 0: ");
            scanf("%d",&numVecinos_K);
        }
        printf("\n");


        iniciarListaVecinos(&listaVecinos);
        listaVecinos = distanciaMinima(CalidadDelSueño, lista, numVecinos_K);
        imprimirResultados(listaVecinos);
        printf("\n");


        //ALGORITMO DE WILSON
        printf("La efectividad del dataset es: \n");
        precisionAcierto(&lista, numVecinos_K);
        printf("\n\n");

        printf("Aplicamos el algoritmo ENN\n");
        algoritmoENN(&lista, numVecinos_K);
        printf("\n\n");

        printf("Despues de aplicar el algoritmo ENN, la efectividad del dataset es: \n");
        precisionAcierto(&lista, numVecinos_K);
        printf("\n\n");



        printf("Desea hacer otra prueba con el mismo dataset? (s/n): ");
        scanf(" %c", &salir);

    } while(salir == 's');

    printf("Saliendo del programa\n");

    //eliminamos la lista de estudiantes
    while (!esListaVacia(lista)) // Recorremos hasta que la lista esté vacía
    {
        desencolarEstudiantes(&lista); // Elimina el primer nodo y lo libera
    }
    while (!estaVacia(listaVecinos)) // Recorremos hasta que la lista esté vacía
    {
        desencolarVecinos(&listaVecinos); // Elimina el primer nodo y lo libera
    }


    return 0;
}
