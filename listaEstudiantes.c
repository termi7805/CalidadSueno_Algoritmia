#include "listaEstudiantes.h"

#include <stdio.h>
#include <stdlib.h>

void iniciarLista(listaEstudiantes *lista)
{
    lista->primero = NULL;
    lista->ultimo = NULL;
}

bool esListaVacia(listaEstudiantes lista)
{
    return lista.primero == NULL;
}

void añadirDato(listaEstudiantes *lista, tipoElementoLista e)
{
    celdaEstudiantes *nuevo;
    nuevo = (celdaEstudiantes*)malloc(sizeof(celdaEstudiantes));
    if (nuevo == NULL)
    {
        printf("No hay memoria para añadir datos\n");
        exit(-1);
    }

    nuevo->dato = e;
    nuevo->sig = NULL;

    if (esListaVacia(*lista))
    {
        lista->primero = nuevo;
        nuevo->id = 0;
    }

    else
    {
        nuevo->id = lista->ultimo->id + 1;
        lista->ultimo->sig = nuevo;
    }
    lista->ultimo = nuevo;
}

void eliminarDatoPrimero(listaEstudiantes *lista)
{
    if (esListaVacia(*lista))
    {
        printf("No se puede eliminar datos de lista vacia\n");
        exit(-1);
    }
    else
    {
        celdaEstudiantes *aux;
        aux = lista->primero;
        lista->primero = lista->primero->sig;
        if (lista->primero == NULL)
        {
            lista->ultimo = NULL;
        }
        free(aux);
    }
}

