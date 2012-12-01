#include <iostream>
#include <string>
#include "lista.h"

lista::nodolista::nodolista(int cod){
	caja = cola::cola();
	codigo = cod;
	sig = NULL;
}

lista::lista(){
	primero = NULL;
	longitud = 0;
}

bool lista::esvacia(){
	return primero == NULL;
}

int lista::cajasabiertas(){
	return longitud;
}

void lista::abrircaja(){
	lista::nodolista* nodo;
	if(esvacia()){
		nodo = new nodolista(1); 
		primero = nodo;
	}
	else{
		lista::nodolista* aux = primero;
		while(aux->sig != NULL && aux->codigo == aux->sig->codigo-1){
			aux = aux->sig;
		}
		nodo = new nodolista(aux->codigo+1);
		nodo->sig = aux->sig;
		aux->sig = nodo;
	}
	longitud++;
	return;
}

int lista::cajasvacias(){
	lista::nodolista* aux = primero;
	int vacias = 0;
	while(aux != NULL){
		if(aux->caja.esvacia())
			vacias ++;
		aux = aux->sig;
	}
	return vacias;
}

void lista::cerrarcaja(){
	if (esvacia())
		throw error("Estas intentando eliminar un elemnto de una lista vacia");
	lista::nodolista* aux = primero;
	
	if(cajasvacias() >= 2)
	{
		aux = primero;
		while(!aux->sig->caja.esvacia()){
			aux = aux->sig;
		}
		lista::nodolista* nodo = aux->sig;
		aux->sig = nodo->sig;
		nodo->sig = NULL;
		delete(nodo);
	}
	return;
}

lista::nodolista* lista::cajamasocupada(){
	nodolista* max = primero;
	nodolista* aux = primero->sig;
	while(aux!=NULL){
		if(max->caja.cuantos() < aux->caja.cuantos())
			max = aux;
		aux = aux->sig;
	}
	return max;
}

lista::nodolista* lista::cajamenosocupada(){
	if(esvacia())
		throw error("La lista es vacia");
	nodolista* min = primero;
	nodolista* aux = primero->sig;
	while(aux!=NULL){
		if(min->caja.cuantos() > aux->caja.cuantos())
			min = aux;
		aux = aux->sig;
	}
	return min;
}