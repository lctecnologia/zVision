/*
 * zComm.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ztronics
 */

#include "zComm.h"
#include <termios.h>

zComm::zComm() {
	// TODO Auto-generated constructor stub

}

zComm::~zComm() {
	// TODO Auto-generated destructor stub
}

//Comandos do Robo
//Frente - f
//Direita - d
//Esquerda - e
//Parar - s
//Pegar lata - p
//Concluir - recebe - z

int zComm::receiveMsg() {

	cout << endl;

	int fd1;

	char * buff = new char[254];

	fcntl(fd1, F_SETFL, O_NONBLOCK);

	fd1 = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

	struct termios options;

	if (fd1 == -1) {
		cout << "Error connnecting";
	} else {

		fcntl(fd1, F_SETFL);            // Configure port reading
		tcgetattr(fd1, &options);       // Get the current options for the port
		cfsetispeed(&options, B9600);    // Set the baud rates to 9600
		cfsetospeed(&options, B9600);

		options.c_cflag |= (CLOCAL | CREAD); // Enable the receiver and set local mode
		options.c_cflag &= ~PARENB;             // No parity bit
		options.c_cflag &= ~CSTOPB;             // 1 stop bit
		options.c_cflag &= ~CSIZE;              // Mask data size
		options.c_cflag |= CS8;                // Select 8 data bits
		options.c_cflag &= ~CRTSCTS;            // Disable hardware flow control

		// Enable data to be processed as raw input
		options.c_lflag &= ~(ICANON | ECHO | ISIG);

		// Set the new attributes
		tcsetattr(fd1, TCSANOW, &options);

		bool STOP = false;

		buff[0] = '0';
		while (STOP == false) {
			int res = read(fd1, buff, 255);
			buff[res] = 0; /* set end of string, so we can
			 printf */
			printf(":%s:%d\n", buff, res);
			sleep(1);

			if (buff[0] == 'z')
				STOP = true;
		}

	}

	close(fd1);

	cout << endl;

	return 0;

}

int zComm::sendReceive(char *cmd) {
	cout << endl;

	int fd1;

	int fd2;

	char * buff = new char[2];

	int wr, rd, nbytes, tries;

	fcntl(fd1, F_SETFL, O_NONBLOCK);

	fd1 = open("/dev/ttyUSB0", O_RDWR | O_NONBLOCK);

	if (fd1 == -1) {
		cout << "Error connnecting";
	} else {
		fcntl(fd1, F_SETFL, 0);

		//wr=write(fd1,"\r\nch2.gettemp\r\n",15);

		//wr=write(fd1,cmd,1);

		//read a bunch of lines
		for (int i = 0; i < 10; i++) {

			//read a single line:

			string data = "";

			rd = 0;
			int bytes = 0;
			do {
				cout << endl << "bytes: " << bytes << endl;
				bytes = read(fd1, buff, 1);
				cout << endl << "bytes: " << bytes << endl;

				if (buff[0] == '\r') {
					read(fd1, buff, 1); //read the following char which should be \n
					break;
				} else {
					data.append(1, buff[0]);
				}
			} while (bytes > 0);

			cout << endl << "buff: " << data << endl;
		}

	}

	close(fd1);

	cout << endl;
	return 0;

}

void zComm::connect() {
	fcntl(port, F_SETFL, O_NONBLOCK);

	printf ("ABRINDO SERIAL\n");

	port = open("/dev/ttyUSB0", O_RDWR | O_NONBLOCK);

	if (port == -1) {
		printf ("ERRO SERIAL\n");
		cout << "Error connnecting";
		sleep(1);

	}
}

void zComm::disconnect() {

	close(port);
}

void zComm::send(char *cmd) {

	fcntl(port, F_SETFL, 0);

	//wr=write(fd1,"\r\nch2.gettemp\r\n",15);

	int wr = write(port, cmd, 1);

}

int zComm::sendCmd(char *cmd) {

	if (this->ultCmd != cmd) {
		cout << endl;

		int fd1;

		int fd2;

		char * buff = new char[2];

		int wr, rd, nbytes, tries;

		fcntl(fd1, F_SETFL, O_NONBLOCK);

		fd1 = open("/dev/ttyUSB0", O_RDWR | O_NONBLOCK);

		if (fd1 == -1) {
			cout << "Error connnecting";
		} else {
			fcntl(fd1, F_SETFL, 0);

			//wr=write(fd1,"\r\nch2.gettemp\r\n",15);

			wr = write(fd1, cmd, 1);

			this->ultCmd = cmd;

			cout << "Comando Enviado!";

		}

		close(fd1);

		cout << endl;

	}

	return 0;

}

