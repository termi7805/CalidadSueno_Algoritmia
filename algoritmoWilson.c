#include "algoritmoWilson.h"
#include "listaordenadavecinos.h"
#include <stdlib.h>

void precisionAcierto(listaEstudiantes *l, int K) // -> comprobar si la predicción del nivel de calidad del sueño (basada en los vecinos más cercanos) es correcta en relación con los datos reales de cada estudiante
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    celdaVecino *vecinoAux;
    float cont = 0, cont2 = 0;
    int fin, calidadSueñoPredicha;

    // Obtener el ID del último elemento para controlar el ciclo
    fin = l->ultimo->id;

    iniciarLista(&listaAuxiliar);

    aux = l->primero;

    // Procesar todos los estudiantes
    while (aux != NULL && aux->id <= fin)
    {
        ant = aux;
        aux = aux->sig;

        // Calcular los vecinos más cercanos de ant`
        vecinos = distanciaMinima(ant->dato, *l, K);

        // Predecir el nivel de calidad del sueño basado en la media de los vecinos
        calidadSueñoPredicha = mediaVecinos(vecinos);

        // Limpiar la lista de vecinos después de usarla
        while (!estavacia(vecinos))
        {
            vecinoAux = vecinos.primero;
            vecinos.primero = vecinos.primero->siguiente;
            free(vecinoAux);
        }

        // Verificar si la predicción coincide con el valor real
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            cont++;
        }

        // Añadir el elemento a ambas listas
        añadirDato(&listaAuxiliar, ant->dato);
        desencolar(l);
        cont2++;
    }

    // Mostrar resultados
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos en la lista: %.0f\n", cont2);
    printf("Se ha acertado en %.0f elementos\n", cont);
    printf("Porcentaje de efectividad: %.2f%%\n", (cont / cont2) * 100);
    printf("------------------------------------------------------------\n");

    // Reemplazar la lista original con la lista auxiliar
    *l = listaAuxiliar;

    // Confirmar que la lista original ha sido vaciada correctamente
    if (esListaVacia(*l))
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista original...\n");
    }
    else
    {
        printf("Error: la lista original no se vació correctamente\n");
    }
}


void algoritmoENN(listaEstudiantes *l, int K) // -> limpiar la lista de estudiantes eliminando aquellos cuya predicción de calidad del sueño no fue correcta, conservando solo aquellos  con predicciones correctas. De esta manera, la lista original se depura para que solo contenga los elementos más precisos.
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    celdaVecino *vecinoAux;
    float cont = 0;
    float cont2 = 0;
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

        // Limpiar la lista de vecinos después de usarla
        while (!estavacia(vecinos))
        {
            vecinoAux = vecinos.primero;
            vecinos.primero = vecinos.primero->siguiente;
            free(vecinoAux);
        }

        // Si la predicción coincide, mantener el elemento
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            cont++;
            añadirDato(&listaAuxiliar, ant->dato); // Guardar en lista depurada
            añadirDato(l, ant->dato);             // Mantener en lista original
        }

        // Quitar el elemento actual de la lista original
        desencolar(l);
        cont2++;
    }

    // Mostrar estadísticas
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos procesados: %.0f\n", cont2);
    printf("Elementos guardados: %.0f\n", cont);
    printf("Elementos eliminados: %.0f\n", cont2 - cont);
    printf("Porcentaje de efectividad: %.2f%%\n", (cont / cont2) * 100);
    printf("------------------------------------------------------------\n");

    // Vaciar la lista original
    aux = l->primero;
    while (aux != NULL)
    {
        desencolar(l);
        aux = aux->sig;
    }

    // Confirmar que la lista original está vacía
    if (esListaVacia(*l))
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista depurada...\n");
    }
    else
    {
        printf("Error: la lista original no se vació correctamente\n");
    }

    // Reemplazar la lista original con la lista depurada
    *l = listaAuxiliar;
}

