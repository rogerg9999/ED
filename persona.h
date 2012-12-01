#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class persona
{
private:
	char idcaja;			// caja en la que se coloca
	int idcliente;			// c�digo identificador de cliente
	string tarea;			// descripci�n de la tarea
	int horaevento;			// hora prevista de inicio
	int duracion;			// duraci�n del servicio
public:
	persona();
	persona(int cli,string tar, int hora, int dur);
	void escribir();        
	void poneridcaja(char caja);
	bool fueatendido(int tiempoatendido);    //Devuelve true si el cliente ya ha sido atendido completamente
	int tiempoenelbanco(int horaactual); //Tiempo que lleva en el banco 
};

#endif
