#include "listaEstudiantes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    celdaEstudiantes* nuevo = (celdaEstudiantes*)malloc(sizeof(celdaEstudiantes));
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
/*
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
}*/

listaEstudiantes cargarDatos(char fichero[100])  //para cargar el dataset
{
    FILE *fd;
    char generoStr[10];
    char añoUniStr[20];

    listaEstudiantes lista;
    iniciarLista(&lista);
    calidadDelSueño nuevo;

    while ((fd = fopen(fichero, "r")) == NULL)
    {
        printf("Error al abrir el fichero, introduce el nombre correctamente: ");
        scanf("%s", fichero);
    }

    char linea[400];
    fgets(linea, sizeof(linea), fd); //saltar la primera linea porque son cabeceras

    while (fscanf(fd, "%d,%d,%[^,],%[^,],%f,%f,%f,%d,%d,%d,%f,%f,%f,%f", &nuevo.id, &nuevo.edad, generoStr, añoUniStr, &nuevo.horas_sueño, &nuevo.horas_estudio, &nuevo.horas_pantalla, &nuevo.cafeina, &nuevo.actividad_fisica, &nuevo.calidad_sueño, &nuevo.acostar_semana, &nuevo.acostar_finde, &nuevo.despertar_semana, &nuevo.despertar_finde) != EOF)
    {
        printf("Dato ID %d: \n", nuevo.id);
        printf("%d %s %s %f %f %f %d %d %d %f %f %f %f\n", nuevo.edad, generoStr, añoUniStr, nuevo.horas_sueño, nuevo.horas_estudio, nuevo.horas_pantalla, nuevo.cafeina, nuevo.actividad_fisica, nuevo.calidad_sueño, nuevo.acostar_semana, nuevo.acostar_finde, nuevo.despertar_semana, nuevo.despertar_finde);

        if(generoStr[0] == 'M')
            nuevo.genero = 0;
        else if(generoStr[0] == 'F')
            nuevo.genero = 1;
        else
            nuevo.genero = 2;


        if(añoUniStr[0] == '1')
            nuevo.año_universidad = 1;
        else if(añoUniStr[0] == '2')
            nuevo.año_universidad = 2;
        else if(añoUniStr[0] == '3')
            nuevo.año_universidad = 3;
        else
            nuevo.año_universidad = 4;

        añadirDato(&lista, nuevo); //los añadimos 1 por 1 usando la funcion que hemos creado antes
    }

    fclose(fd);
    return lista;
}

