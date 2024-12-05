#ifndef LISTA_ESTUDIANTES_H
#define LISTA_ESTUDIANTES_H

#include "CalidadSueño.h"

typedef calidadDelSueño tipoElementoLista;

typedef struct celdaEstudiantes{
    tipoElementoLista dato;
    struct celdaEstudiantes *sig;
    int id;  //lista[0] == id 0, lista[N] == id N //creo que se puede quitar
} celdaEstudiantes;

typedef struct listaEstudiantes{
    celdaEstudiantes *primero;
    celdaEstudiantes *ultimo;
} listaEstudiantes;


void iniciarLista(listaEstudiantes *);
bool esListaVacia(listaEstudiantes);
void añadirDato(listaEstudiantes *, tipoElementoLista);
void desencolar(listaEstudiantes *);
listaEstudiantes cargarDatos();
void inicializaMinMax (int *, int *, listaEstudiantes, calidadDelSueño);
void normalizar(listaEstudiantes *, calidadDelSueño *);

void imprimeDato(tipoElementoLista );

//void imprimeDato(tipoElementoLista);
void imprimeListaEntera(listaEstudiantes);

#endif
