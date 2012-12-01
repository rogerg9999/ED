#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include <string>
#include "persona.h"
#include "cola.h"

using namespace std;


class lista
{
	friend class banco;	// el banco puede usar los atributos de las cajas
	
	class nodolista		// clase para gestionar los nodos de las listas
	{
	public:
		cola caja;			// cola de gente en la caja
		int codigo;			// código identificador de la caja
		nodolista* sig;		// puntero al siguiente nodo
		nodolista(int cod); // Constructor del nodo
	};

private:
	nodolista* primero;		// primer nodo de la lista
	int longitud;			// cantidad de nodos de la lista
public:
	lista();				// Constructor de la lista de cajas
	void abrircaja();		// Añadir ordenadamente una caja a la lista
	void cerrarcaja();		// Quitar una caja si hay dos o más cajas vacías
	int cajasabiertas();	// Devuelve el total de cajas disponibles
	bool esvacia();			// Comprobar si la lista está vacía
	nodolista* cajamasocupada();	// nodo de la caja con más gente
	nodolista* cajamenosocupada();	// nodo de la caja con menos gente
	
	void escribirlista();	// Escribe el estado de la lista de cajas
	void atender1min();		// Atiende un minuto en todas las cajas abiertas

	int cajasvacias();     //Devuelve el numero de cajas que estan vacias
};

#endif /* LISTA_H_ */
