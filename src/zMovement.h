/*
 * zMovement.h
 *
 *  Created on: 04/09/2013
 *      Author: ztronics
 */

#ifndef ZMOVEMENT_H_
#define ZMOVEMENT_H_

#include "zIncludes.h"

class zMovement {
public:
	zMovement();
	virtual ~zMovement();
	void andarFrente(int tempo);
	void andarFrente();
	void pararRobo();
	void pegarObjeto();
	void virarDireita();
	void meiaVolta();
	void despejarLata();
	void virarDireita(int tempo);
	void virarEsquerda();
	void virarEsquerda(int tempo);
	void reRobo(int tempo);
	void reRobo();
	int pegarLata();

private:
	//Comandos do Robo
	//Frente - f
	//Direita - d
	//Esquerda - e
	//Parar - s
	//Pegar lata - p
	//Concluir - recebe - z

	char* frente = "f";
	char* esquerda = "e";
	char* re = "r";
	char* direita = "d";
	char* parar = "s";
	char* pegaLata = "p";
	char* volta = "m";
	char* braco = "b";
	char* despejar = "j";


};

#endif /* ZMOVEMENT_H_ */
