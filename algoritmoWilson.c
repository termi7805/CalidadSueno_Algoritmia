#include "algoritmoWilson.h"
#include "listaordenadavecinos.h"
#include <stdlib.h>

void precisionAcierto(listaEstudiantes *l, int K)
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    float contCorrectos = 0, contTotales = 0;
    int calidadSueñoPredicha;


    iniciarLista(&listaAuxiliar);

    aux = l->primero;

    while (aux != NULL && aux->id <= l->ultimo->id)
    {
        ant = aux;
        aux = aux->sig;

        vecinos = distanciaMinima(ant->dato, *l, K); //vecinos mas cercanos

        calidadSueñoPredicha = mediaVecinos(vecinos); // Predecimos el nivel de calidad del sueño basandonos en la media de los vecinos

        while (!estaVacia(vecinos))
        {
            desencolarVecinos(&vecinos);
        }

        if (calidadSueñoPredicha == ant->dato.calidad_sueño) // Verificamos si la predicción coincide con el valor real
            contCorrectos++;

        // Añadir el elemento a ambas listas
        añadirDato(&listaAuxiliar, ant->dato);
        desencolarEstudiantes(l);
        contTotales++;
    }

    // Mostrar resultados
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos en la lista: %.0f\n", contTotales);
    printf("Se ha acertado en %.0f elementos\n", contCorrectos);
    printf("Porcentaje de efectividad: %.2f%%\n", (contCorrectos / contTotales) * 100);
    printf("------------------------------------------------------------\n");

    // Confirmar que la lista original ha sido vaciada correctamente
    if (esListaVacia(*l))
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista original...\n");
    }
    else
        printf("Error: la lista original no se vació correctamente\n");

     // Reemplazar la lista original con la lista auxiliar
    *l = listaAuxiliar;

}


void algoritmoENN(listaEstudiantes *l, int K)
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    float contCorrectos = 0, contTotales = 0;
    int calidadSueñoPredicha;

    // Obtener el ID del último elemento para controlar el ciclo
    int fin = l->ultimo->id;

    // Iniciar la lista auxiliar
    iniciarLista(&listaAuxiliar);

    aux = l->primero;

    // Procesar todos los estudiantes
    while (aux != NULL && aux->id <= fin)
    {
        ant = aux;
        aux = aux->sig;

        // Calcular los vecinos más cercanos de `ant`
        vecinos = distanciaMinima(ant->dato, *l, K);

        // Predecir el nivel de calidad del sueño basado en la media de los vecinos
        calidadSueñoPredicha = mediaVecinos(vecinos);


        while (!estaVacia(vecinos))
        {
            desencolarVecinos(&vecinos);
        }


        // Si la predicción coincide, mantener el elemento
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            contCorrectos++;
            añadirDato(&listaAuxiliar, ant->dato); // Guardar en lista depurada
            añadirDato(l, ant->dato);             // Mantener en lista original
        }

        // Quitar el elemento actual de la lista original
        desencolarEstudiantes(l);
        contTotales++;
    }

    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos procesados: %.0f\n", contTotales);
    printf("Elementos guardados: %.0f\n", contCorrectos);
    printf("Elementos eliminados: %.0f\n", contTotales - contCorrectos);
    printf("Porcentaje de efectividad: %.2f%%\n", (contCorrectos / contTotales) * 100);
    printf("------------------------------------------------------------\n");

    while (!esListaVacia(*l))
    {
        desencolarEstudiantes(l);
    }


    if (esListaVacia(*l)) //confirmamos que esta vacia
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista depurada...\n");
    }
    else
        printf("Error: la lista original no se vació correctamente\n");

    *l = listaAuxiliar;
}
