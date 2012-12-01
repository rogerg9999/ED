#include <iostream>
#include <string>
#include <conio.h>
#include "banco.h"
#include "cola.h"
#include "persona.h"
#include "util.h"

using namespace std;

int main()
{
	banco bank=banco();
	persona p1(1,"PAGOS",0,20);
	persona p3(3,"PAGOS",0,15);
	persona p2(2,"ACTUALIZAR",5,19);
	persona p4(4,"INGRESOS",7,23);
	persona p7(7,"PAGOS",9,16);
	persona p9(9,"INGRESOS",11,23);
	persona p8(8,"RECIBOS",14,31);
	persona p6(6,"ACTUALIZAR",18,14);
	persona p5(5,"TRANSFERENCIA",21,20);

	for(int i=0; i<horacierre; i++){
		
		switch(i){
		case 0:
			bank.llegada(p1);
			bank.llegada(p3);
			break;
		case 5:
			bank.llegada(p2);
			break;
		case 7:
			bank.llegada(p4);
			break;
		case 9:
			bank.llegada(p7);
			break;
		case 11:
			bank.llegada(p9);
			break;
		case 14:
			bank.llegada(p8);
			break;
		case 18:
			bank.llegada(p6);
			break;
		case 21:
			bank.llegada(p5);
			break;
		}

		bank.salida(); //Busca si en alguna cola hay un cliente que haya terminado su diligencia
		bank.escribir(); 
		bank.actualizaestado(); //Incrementa el reloj del banco
		_getch();
	}
	

	cout << "Fin del programa" << endl;
	_getch();

	return 0;
};
