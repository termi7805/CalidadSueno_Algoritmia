#ifndef LISTA_ESTUDIANTES_H
#define LISTA_ESTUDIANTES_H

#include "CalidadSueño.h"

typedef struct celdaEstudiantes{
    calidadDelSueño dato;
    struct celdaEstudiantes *sig;
    int id;  //lista[0] == id 0, lista[N] == id N
} celdaEstudiantes;

typedef struct listaEstudiantes{
    celdaEstudiantes *primero;
    celdaEstudiantes *ultimo;
} listaEstudiantes;


void iniciarLista(listaEstudiantes *);
bool esListaVacia(listaEstudiantes);
void añadirDato(listaEstudiantes *, calidadDelSueño);
listaEstudiantes cargarDatos();
void desencolarEstudiantes(listaEstudiantes *);
void inicializaMinMax (float [12], float [12], listaEstudiantes, calidadDelSueño);
void normalizar(listaEstudiantes *, calidadDelSueño *);
void imprimeDato(calidadDelSueño);
void imprimeListaEntera(listaEstudiantes);

#endif
