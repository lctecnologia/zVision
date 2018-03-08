/*
 * zComm.h
 *
 *  Created on: 04/09/2013
 *      Author: ztronics
 */

#ifndef ZCOMM_H_
#define ZCOMM_H_

#include "zIncludes.h"

class zComm {
public:
	zComm();
	virtual ~zComm();
	int sendReceive(char *cmd);
	void connect();
	void disconnect();
	void send(char *cmd);
	int sendCmd(char *cmd);
	int receiveMsg();
	char *ultCmd;
	char* frente = "f";
	char* esquerda = "e";
	char* re = "r";
	char* direita = "d";
	char* parar = "s";
	char* pegaLata = "p";
	char* volta = "m";
	char* braco = "b";
	char* despejar = "j";
	int port;
};

#endif /* ZCOMM_H_ */
