#include "listaEstudiantes.h"
#include "listaordenadavecinos.h"

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
		
		return (distancia < l.ultimo->distancia);
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













