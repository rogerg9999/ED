#include <iostream>
#include <string>
#include "banco.h"
#include "util.h"


using namespace std;

banco::banco(){
	inicia_colas(); 
	inicia_tiempoatendido();
	totalclientes=0;
	tiempototal=0;
	horaactual=0;
};

//llama al consrtuctor de cola en cada posicion del array caja[]
void banco::inicia_colas(){
		for(int i=0; i<maxcajas; i++){
			caja[i]=cola::cola();
		}
};

//Pone el contador de atencion de cada caja a cero
void banco::inicia_tiempoatendido(){
	for(int i=0; i<maxcajas; i++){
		tiempoatendido[i]=0;
	}
};

//Busca la posicion de la cola mas corta.
int banco::indice_colamascorta(){
	int min=caja[0].cuantos();
	int index=0;
	for(int i=1; i<maxcajas; i++){
		if(caja[i].cuantos() < min){
			min=caja[i].cuantos();
			index=i;
		}
	}
	return index;
};

//Simula la llegada de una persona al banco
void banco::llegada(persona p){
	int icolamascorta=indice_colamascorta();
	p.poneridcaja((char)icolamascorta+48);
	caja[icolamascorta].anadir(p);
	totalclientes++;
};

//Busca en todas las colas si el primer cliente dentro de ella
//a sido atendido completamente.
void banco::salida(){	
	for(int i=0; i<maxcajas; i++){
		try{
			if(caja[i].cuantos()>0 && caja[i].ha_terminado_el_primero()){
				tiempototal+=caja[i].primero().tiempoenelbanco(horaactual);
				caja[i].eliminar();
			}
		}
		catch(error e){
		}
	}
};

//Incrementa el reloj del banco y el tiempo que el primer cliente
//de cada cola lleva siendo atendido
void banco::actualizaestado(){
	horaactual++;
	for(int i=0; i<maxcajas; i++){
		if(caja[i].cuantos() > 0){
			caja[i].atenderprimero();
		}
	}
};

//Tiempo medio que todos los clientes pasan dentro del banco
float banco::tiempomedio(){
	return (float)tiempototal/totalclientes;;
};

//Los clientes que esperan por ser atendidos
int banco::clientessinatender(){
	int enespera=0;
	for(int i=0; i<maxcajas; i++){
		if(caja[i].cuantos() > 1){
			enespera += caja[i].cuantos()-1;
		}
	}
	return enespera;
};

//Escribe el estado actual del banco y de los clientes que estan siendo atendidos
//en cada caja
void banco::escribir(){
	util::clrscr();
	for(int i=0; i<maxcajas; i++){
		util::gotoxy(i*20,0);
		cout<<"Caja "<<i;
		
		if(caja[i].cuantos()>0){
			cout<<"\n";
			util::gotoxy(i*20,5);
			cout<<"Tiempo atendido: "<<tiempoatendido[i]<<endl;
			util::gotoxy(i*20,6);
			caja[i].primero().escribir();
		}    
		else {
			util::gotoxy(i*20,10);
			cout<<" vacia "<< endl;
		}
	}
	    util::gotoxy(0,18);
		cout.precision(4);
		cout<<"Clientes que han entrado en el banco: " << totalclientes << endl
		<<"Clientes sin atender: " << clientessinatender() << endl
		<<"Tiempo medio: " << tiempomedio() << endl
		<<"Hora actual: "<<horaactual<<endl
	    <<"Estado de las cajas "<< endl;
}