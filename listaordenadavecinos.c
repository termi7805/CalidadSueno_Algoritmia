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
	
	
}













