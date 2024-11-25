#include "listaEstudiantes.h"
#include "listaordenadavecinos.h"
#include "CalidadSueño.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void iniciarListaVecinos(listaOrdenadaVecinos *l)
{
	l->primero = NULL;
	l->ultimo = NULL;
	l->numerovecinos = 0;
	l->maximo = 0;
}

void cambiarK(listaOrdenadaVecinos *l, int k)
{
	l->maximo = k;
}

bool estavacia(listaOrdenadaVecinos l)
{
	return l.primero == NULL;
}

bool estallena(listaOrdenadaVecinos l)
{
	return l.numerovecinos == l.maximo;
}

bool deberiaEstarEnLaLista(listaOrdenadaVecinos l, float distancia)
{
	if(!estallena(l)){
		return true;
	}	
	
	else{
		return (distancia < l.ultimo->distancia); //true: si es menor  false: si es mayor
	}
}

int mediaVecinos(listaOrdenadaVecinos l)
{
	if (estavacia(l)){
		printf("ERROR: Lista de vecinos vacia\n");
		exit(-1);
	}
	
	int nivel;
	int tipo[10] = {0,0,0,0,0,0,0,0,0,0};
	int distancia[10] = {0,0,0,0,0,0,0,0,0};
	celdavecino *aux = l.primero;
	
	while(aux != NULL){
		
		nivel = aux->calidadDelSueño->calidad_sueño;
		
		if (nivel >= 1 && nivel <= 10)
		{
			tipo[nivel-1]++;
			distancia[nivel-1] += aux->distancia;
		}
		
		aux = aux->siguiente;
	}
	
	int tipoPredominante = 0;

	for (int i = 1; i<10; i++){
		
		if(tipo[i] > tipo[tipoPredominante])
		{
			tipoPredominante = i;
		}
		
		else if (tipo[i] == tipo[tipoPredominante])
		{
			if(distancia[i] > distancia[tipoPredominante])
			{
				tipoPredominante = i;
			}
		}
	}
	return tipoPredominante + 1;
}

void insertar(listaOrdenadaVecinos *l, celdaVecino c)
{
    celdaVecino *nueva = (celdaVecino*)malloc(sizeof(celdaVecino));
    *nueva = c;
    
    if(estavacia(*l)){
        l->primero = nueva;
        l->ultimo = nueva; 
        nueva->siguiente = NULL;
        l->numeroVecinos = l->numeroVecinos + 1;
    }

    else {

        if(estallena(*l)){
            if(deberiaEstarEnLaLista(*l, c.distancia) ){
                eliminarConPos(l, l->numerovecinos);
                insertar(l, c);
            }
        }

        else{
            if (nueva->distancia <= l->primero->distancia){

                nueva->siguiente = l->primero;
				l->primero = nueva;
				l->numerovecinos++;
			}
			else if (nueva->distancia >= l->ultimo->distancia){

                l->ultimo->siguiente = nueva;
                l->ultimo = nueva;
				nueva->siguiente = NULL;
				l->numeroVecinos = l->numeroVecinos + 1;
			}
            else{	  

                celdaVecino *ant = NULL;
				celdaVecino *aux = l->primero;
				while ((aux->distancia) < (nueva->distancia)){
					ant = aux;
					aux = aux->siguiente;
				}

				nueva->siguiente = aux;
				ant->siguiente = nueva;
				l->numeroVecinos = l->numeroVecinos + 1;
			}
        }
    }
}

void eliminarConPos(listaOrdenadaVecinos *l, int pos)
{
	int i = 0;
	celdavecino *aux = l->primero;
	celdavecino *ant = NULL;
	pos = pos - 1;

	while(aux->siguiente != NULL && aux != NULL){
		ant = aux;
		aux = aux->siguiente;
		i++;
	}

	if(ant == NULL){

		l->primero = NULL;
		l->ultimo = NULL;
		free(aux);
		l->numeroVecinos = l->numeroVecinos - 1;
	}
	else{

		l->ultimo = ant
		l->ultimo->siguiente = NULL;
		free(aux);
		l->numeroVecinos = l->numeroVecinos - 1;
	}
}	

listaOrdenadaVecinos distanciaminima(calidadDelSueño sueño, listaEstudiantes datos, int K)
{
	listaOrdenadaVecinos vecinosCercanos;
	celdaEstudiantes * aux;
	celdavecino nueva;
	iniciarListaVecinos(&vecinoscercanos);
	cambiarK(&vecinosCercanos, K);
	aux = datos.primero;
	while (aux != NULL)
	{
		nueva.distancia = distancia(sueño, aux->calidad_sueño);
		if(deberiaEstarEnLaLista(vecinosCercanos, nueva.distancia))
		{
			nueva.id = aux->id - 1;
			nueva.distancia = distancia(sueño, aux->calidad_sueño);
			nueva.calidadDelSueño = aux;
			insertar(&vecinosCercanos, nueva);
		}
		aux = aux->siguiente;
	}
	return vecinoscercanos;
}

float distancia(calidadDelSueño a, calidadDelSueño b)
{
	return fabs(a.calidad_sueño - b.calidad_sueño);  //no se si esta bien (si no hay que restar todos los valores 1 por 1)
}
	











