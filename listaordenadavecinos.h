#include <stdio.h>


#include "listaEstudiantes.h"


typedef struct celdavecino{
    int id;
    float distancia;
    Nodo * calidadDelSueño;
    struct celdavecino * siguiente;
}celdavecino;

typedef struct listaOrdenadaVecinos{
    celdavecino* primero;
    celdavecino* ultimo;
    int numerovecinos;
    int maximo;
}listaOrdenadaVecinos;


void iniciarlistavecinos(listaOrdenadaVecinos *);

void cambiarK(listaOrdenadaVecinos *,int );

bool estavacia(listaOrdenadaVecinos);

bool estallena(listaOrdenadaVecinos);

bool deberiaestarenlalista(listaOrdenadaVecinos , float );

int mediaVecinos(listaOrdenadaVecinos);

void insertar(listaOrdenadaVecinos *, celdavecino);

void eliminarporposicion(listaOrdenadaVecinos *,int);

listaOrdenadaVecinos distanciaminima(calidadDelSueño ,listaEstudiantes , int);

float distancia(calidadDelSueño, calidadDelSueño);


