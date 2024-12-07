#include "listaordenadavecinos.h"
#include <math.h>
#include <stdlib.h>

void iniciarListaVecinos(listaOrdenadaVecinos *lista)
{
	lista->primero = NULL;
	lista->ultimo = NULL;
	lista->numeroVecinos = 0;
	lista->maximo = 0;
}

void cambiarK(listaOrdenadaVecinos *lista, int k)
{
	lista->maximo = k; //K: numero de vecinos que se quieren guardar
}

bool estaVacia(listaOrdenadaVecinos lista)
{
	return lista.primero == NULL;
}

bool estaLlena(listaOrdenadaVecinos lista)
{
	return lista.numeroVecinos == lista.maximo;
}

bool deberiaEstarEnLaLista(listaOrdenadaVecinos lista, float distancia)
{
	if(!estaLlena(lista)){
		return true;
	}	
	
	else{
		return (distancia < (lista.ultimo->distancia)); //true: si es menor  false: si es mayor
	}
}

int mediaVecinos(listaOrdenadaVecinos l)
{
	if (estaVacia(l)){
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

	for (int i = 0; i<10; i++){
		
		if(tipo[i] > tipo[tipoPredominante])
		{
			tipoPredominante = i;
		}
		
		else if (tipo[i] == tipo[tipoPredominante]) //En caso de empate, se elige el que tenga menor distancia
		{
			if(distancia[i] < distancia[tipoPredominante])
			{
				tipoPredominante = i;
			}
		}
	}
	return tipoPredominante + 1; //+1 porque nuestro array va del 0-9
}

void insertarVecino(listaOrdenadaVecinos *l, celdaVecino c) //
{
    celdaVecino *nueva = (celdaVecino*)malloc(sizeof(celdaVecino));
    *nueva = c;
    
    if(estaVacia(*l)){
        l->primero = nueva;
        l->ultimo = nueva; 
        nueva->siguiente = NULL;
        l->numeroVecinos = l->numeroVecinos + 1;
    }

    else {

        if(estaLlena(*l)){
            if(deberiaEstarEnLaLista(*l, c.distancia)){
                eliminarConPos(l, l->numeroVecinos);
                insertarVecino(l, c);
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

void eliminarConPos(listaOrdenadaVecinos *l, int pos)//
{
	int i = 0;
	celdaVecino *aux = l->primero;
	celdaVecino *ant = NULL;
	pos = pos - 1;

	if (l->primero == l->ultimo && pos == 0) { //tenemos 1 elemento
        free(l->primero);
        l->primero = NULL;
        l->ultimo = NULL;
        l->numeroVecinos--;
        return;
    }

    while (aux != NULL && i < pos) {
        ant = aux;
        aux = aux->siguiente;
        i++;
    }

    if (aux == NULL) {
        printf("Posición no válida\n");
        return;
    }

    // Si el nodo a eliminar es el primero
    if (ant == NULL) {
        l->primero = aux->siguiente;
        if (l->primero == NULL) {
            l->ultimo = NULL; // Si la lista queda vacía
        }
    }
    // Si el nodo a eliminar es el último
    else if (aux->siguiente == NULL) {
        l->ultimo = ant;
        ant->siguiente = NULL;
    }
    // Si el nodo está en el medio
    else {
        ant->siguiente = aux->siguiente;
    }

    free(aux);
    l->numeroVecinos--;


	/*while(aux->siguiente != NULL){
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
	}*/
}

listaOrdenadaVecinos distanciaMinima(calidadDelSueño CS, listaEstudiantes lista, int K) //Crea lista de K vecinos cercanos
{
	listaOrdenadaVecinos vecinosCercanos;
	celdaEstudiantes *aux;
	celdaVecino nueva;

	iniciarListaVecinos(&vecinosCercanos);
	cambiarK(&vecinosCercanos, K);

	aux = lista.primero;
	while (aux != NULL)
	{
		float dist = distancia(CS, aux->dato);
		if(deberiaEstarEnLaLista(vecinosCercanos, dist))
		{
			nueva.id = aux->id - 1;
			nueva.distancia = distancia(CS, aux->dato);
			nueva.estudiante = aux;
			insertarVecino(&vecinosCercanos, nueva);
		}
		aux = aux->sig;
	}
	return vecinosCercanos;
}

float distancia(calidadDelSueño a, calidadDelSueño b) //Calcula la distancia euclidea entre dos elementos
{
    float suma = 0;
    suma += pow(a.año_universidad - b.año_universidad, 2);
    suma += pow(a.edad - b.edad, 2);
	suma += (a.genero == b.genero) ? 0 : 1;
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

void imprimirResultados(listaOrdenadaVecinos lista)
{
    celdaVecino * aux;
	int i = 1;

	aux = lista.primero;
    while (aux != NULL)
    {
        printf("La distancia a la calidad de sueño %d mas cercana ha sido %f, perteneciente a la posicion %d: \n", i, aux->distancia, aux->id);
        imprimeDato(aux->estudiante->dato);
        aux = aux->siguiente;
        i++;
    }

	printf("El nivel de calidad de sueño a comprobar ha resultado ser: %d\n\n", mediaVecinos(lista));
}

void desencolarVecinos(listaOrdenadaVecinos *lista)
{
    if (estaVacia(*lista)) {
        printf("No se puede desencolar de lista vacía\n");
        exit(-1);
    }

    celdaVecino *aux;
	aux = lista->primero;

    lista->primero = lista->primero->siguiente;

    if (lista->primero == NULL) {
        lista->ultimo = NULL;
    }

    lista->numeroVecinos = lista->numeroVecinos - 1;
    free(aux);
}