listaEstudiantes cargarDatos()
{
    listaEstudiantes = lista;
    iniciarLista(&lista);

    calidadSueño nuevo;
    int edad;
    char genero;
    int año_universidad;
    float horas_sueño;
    float horas_estudio;
    float horas_pantalla;
    int cafeina;
    int actividad_fisica;
    float acostar_semana;
    float acostar_finde;
    float despertar_semana;
    float despertar_finde;
    int calidad_sueño;

    char fichero[100];
    FILE *fd;
    scanf ("%s", fichero);
    while ((fd = fopen(fichero, "r")) == NULL)
    {
        printf("Error al abrir el fichero\n");
        scanf("%s", fichero);
    }

    //seguir



void minMax (int min[20], int max[20], listaEstudiantes lista, calidadSueño calidad)
{


void normalizar(listaEstudiantes *lista, calidadDelSueño *calidad)
{
    int minimo, maximo;
    minimo[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    maximo[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    minMax(minimo, maximo, *lista, *calidad);

    celdaEstudiantes *aux;
    aux = lista->primero;

    while (aux != NULL)
    {
        aux->dato.edad = (aux->dato.edad - minimo[0]) / (maximo[0] - minimo[0]);
        aux->dato.genero = (aux->dato.genero - minimo[1]) / (maximo[1] - minimo[1]);
        aux->dato.año_universidad = (aux->dato.año_universidad - minimo[2]) / (maximo[2] - minimo[2]);
        aux->dato.horas_sueño = (aux->dato.horas_sueño - minimo[3]) / (maximo[3] - minimo[3]);
        aux->dato.horas_estudio = (aux->dato.horas_estudio - minimo[4]) / (maximo[4] - minimo[4]);
        aux->dato.horas_pantalla = (aux->dato.horas_pantalla - minimo[5]) / (maximo[5] - minimo[5]);
        aux->dato.cafeina = (aux->dato.cafeina - minimo[6]) / (maximo[6] - minimo[6]);
        aux->dato.actividad_fisica = (aux->dato.actividad_fisica - minimo[7]) / (maximo[7] - minimo[7]);
        aux->dato.acostar_semana = (aux->dato.acostar_semana - minimo[8]) / (maximo[8] - minimo[8]);
        aux->dato.acostar_finde = (aux->dato.acostar_finde - minimo[9]) / (maximo[9] - minimo[9]);
        aux->dato.despertar_semana = (aux->dato.despertar_semana - minimo[10]) / (maximo[10] - minimo[10]);
        aux->dato.desperar_finde = (aux->dato.desperar_finde - minimo[11]) / (maximo[11] - minimo[11]);

        aux = aux->sig;
    }

    lista->dato.edad = (aux->dato.edad - minimo[0]) / (maximo[0] - minimo[0]);
    lista->dato.genero = (aux->dato.genero - minimo[1]) / (maximo[1] - minimo[1]);
    lista->dato.año_universidad = (aux->dato.año_universidad - minimo[2]) / (maximo[2] - minimo[2]);
    lista->dato.horas_sueño = (aux->dato.horas_sueño - minimo[3]) / (maximo[3] - minimo[3]);
    lista->dato.horas_estudio = (aux->dato.horas_estudio - minimo[4]) / (maximo[4] - minimo[4]);
    lista->dato.horas_pantalla = (aux->dato.horas_pantalla - minimo[5]) / (maximo[5] - minimo[5]);
    lista->dato.cafeina = (aux->dato.cafeina - minimo[6]) / (maximo[6] - minimo[6]);
    lista->dato.actividad_fisica = (aux->dato.actividad_fisica - minimo[7]) / (maximo[7] - minimo[7]);
    lista->dato.acostar_semana = (aux->dato.acostar_semana - minimo[8]) / (maximo[8] - minimo[8]);
    lista->dato.acostar_finde = (aux->dato.acostar_finde - minimo[9]) / (maximo[9] - minimo[9]);
    lista->dato.despertar_semana = (aux->dato.despertar_semana - minimo[10]) / (maximo[10] - minimo[10]);
    lista->dato.desperar_finde = (aux->dato.desperar_finde - minimo[11]) / (maximo[11] - minimo[11]);
}



void imprimeDato(tipoElementoLista e)
{
    printf("Edad: %d\n", e.edad);
    printf("Genero: %s\n", e.genero);
    printf("Año universitario: %d\n", e.año_universidad);
    printf("Horas de sueño: %f\n", e.horas_sueño);
    printf("Horas de estudio: %f\n", e.horas_estudio);
    printf("Tiempo con pantallas: %f\n", e.horas_pantalla);
    printf("Cafeina tomada: %d\n", e.cafeina);
    printf("Actividad fisica realizada: %d\n", e.actividad_fisica);
    printf("Hora de acostarse entre semana: %f\n", e.acostar_semana);
    printf("Hora de acostarse en fin de semana: %f\n", e.acostar_finde);
    printf("Hora de despertarse entre semana: %f\n", e.despertar_semana);
    printf("Hora de despertarse en fin de semana: %f\n", e.despertar_finde);
    printf("Calidad de sueño: %d\n\n", e.calidad_sueño);
}

void imprimeListaEntera(listaEstudiantes lista)
{
    celdaEstudiantes *aux;
    aux = lista.primero;

    while (aux != NULL)
    {
        printf("Edad: %d", aux->e.edad);
        printf("Genero: %s", aux->e.genero);
        printf("Curso: %d", aux->e.año_universidad);
        printf("Horas sueño: %f", aux->e.horas_sueño);
        printf("Horas estudio: %f", aux->e.horas_estudio);
        printf("Tiempo pantallas: %f", aux->e.horas_pantalla);
        printf("Cafeina: %d", aux->e.cafeina);
        printf("Actividad fisica: %d", aux->e.actividad_fisica);
        printf("Acostarse semana: %f", aux->e.acostar_semana);
        printf("Acostarse finde: %f", aux->e.acostar_finde);
        printf("Despertarse semana: %f", aux->e.despertar_semana);
        printf("Despertarse finde: %f", aux->e.despertar_finde);
         printf("Calidad de sueño: %d\n", aux->e.calidad_sueño);

        aux = aux->sig;
    }
}
