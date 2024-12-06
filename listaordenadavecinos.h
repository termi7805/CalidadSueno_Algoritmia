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
    int maximo;
}listaOrdenadaVecinos;


void iniciarListaVecinos(listaOrdenadaVecinos *);

void cambiarK(listaOrdenadaVecinos *, int);

bool estavacia(listaOrdenadaVecinos);

bool estallena(listaOrdenadaVecinos);

bool deberiaEstarenLaLista(listaOrdenadaVecinos , float);

int mediaVecinos(listaOrdenadaVecinos);

void insertar(listaOrdenadaVecinos *, celdaVecino);

void eliminarConPos(listaOrdenadaVecinos *, int);

listaOrdenadaVecinos distanciaMinima(calidadDelSueño, listaEstudiantes, int);

float distancia(calidadDelSueño, tipoElementoLista);

void imprimirResultados(calidadDelSueño, listaOrdenadaVecinos);



#endif
