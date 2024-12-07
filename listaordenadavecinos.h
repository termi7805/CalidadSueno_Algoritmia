#ifndef LISTAORDENADAVECINOS_H
#define LISTAORDENADAVECINOS_H
#include "listaEstudiantes.h"

typedef struct celdaVecino{
    int id;
    float distancia;
    celdaEstudiantes *estudiante;
    struct celdaVecino *siguiente;
}celdaVecino;

typedef struct listaOrdenadaVecinos{
    celdaVecino* primero;
    celdaVecino* ultimo;
    int numeroVecinos;
    int maximo; //k
}listaOrdenadaVecinos;


void iniciarListaVecinos(listaOrdenadaVecinos *);

void cambiarK(listaOrdenadaVecinos *, int);

bool estaVacia(listaOrdenadaVecinos);

bool estaLlena(listaOrdenadaVecinos);

bool deberiaEstarEnLaLista(listaOrdenadaVecinos , float);

int mediaVecinos(listaOrdenadaVecinos);

void insertarVecino(listaOrdenadaVecinos *, celdaVecino);

void eliminarConPos(listaOrdenadaVecinos *, int);

listaOrdenadaVecinos distanciaMinima(calidadDelSueño, listaEstudiantes, int);

float distancia(calidadDelSueño, calidadDelSueño);

void imprimirResultados(listaOrdenadaVecinos);

void desencolarVecinos(listaOrdenadaVecinos *);



#endif