void inicializaMinMax (int *minimo, int *maximo, listaEstudiantes lista, calidadDelSueño calidad) //para normalizar los valores
{
    celdaEstudiantes* aux = lista.primero;
    int listaAux[12] = {calidad.edad, calidad.genero, calidad.año_universidad, calidad.horas_sueño, calidad.horas_estudio, calidad.horas_pantalla, calidad.cafeina, calidad.actividad_fisica, calidad.acostar_semana, calidad.acostar_finde, calidad.despertar_semana, calidad.despertar_finde};
    
    memcpy(minimo, listaAux, 12);
    memcpy(maximo, listaAux, 12);

    while (aux != NULL)  //recorremos toda la lista para encontrar los valores maximos y minimos
    {
        if (aux->dato.edad < minimo[0]) //Sentencias if-else, como ya hemos asignado un valor por defecto, si es minimo ya no es maximo 
            minimo[0] = aux->dato.edad;
        else if (aux->dato.edad > maximo[0])
            maximo[0] = aux->dato.edad;
        if (aux->dato.genero < minimo[1])
            minimo[1] = aux->dato.genero;
        else if (aux->dato.genero > maximo[1])
            maximo[1] = aux->dato.genero;
        if (aux->dato.año_universidad < minimo[2])
            minimo[2] = aux->dato.año_universidad;
        else if (aux->dato.año_universidad > maximo[2])
            maximo[2] = aux->dato.año_universidad;
        if (aux->dato.horas_sueño < minimo[3])
            minimo[3] = aux->dato.horas_sueño;
        else if (aux->dato.horas_sueño > maximo[3])
            maximo[3] = aux->dato.horas_sueño;
        if (aux->dato.horas_estudio < minimo[4])
            minimo[4] = aux->dato.horas_estudio;
        else if (aux->dato.horas_estudio > maximo[4])
            maximo[4] = aux->dato.horas_estudio;
        if (aux->dato.horas_pantalla < minimo[5])
            minimo[5] = aux->dato.horas_pantalla;
        else if (aux->dato.horas_pantalla > maximo[5])
            maximo[5] = aux->dato.horas_pantalla;
        if (aux->dato.cafeina < minimo[6])
            minimo[6] = aux->dato.cafeina;
        else if (aux->dato.cafeina > maximo[6])
            maximo[6] = aux->dato.cafeina;
        if (aux->dato.actividad_fisica < minimo[7])
            minimo[7] = aux->dato.actividad_fisica;
        else if (aux->dato.actividad_fisica > maximo[7])
            maximo[7] = aux->dato.actividad_fisica;
        if (aux->dato.acostar_semana < minimo[8])
            minimo[8] = aux->dato.acostar_semana;
        else if (aux->dato.acostar_semana > maximo[8])
            maximo[8] = aux->dato.acostar_semana;
        if (aux->dato.acostar_finde < minimo[9])
            minimo[9] = aux->dato.acostar_finde;
        else if (aux->dato.acostar_finde > maximo[9])
            maximo[9] = aux->dato.acostar_finde;
        if (aux->dato.despertar_semana < minimo[10])
            minimo[10] = aux->dato.despertar_semana;
        else if (aux->dato.despertar_semana > maximo[10])
            maximo[10] = aux->dato.despertar_semana;
        if (aux->dato.despertar_finde < minimo[11])
            minimo[11] = aux->dato.despertar_finde;
        else if (aux->dato.despertar_finde > maximo[11])
            maximo[11] = aux->dato.despertar_finde;

        aux = aux->sig;
    }
}

void normalizar(listaEstudiantes *lista, calidadDelSueño *calidad)
{
    int minimo[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int maximo[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    inicializaMinMax(minimo, maximo, *lista, *calidad);

    celdaEstudiantes* aux = lista->primero;

    while (aux != NULL)  //normalizamos
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
        aux->dato.despertar_finde = (aux->dato.despertar_finde - minimo[11]) / (maximo[11] - minimo[11]);

        aux = aux->sig;
    }
    //falta el ultimo dato de la lista? (lista->dato es lo mismo que lista->ultimo->dato?)
    /*Error al compilar, explicación en WhatsApp pendiente de resolver, comento las líneas
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
    lista->dato.despertar_finde = (aux->dato.despertar_finde - minimo[11]) / (maximo[11] - minimo[11]);*/
}



void imprimeDato(tipoElementoLista e)
{
    printf("Edad: %d\n", e.edad);
    printf("Genero: %d\n", e.genero);
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
        printf("Edad: %d\n", aux->dato.edad);
        printf("Genero: %d\n", aux->dato.genero);
        printf("Curso: %d\n", aux->dato.año_universidad);
        printf("Horas sueño: %f\n", aux->dato.horas_sueño);
        printf("Horas estudio: %f\n", aux->dato.horas_estudio);
        printf("Tiempo pantallas: %f\n", aux->dato.horas_pantalla);
        printf("Cafeina: %d\n", aux->dato.cafeina);
        printf("Actividad fisica: %d\n", aux->dato.actividad_fisica);
        printf("Acostarse semana: %f\n", aux->dato.acostar_semana);
        printf("Acostarse finde: %f\n", aux->dato.acostar_finde);
        printf("Despertarse semana: %f\n", aux->dato.despertar_semana);
        printf("Despertarse finde: %f\n", aux->dato.despertar_finde);
        printf("Calidad de sueño: %d\n", aux->dato.calidad_sueño);

        aux = aux->sig;
    }
}
