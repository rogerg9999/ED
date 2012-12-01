#include <iostream>
#include  <string>
#include "cola.h"


cola::nodocola::nodocola(persona p){
	cliente=p;
	sig=NULL;
}

cola::cola(){
	cabeza=NULL;
	ultimo=NULL;
	elementos = 0;
	tatendido = 0;
};

bool cola::esvacia(){
	return cabeza==NULL;
};
//Añade una persona en la cola
void cola::anadir(persona p){
	cola::nodocola* nodo=new nodocola(p);
	if(esvacia())
		cabeza=nodo;
	else
		ultimo->sig=nodo;

	ultimo=nodo;
	elementos++;
};
//Devuelve un puntero a la primera persona de la cola
persona cola::primero(){
	if(esvacia())
		throw error("La cola esta vacia");
	else
		return cabeza->cliente;
};
//Elimina la primera persona de la cola
void cola::eliminar(){
	cola::nodocola * nodo;
	if(esvacia())
		throw error("Estas intentando eliminar un elemento de una cola vacia");
	else{
		nodo=cabeza;
		cabeza=cabeza->sig;
		if(cabeza==NULL)
			ultimo=NULL;
		nodo->sig=NULL;
		delete(nodo);
		elementos--;
		tatendido = 0;
	}

};

//Devuelve el numero de personas de la cola
int cola::cuantos(){
	return elementos;
};

void cola::atenderprimero(){
	tatendido++;
}

bool cola::ha_terminado_el_primero(){
	if(esvacia())
		throw error("No hay ningun elemento en la lista");

	return cabeza->cliente.fueatendido(tatendido);
};
