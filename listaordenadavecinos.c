#include "listaEstudiantes.h"
#include "listaordenadavecinos.h"
#include "CalidadSueño.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void iniciarlistavecinos(listaOrdenadaVecinos *l){
	
	l->primero = NULL;
	l->ultimo = NULL;
	l->numerovecinos = 0;
	l->maximo = 0;
}


void cambiarK(listaOrdenadaVecinos *l,int k){
	
	l->maximo = k;
}

bool estavacia(listaOrdenadaVecinos l){
	
	return l.primero == NULL;
}

bool estallena(listaOrdenadaVecinos l){
	
	return l.numerovecinos == l.maximo;
}

bool deberiaestarenlalista(listaOrdenadaVecinos l, float d){
	
	if(!estallena(l)){
		
		return true;
	}	
	
	else{
		
		return (d < l.ultimo->distancia);
	}
}

int mediaVecinos(listaOrdenadaVecinos l){
	
	if (estavacia(l)){
		
		printf("ERROR: LA LISTA ESTA VACIA");
		exit(-1);
	}
	
	int tipo[10] = {0};
	int distancia[10] = {0};
	celdavecino *aux = l.primero;
	
	while(aux != NULL){
		
		int nivel = aux->calidadDelSueño->calidad_sueño;
		
		if (nivel >= 1 && nivel <= 10){
			
			tipo[nivel-1]++;
			distancia[nivel-1] += aux->distancia;
			
		}
		
		aux = aux->siguiente;
	}
	
	int tipoPredominante = 0;
	for (int i = 1; i<10; i++){
		
		if(tipo[i] > tipo[tipoPredominante]){
				
			tipoPredominante = i;
		}
		
		else if (tipo[i] == tipo[tipoPredominante]){
			
			if(distancia[i] > distancia[tipoPredominante]){
				
				tipoPredominante = i;
			}
		}
			
	}
	
	return tipoPredominante + 1;
}

void insertar(listaOrdenadaVecinos *l, celdavecino c){
	
    celdavecino * nueva = (celdavecino*)malloc(sizeof(celdavecino));
    *nueva = c;
    
    if(estavacia(*l)){
        l->primero = nueva;
        l->ultimo = nueva; 
        nueva->siguiente = NULL;
        l->numerovecinos++;
    }
    else {
        if(estallena(*l)){
            if(deberiaestarenlalista(*l, c.distancia) ){
				
                eliminarporposicion(l, l->numerovecinos);
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
				l->numerovecinos++;
			}
            else{	  
				
                celdavecino * ant = NULL;
				celdavecino * aux = l->primero;
				while (aux != NULL && aux->distancia < (nueva->distancia)){
					
					ant = aux;
					aux = aux->siguiente;
				}
				
				nueva->siguiente = aux;
				if (ant != NULL){
					
					ant->siguiente = nueva;
				}
				l->numerovecinos++;
			}
        }
    }
}

void eliminarporposicion(listaOrdenadaVecinos *l ,int pos){

	int i = 0;
	celdavecino *aux = l->primero;
	celdavecino *ant = NULL;
	pos--;
	while(aux->siguiente != NULL && aux != NULL){
		ant = aux;
		aux = aux->siguiente;
		i++;
	}

	if(ant == NULL){
		
		l->primero = NULL;
		l->ultimo = NULL;
		free(aux);
		l->numerovecinos--;
	}
	else{
		
		l->ultimo = ant
		l->ultimo->siguiente = NULL;
		free(aux);
		l->numerovecinos--;
	}
}	

listaOrdenadaVecinos distanciaminima(calidadDelSueño sueño,listaEstudiantes BasedeDatos, int K){
	
	listaOrdenadaVecinos vecinoscercanos;
	Nodo * aux;
	celdavecino nueva;
	iniciarlistavecinos(&vecinoscercanos);
	cambiarK(&vecinoscercanos, K);
	aux = BasedeDatos.primero;
	while (aux != NULL){
		
		nueva.distancia = distancia(sueño, aux->calidad_sueño);
		if(deberiaestarenlalista(vecinoscercanos, nueva.distancia)){
			
			nueva.id = aux->id - 1;
			nueva.distancia = distancia(sueño, aux->calidad_sueño);
			nueva.calidadDelSueño = aux;
			insertar(&vecinoscercanos, nueva);
		}
		aux = aux->siguiente;
	}
	return vecinoscercanos;
}

float distancia(calidadDelSueño a, calidadDelSueño b){
	
	return fabs(a.calidad_sueño - b.calidad_sueño);
}
	











