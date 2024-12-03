#include "listaordenadavecinos.h"
#include <math.h>
#include <stdlib.h>

void iniciarListaVecinos(listaOrdenadaVecinos *l)
{
	l->primero = NULL;
	l->ultimo = NULL;
	l->numeroVecinos = 0;
	l->maximo = 0;
}

void cambiarK(listaOrdenadaVecinos *l, int k)
{
	l->maximo = k; //K: numero de vecinos que se quieren guardar
}

bool estavacia(listaOrdenadaVecinos l)
{
	return l.primero == NULL;
}

bool estallena(listaOrdenadaVecinos l)
{
	return l.numeroVecinos == l.maximo;
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
	int tipo[10] = {0,0,0,0,0,0,0,0,0,0}; //Numero de vecinos por cada nivel de calidad de sueño
	int distancia[10] = {0,0,0,0,0,0,0,0,0}; //Distancia total de los vecinos por cada nivel de calidad de sueño
	celdaVecino *aux = l.primero;
	
	while(aux != NULL){
		
		nivel = aux->estudiante->dato.calidad_sueño;
		
		if (nivel >= 1 && nivel <= 10)
		{
			tipo[nivel-1]++;
			distancia[nivel-1] += aux->distancia;
		}
		
		aux = aux->siguiente;
	}
	
	int tipoPredominante = 0; //Nivel de calidad de sueño con mas frecuencia

	for (int i = 1; i<10; i++){ 
		
		if(tipo[i] > tipo[tipoPredominante])
		{
			tipoPredominante = i;
		}
		
		else if (tipo[i] == tipo[tipoPredominante]) //En caso de empate, se elige el que tenga mayor distancia
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
                eliminarConPos(l, l->numeroVecinos);
                insertar(l, c);
            }
        }

        else{
            if (nueva->distancia <= l->primero->distancia){

                nueva->siguiente = l->primero;
				l->primero = nueva;
				l->numeroVecinos++;
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
	celdaVecino *aux = l->primero;
	celdaVecino *ant = NULL;
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

		l->ultimo = ant;
		l->ultimo->siguiente = NULL;
		free(aux);
		l->numeroVecinos = l->numeroVecinos - 1;
	}
}	

listaOrdenadaVecinos distanciaMinima(calidadDelSueño sueño, listaEstudiantes datos, int K) //Crea lista de K vecinos cercanos
{
	listaOrdenadaVecinos vecinosCercanos;
	celdaEstudiantes * aux;
	celdaVecino nueva;
	iniciarListaVecinos(&vecinosCercanos);
	cambiarK(&vecinosCercanos, K);
	aux = datos.primero;
	while (aux != NULL)
	{
		nueva.distancia = distancia(sueño, aux->dato);
		if(deberiaEstarEnLaLista(vecinosCercanos, nueva.distancia))
		{
			nueva.id = aux->id - 1;
			nueva.distancia = distancia(sueño, aux->dato);
			nueva.estudiante = aux;
			insertar(&vecinosCercanos, nueva);
		}
		aux = aux->sig;
	}
	return vecinosCercanos;
}

float distancia(calidadDelSueño a, tipoElementoLista b) //Calcula la distancia euclidea entre dos elementos
{
    float suma = 0;
    suma += pow(a.año_universidad - b.año_universidad, 2);
    suma += pow(a.edad - b.edad, 2);
    suma += pow(a.genero - b.genero, 2);
    suma += pow(a.actividad_fisica - b.actividad_fisica, 2);
    suma += pow(a.calidad_sueño - b.calidad_sueño, 2);
    suma += pow(a.acostar_semana - b.acostar_semana, 2);
    suma += pow(a.acostar_finde - b.acostar_finde, 2);
    suma += pow(a.despertar_semana - b.despertar_semana, 2);
    suma += pow(a.despertar_finde - b.despertar_finde, 2);
    suma += pow(a.horas_sueño - b.horas_sueño, 2);
    suma += pow(a.horas_estudio - b.horas_estudio, 2);
    suma += pow(a.horas_pantalla - b.horas_pantalla, 2);
    suma += pow(a.cafeina - b.cafeina, 2);
    return sqrt(suma);
}
	











