/*
 * zMovement.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ztronics
 */

#include "zMovement.h"

zMovement::zMovement() {
	// TODO Auto-generated constructor stub

}

zMovement::~zMovement() {
	// TODO Auto-generated destructor stub
}

void zMovement::andarFrente(int tempo) {

	zComm zConnect;
	zConnect.sendCmd(this->frente);

	sleep(tempo);

	zConnect.sendCmd(this->parar);

}

void zMovement::andarFrente() {

	zComm zConnect;
	zConnect.sendCmd(this->frente);

}

void zMovement::virarDireita(int tempo) {

	zComm zConnect;
	zConnect.sendCmd(this->direita);

	sleep(tempo);

	zConnect.sendCmd(this->parar);

}

void zMovement::virarDireita() {

	zComm zConnect;
	zConnect.sendCmd(this->direita);

}
void zMovement::meiaVolta() {

	zComm zConnect;
	zConnect.sendCmd(this->volta);

}

void zMovement::despejarLata() {

	zComm zConnect;
	zConnect.sendCmd(this->despejar);

}

void zMovement::virarEsquerda(int tempo) {

	zComm zConnect;
	zConnect.sendCmd(this->esquerda);

	sleep(tempo);

	zConnect.sendCmd(this->parar);

}

void zMovement::reRobo(int tempo) {

	zComm zConnect;
	zConnect.sendCmd(this->re);


	sleep(tempo);
	//sleep(tempo);

	zConnect.sendCmd(this->parar);

}

void zMovement::virarEsquerda() {

	zComm zConnect;
	zConnect.sendCmd(this->esquerda);

}

void zMovement::reRobo() {

	zComm zConnect;
	zConnect.sendCmd(this->re);

}

void zMovement::pararRobo() {

	zComm zConnect;
	zConnect.sendCmd(this->parar);

}

void zMovement::pegarObjeto() {

	zComm zConnect;
	int msg = zConnect.receiveMsg();
	cout << endl << "Msg: " << msg << endl;
	//zConnect.sendCmd(this->pegaLata);

}

int zMovement::pegarLata() {

	zComm zConnect;
	return zConnect.sendCmd(this->pegaLata);

}

