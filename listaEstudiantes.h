
#include "calidadSueño.h"

typedef struct calidadDelSueño tipoElementoLista;

typedef struct celdaEstudiantes{
    tipoElementoLista dato;
    struct celdaEstudiantes *sig;
    int id;
} celdaEstudiantes;

typedef struct listaEstudiantes{
    celdaEstudiantes *primero;
    celdaEstudiantes *ultimo;
} listaEstudiantes;


void iniciarLista(listaEstudiantes *);
bool esListaVacia(listaEstudiantes);
void añadirDato(listaEstudiantes *, tipoElementoLista);
void eliminarDatoPrimero(listaEstudiantes *);
listaEstudiantes cargarDatos();
void imprimeDato(tipoElementoLista);
void imprimeListaEntera(listaEstudiantes);
