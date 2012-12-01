#ifndef BANCO_H_
#define BANCO_H_

#include <iostream>
#include <string>
#include "cola.h"
#include "persona.h"

using namespace std;

const int maxcajas = 4;     // Total de cajas en el banco
const int horacierre = 360; // Hora de cierre del banco

class banco
{
private:
	cola caja[maxcajas];   // Cajas disponibles para atender
	int totalclientes;     // Clientes que han entrado en el banco
	int tiempototal;       // Tiempo total que pasan los clientes en el banco
	int horaactual;        //Reloj del banco
	int tiempoatendido[maxcajas]; //Tiempo que lleva siendo atendido el primer cliente de cada caja
	void inicia_tiempoatendido(); //Inicia el contador de cada caja
	void inicia_colas();    //LLama al constructor de las colas
	int indice_colamascorta(); //Busca la caja con la cola mas corta
public:
	banco();                   // Constructor
	void escribir();           // Escribe la situación actual del banco
	void llegada(persona p);   // Gestiona la llegada de una persona
	void salida();             // Gestiona la salida de una persona
	int clientessinatender();  // Devuelve los clientes sin atender
	void actualizaestado();    // Actualiza el estado del banco
	float tiempomedio();       // Tiempo medio de espera de los clientes
};

#endif
