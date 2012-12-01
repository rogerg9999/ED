#include <iostream>
#include <string>
#include <conio.h>
#include "persona.h"
#include "util.h"

using namespace std;

persona::persona(){

};

persona::persona(int cli,string tar, int hora, int dur){
	idcaja='*';
	idcliente=cli;
	tarea=tar;
	horaevento=hora;
	duracion=dur;
};
//Escribe los campos de una persona
void persona::escribir(){
	int x= util::getX();
	int y = util::getY();
	cout << "El cliente " << idcliente << endl;
	util::gotoxy(x,y+1);
	cout<< " viene a " << tarea << endl;
	util::gotoxy(x,y+2);
	cout<< " hora del evento " << horaevento << endl;
	util::gotoxy(x,y+3);
	cout<< " duracion " << duracion << endl;
	util::gotoxy(x,y+4);
	cout<< "en la caja: "<< idcaja << endl;
		return;
};

void persona::poneridcaja(char caja){
	idcaja = caja;
};

//Devuelve true si el cliente ya a terminado de ser atendido
bool persona::fueatendido(int tiempoatendido){
	return duracion==tiempoatendido;
};
//Tiempo que lleva en el banco la persona
int persona::tiempoenelbanco(int horaactual){
	return horaactual-horaevento;
}



