#include "algoritmoWilson.h"
#include "listaordenadavecinos.h"
#include <stdlib.h>

void precisionAcierto(listaEstudiantes *l, int K)
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    float cont = 0, cont2 = 0;
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
        {
            cont++;
        }

        // Añadir el elemento a ambas listas
        añadirDato(&listaAuxiliar, ant->dato);
        desencolarEstudiantes(l);
        cont2++;
    }

    // Mostrar resultados
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos en la lista: %.0f\n", cont2);
    printf("Se ha acertado en %.0f elementos\n", cont);
    printf("Porcentaje de efectividad: %.2f%%\n", (cont / cont2) * 100);
    printf("------------------------------------------------------------\n");

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

     // Reemplazar la lista original con la lista auxiliar
    *l = listaAuxiliar;

}


void algoritmoENN(listaEstudiantes *l, int K) // -> limpiar la lista de estudiantes eliminando aquellos cuya predicción de calidad del sueño no fue correcta, conservando solo aquellos  con predicciones correctas. De esta manera, la lista original se depura para que solo contenga los elementos más precisos.
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
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


        while (!estaVacia(vecinos))
        {
            desencolarVecinos(&vecinos);
        }


        // Si la predicción coincide, mantener el elemento
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            cont++;
            añadirDato(&listaAuxiliar, ant->dato); // Guardar en lista depurada
            añadirDato(l, ant->dato);             // Mantener en lista original
        }

        // Quitar el elemento actual de la lista original
        desencolarEstudiantes(l);
        cont2++;
    }

    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos procesados: %.0f\n", cont2);
    printf("Elementos guardados: %.0f\n", cont);
    printf("Elementos eliminados: %.0f\n", cont2 - cont);
    printf("Porcentaje de efectividad: %.2f%%\n", (cont / cont2) * 100);
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
    {
        printf("Error: la lista original no se vació correctamente\n");
    }

    *l = listaAuxiliar;
}

void precisionYDepuracion(listaEstudiantes *l, int K)
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    float contAciertosAntes = 0, contTotalAntes = 0;
    float contAciertosDespues = 0, contTotalDespues = 0;
    int calidadSueñoPredicha;

    // Iniciar la lista auxiliar
    iniciarLista(&listaAuxiliar);

    aux = l->primero;

    // Procesar todos los estudiantes
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->sig;

        // Calcular los vecinos más cercanos de `ant`
        vecinos = distanciaMinima(ant->dato, *l, K);

        // Predecir el nivel de calidad del sueño basado en la media de los vecinos
        calidadSueñoPredicha = mediaVecinos(vecinos);

        // Limpiar la lista de vecinos
        while (!estaVacia(vecinos))
        {
            desencolarVecinos(&vecinos);
        }

        // Contar total de elementos procesados
        contTotalAntes++;

        // Si la predicción coincide, mantener el elemento
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            contAciertosAntes++;
            añadirDato(&listaAuxiliar, ant->dato); // Guardar en lista depurada
        }

        // Quitar el elemento actual de la lista original
        desencolarEstudiantes(l);
    }

    // Mostrar resultados antes de la depuración
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos procesados: %.0f\n", contTotalAntes);
    printf("Elementos guardados (predicciones correctas): %.0f\n", contAciertosAntes);
    printf("Elementos eliminados: %.0f\n", contTotalAntes - contAciertosAntes);
    printf("Porcentaje de efectividad (antes de depurar): %.2f%%\n", (contAciertosAntes / contTotalAntes) * 100);
    printf("------------------------------------------------------------\n");

    // Calcular el total de elementos en la lista depurada
    contTotalDespues = 0;
    celdaEstudiantes *auxDepurada = listaAuxiliar.primero;
    while (auxDepurada != NULL)
    {
        contTotalDespues++;
        auxDepurada = auxDepurada->sig;
    }

    // La cantidad de aciertos después de la depuración es igual a los que se guardaron
    contAciertosDespues = contAciertosAntes;

    // Mostrar resultados después de la depuración
    printf("Total de elementos en la lista depurada: %.0f\n", contTotalDespues);
    printf("Elementos guardados (predicciones correctas): %.0f\n", contAciertosDespues);
    printf("Porcentaje de efectividad (después de depurar): %.2f%%\n", (contAciertosDespues / contTotalDespues) * 100);
    printf("------------------------------------------------------------\n");

    // Confirmar que la lista original ha sido vaciada correctamente
    if (esListaVacia(*l))
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista depurada...\n");
    }
    else
    {
        printf("Error: la lista original no se vació correctamente\n");
    }

    // Reemplazar la lista original con la lista auxiliar
    *l = listaAuxiliar;
}
