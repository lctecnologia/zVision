//============================================================================
// Name        : zVision.cpp
// Author      : Leonardo Costa
// Version     :
// Copyright   : LC Software
// Description : Componente de Manipulação da Visão Robótica C++, Ansi-style
//============================================================================

#include <iostream>
#include "zDetect.h"

bool backprojMode = false;
bool selectObject = false;
int trackObject = 0;
bool showHist = true;
Point origin;
Rect selection;
int vmin = 10, vmax = 256, smin = 30;
Mat image;
zDetect zDetec;
zMovement zMov;
bool achouLata = false;
bool achouObstaculo = false;
bool achouCesto = false;
int contAcao = 0;
int contNaoAchou = 0;
int totalLatas = 20;
int nLatas = 0;
bool obstaculo = false;
bool procurando = true;
bool andando = false;
int acao = 0;
int contMov = 0;
zComm conn;

const char* keys = { "{1|  | 0 | camera number}" };

//This function threshold the HSV image and create a binary image
IplImage* GetThresholdedImage(IplImage* imgHSV) {
	IplImage* imgThresh = cvCreateImage(cvGetSize(imgHSV), IPL_DEPTH_8U, 1);
	cvInRangeS(imgHSV, cvScalar(170, 160, 60), cvScalar(180, 256, 256),
			imgThresh);
	return imgThresh;
}

static void onMouse(int event, int x, int y, int, void*) {

	if (event == CV_EVENT_MOUSEMOVE) {
		zDetec.mouse.x = x;
		zDetec.mouse.y = y;
	}

}

void testeMovment() {
	printf("Teste Pegar Lata\n");
	zMov.andarFrente(5);
	printf("Virando Direita 2 segundos\n");
	zMov.virarDireita(3);
	printf("Virando Esquerda 2 segundos\n");
	zMov.virarEsquerda(5);
	zMov.pararRobo();
	//printf("Pegar lata\n");
	zMov.pegarObjeto();
	//int ret = zMov.pegarLata();

	//zMov.pegarObjeto();

	//printf("Pegar lata result %i\n",&ret);

}

int zVisionCV() {
	int ret = 0;

	CvCapture* capture = 0;

	capture = cvCaptureFromCAM(0);
	if (!capture) {
		printf("Capture failure\n");
		return -1;
	}

	IplImage* frame = 0;

	cvNamedWindow("Video");

	//iterate through each frames of the video
	while (true) {

		frame = cvQueryFrame(capture);
		if (!frame)
			break;

		frame = cvCloneImage(frame);

		cvShowImage("Video", frame);

		//Clean up used images

		cvReleaseImage(&frame);

		//Wait 50mS
		int c = cvWaitKey(10);
		//If 'ESC' is pressed, break the loop
		if ((char) c == 27)
			break;
	}

	cvDestroyAllWindows();
	cvReleaseCapture(&capture);

	return ret;
}

bool procuraLata() {

	printf("Procura posição (%d,%d)\n", zDetec.posxL, zDetec.posyL);

	printf("Ultima posição (%d,%d)\n", zDetec.lastxL, zDetec.lastyL);

	if (zDetec.lastxL > 11 && zDetec.lastyL > 11 && zDetec.posxL > 11
			&& zDetec.posyL > 11 && achouLata == false) {
		printf("Achou Lata\n");
		achouLata = true;

	} else if (zDetec.lastxL > 11 && zDetec.lastyL > 11 && zDetec.posxL > 11
			&& zDetec.posyL > 11 && achouLata == true) {
		printf("Achou Lata\n");
		//zMov.pegarObjeto();
		achouLata = true;

	}

	else if (zDetec.lastxL < 11 && zDetec.lastyL < 11 && zDetec.posxL < 11
			&& zDetec.posyL < 11 && achouLata == true) {
		printf("Pegando a  Lata\n");
		zMov.pegarObjeto();

	}

	else {

		achouLata = false;
		printf("Não achou parar Robô\n");
		zMov.pararRobo();

		if (totalLatas != nLatas) {
			printf("Ainda Falta Latas para Pegar\n");
		}

		if (contNaoAchou == 4) {
			contNaoAchou = 0;
			zMov.andarFrente(1);
		} else {
			zMov.virarDireita(1);
		}
	}

	contNaoAchou++;
	return achouLata;

}

bool procuraObstaculo() {

	printf("Procura posição (%d,%d)\n", zDetec.posxL, zDetec.posyL);

	printf("Ultima posição (%d,%d)\n", zDetec.lastxL, zDetec.lastyL);

	if (zDetec.lastxL > 0 && zDetec.lastyL > 0 && zDetec.posxL > 0
			&& zDetec.posyL > 0 && achouLata == false) {
		printf("Achou OBSTACULO Fazer Meia Volta\n");
		//zMov.virarEsquerda(7);

		return true;
	}

	else {
		return false;
	}

}

bool procuraCesto() {

	printf("Procura posição (%d,%d)\n", zDetec.posxL, zDetec.posyL);

	printf("Ultima posição (%d,%d)\n", zDetec.lastxL, zDetec.lastyL);

	if (zDetec.lastxL > 0 && zDetec.lastyL > 0 && zDetec.posxL > 0
			&& zDetec.posyL > 0 && achouLata == false) {
		printf("Achou OBSTACULO Fazer Meia Volta\n");
		//zMov.virarEsquerda(7);

		if (zDetec.area > 200) {
			return true;
		}

	}

	else {
		return false;
	}

}

bool procuraLataBool() {

	//printf("Procura posição (%d,%d)\n", zDetec.posxL, zDetec.posyL);

	//printf("Ultima posição (%d,%d)\n", zDetec.lastxL, zDetec.lastyL);

	if (zDetec.lastxL > 11 && zDetec.lastyL > 11 && zDetec.posxL > 11
			&& zDetec.posyL > 11 && achouLata == false) {
		printf("Achou LATA\n");
		//zMov.virarEsquerda(7);
		if (zDetec.area > 200) {
			achouLata = true;
			return true;
		} else {
			return false;
		}

	}

	else {
		achouLata = false;
		printf("NAO Achou LATA\n");
		return false;
	}

}

int zVisionStart(int argc, const char** argv) {
	int ret = 0;

	VideoCapture cap;
//VideoCapture cap1;
	Rect trackWindow;
	int hsize = 16;
	float hranges[] = { 0, 180 };
	const float* phranges = hranges;
	CommandLineParser parser(argc, argv, keys);
	int camNum = parser.get<int>("4");

	vector<Vec3f> result;

	cap.open(camNum);

	if (!cap.isOpened()) {
		cout << "***Não foi possível inicializar a Câmera...***\n";
		cout << "Parâmetros Informados: \n";
		parser.printParams();
		return -1;
	}

	namedWindow("Histogram", 0);
	namedWindow("zVision", 0);

	Mat frame, hsv, hue, mask, hist, histimg = Mat::zeros(200, 320, CV_8UC3),
			backproj;
	bool paused = false;

	for (;;) {
		if (!paused) {
			cap >> frame;
			if (frame.empty())
				break;
		}

		frame.copyTo(image);

		if (!paused) {

			cvtColor(image, hsv, CV_BGR2HSV);

			//zDetec.dtCirculos(hsv, result);

			if (trackObject) {
				int _vmin = vmin, _vmax = vmax;

				inRange(hsv, Scalar(0, smin, MIN(_vmin,_vmax)),
						Scalar(180, 256, MAX(_vmin, _vmax)), mask);
				int ch[] = { 0, 0 };
				hue.create(hsv.size(), hsv.depth());
				mixChannels(&hsv, 1, &hue, 1, ch, 1);

				if (trackObject < 0) {
					Mat roi(hue, selection), maskroi(mask, selection);
					calcHist(&roi, 1, 0, maskroi, hist, 1, &hsize, &phranges);
					normalize(hist, hist, 0, 255, CV_MINMAX);

					trackWindow = selection;
					trackObject = 1;

					histimg = Scalar::all(0);
					int binW = histimg.cols / hsize;
					Mat buf(1, hsize, CV_8UC3);
					for (int i = 0; i < hsize; i++)
						buf.at<Vec3b>(i) = Vec3b(
								saturate_cast<uchar>(i * 180. / hsize), 255,
								255);
					cvtColor(buf, buf, CV_HSV2BGR);

					for (int i = 0; i < hsize; i++) {
						int val = saturate_cast<int>(
								hist.at<float>(i) * histimg.rows / 255);
						rectangle(histimg, Point(i * binW, histimg.rows),
								Point((i + 1) * binW, histimg.rows - val),
								Scalar(buf.at<Vec3b>(i)), -1, 8);
					}
				}

				calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
				backproj &= mask;
				RotatedRect trackBox = CamShift(backproj, trackWindow,
						TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10,
								1));
				if (trackWindow.area() <= 1) {
					int cols = backproj.cols, rows = backproj.rows, r = (
							MIN(cols, rows) + 5) / 6;
					trackWindow = Rect(trackWindow.x - r, trackWindow.y - r,
							trackWindow.x + r, trackWindow.y + r)
							& Rect(0, 0, cols, rows);
				}

				if (backprojMode)
					cvtColor(backproj, image, CV_GRAY2BGR);
				ellipse(image, trackBox, Scalar(0, 0, 255), 3, CV_AA);
			}
		} else if (trackObject < 0)
			paused = false;

		if (selectObject && selection.width > 0 && selection.height > 0) {
			Mat roi(image, selection);
			bitwise_not(roi, roi);
		}

		imshow("zVision", image);
		imshow("Histogram", histimg);

		char c = (char) waitKey(10);
		if (c == 27)
			break;
		switch (c) {
		case 'b':
			backprojMode = !backprojMode;
			break;
		case 'c':
			trackObject = 0;
			histimg = Scalar::all(0);
			break;
		case 'h':
			showHist = !showHist;
			if (!showHist)
				destroyWindow("Histogram");
			else
				namedWindow("Histogram", 1);
			break;
		case 'p':
			paused = !paused;
			break;
		default:
			;
		}
	}

	return ret;
}

int videoCap2Cam() {
//initialize and allocate memory to load the video stream from camera
	/*
	 CvCapture *capture1 = cvCaptureFromCAM(0);

	 if (!capture1)
	 return 1;

	 //create a window with the title "Video1"
	 cvNamedWindow("Video1");

	 while (true) {
	 //grab and retrieve each frames of the video sequentially
	 IplImage* frame1 = cvQueryFrame(capture1);

	 if (!frame1)
	 break;

	 //show the retrieved frame in the "Video1" window
	 cvShowImage("Video1", frame1);

	 //wait for 40 milliseconds
	 int c = cvWaitKey(40);

	 //exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
	 if ((char) c == 27)
	 break;

	 }

	 */

//initialize and allocate memory to load the video stream from camera
	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);
//		IplImage* lata = cvQueryFrame(capture2);
		//IplImage* gray = frame2;

		//zDetec.fFiltrGray(gray, gray);

		//convert IplImage to Mat
		//Mat matConv(frame2);

		//vector<Rect> resultPessoas;

		//vector<Vec3f> resultCirculos;

		//zDetec.dtCirculos(matConv,resultCirculos);

		zMov.andarFrente(1);

		if (!frame2)
			break;

		//show the retrieved frame in the "Video2" window
		cvShowImage("Video2", frame2);
		//	cvShowImage("Video2lata", lata);

		int c = cvWaitKey(50);

		if (contAcao == 0 && achouLata == false) {

			zDetec.dtMar(frame2);
			contAcao = 1;
			procuraObstaculo();

		}

		else if (contAcao == 1 && achouLata == false) {

			//zDetec.dtObstaculo1(frame2);
			contAcao = 2;
			procuraObstaculo();

		} else if (contAcao == 2 && achouLata == false) {

			//zDetec.dtObstaculo2(frame2);
			contAcao = 3;
			procuraObstaculo();

		} else if (contAcao == 3 && achouLata == false) {

			//zDetec.dtObstaculo3(frame2);
			contAcao = 4;
			procuraObstaculo();

		} else if (contAcao == 4 && achouLata == false) {

			//zDetec.dtObstaculo4(frame2);
			contAcao = 5;
			procuraObstaculo();

		} else if (contAcao == 5 && achouLata == false) {

			//zDetec.dtObstaculo5(frame2);
			contAcao = 6;
			procuraObstaculo();

		} else if (contAcao == 6 && achouLata == false) {

			zDetec.dtLata(frame2);
			procuraLata();
			/*
			 while (procuraLata() == true) {
			 sleep(1);
			 }
			 */

			if (achouLata == true) {
				contAcao = 6;
			} else {
				contAcao = 0;
			}

		} else if (contAcao == 6 && achouLata == true) {
			zDetec.dtLata(frame2);
			procuraLata();

		}

		else {
			zMov.virarEsquerda(1);
			procuraLata();
			contAcao = 0;
		}

		//	printf("Teste Andar para Frente\n");
		//	zMov.andarFrente();

		//wait for 40 milliseconds
		// c = cvWaitKey(40);

		//zDetec.dtLata(frame2);

		//zDetec.dtRGB(frame2);
		/*
		 if (procurando == true && andando == false) {

		 while (zDetec.dtPessoas(matConv, resultPessoas) == false) {

		 cout << "Procurando Objetos ..." << endl;
		 c = cvWaitKey(40);

		 if ((char) c == 27)
		 break;
		 }

		 procurando = false;

		 }

		 */

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

void movObstaculo() {

	if (contMov == 0) {
		zMov.pararRobo();

	} else if (contMov > 0 && contMov < 10) {
		zMov.reRobo();

	} else if (contMov > 10 && contMov < 20) {
		zMov.virarDireita();

	} else if (contMov > 20) {
		contMov = 0;
	}

	contMov++;

}

int analisaImagem(IplImage* frame2) {

	printf("Acao: %i\n", acao);
	int ret = 0;
	if (acao == 1) {

		zDetec.dtMar(frame2);
		if (procuraObstaculo() == true) {

			if (zDetec.posxL > 212) {
				conn.send(conn.esquerda);
				//zMov.virarEsquerda();
			} else if (zDetec.posxL < 106) {
				//zMov.virarDireita();
				conn.send(conn.direita);
			} else {
				conn.send(conn.volta);
				//zMov.meiaVolta();
			}

			//zMov.pararRobo();
			//zMov.reRobo();
			//zMov.pararRobo();
			//zMov.virarDireita();

			//movObstaculo();
			acao = 0;
			ret = 0;

		}
	}

	else if (acao == 2) {

		zDetec.dtCestoLixo(frame2);
		if (procuraCesto() == true) {
			//zMov.pararRobo();
			//zMov.reRobo();
			//zMov.virarDireita();
			if (zDetec.posxL > 212) {
				conn.send(conn.esquerda);
				//zMov.virarEsquerda();
			} else if (zDetec.posxL < 106) {
				//zMov.virarDireita();
				conn.send(conn.direita);
			} else {
				conn.send(conn.volta);
				//zMov.meiaVolta();
			}

			acao = 1;
			ret = 0;

		}
	}

	else if (acao == 3) {

		zDetec.dtObstaculo1(frame2);
		if (procuraObstaculo() == true) {
			//zMov.pararRobo();
			//zMov.reRobo();
			//zMov.virarDireita();
			if (zDetec.posxL > 212) {
				conn.send(conn.esquerda);
				//zMov.virarEsquerda();
			} else if (zDetec.posxL < 106) {
				//zMov.virarDireita();
				conn.send(conn.direita);
			} else {
				conn.send(conn.volta);
				//zMov.meiaVolta();
			}

			acao = 2;
			ret = 0;

		}
	}
	/*

	 else if (acao == 4) {

	 zDetec.dtObstaculo2(frame2);
	 if (zDetec.dtCadeira(frame2) == true) {
	 //zMov.pararRobo();
	 //zMov.reRobo();
	 //zMov.virarDireita();
	 if (zDetec.posxL > 212) {
	 conn.send(conn.esquerda);
	 } else if (zDetec.posxL < 106) {
	 conn.send(conn.direita);
	 } else {
	 conn.send(conn.volta);
	 }

	 acao = 3;
	 ret = 0;

	 }
	 }
	 */

	else if (acao == 4) {


		//acao = 9;
		zDetec.dtLata(frame2);
		if (procuraLataBool() == true) {

			if (zDetec.posxL > 212) {
				conn.send(conn.direita);
				//zMov.virarDireita();
			} else if (zDetec.posxL < 106) {
				conn.send(conn.esquerda);
				//zMov.virarEsquerda();
			} else {
				achouLata = true;
				printf("ACHOU LATA!");

				//zMov.pararRobo();
				//conn.send(conn.parar);

				printf("MANDOU P!");
				//zMov.pegarLata();
				conn.send(conn.pegaLata);
				printf("ESPEROU Z");
				//zMov.pegarObjeto();
				printf("RECEBEU Z");
				//zMov.pararRobo();
				conn.send(conn.parar);
				printf("PAROU ROBO");

			}
			achouLata = false;
			acao = 0;
			ret = 11;

		} else {
			printf("ANDAR FRENTE!");
			achouLata = false;
			//zMov.andarFrente();
			conn.send(conn.frente);
			acao = 0;
			ret = 0;

		}
		acao = 0;

	}

	acao++;

	return ret;

}

int analisaImagemDemo2(IplImage* frame2) {

	zDetec.dtLata(frame2);
	if (procuraLataBool() == true) {
		zDetec.fFiltrGray(frame2, frame2);
		achouLata = true;
		printf("ACHOU LATA!\n");

		zMov.pararRobo();

		printf("MANDOU PEGAR!\n");
		zMov.pegarLata();
		//sleep(11);
		zMov.pegarObjeto();
		printf("PEGOU!\n");
		zMov.pararRobo();
		printf("PAROU ROBO\n");
		achouLata = false;
		return 2;

	} else {
		printf("ANDAR FRENTE!\n");
		achouLata = false;
		zMov.andarFrente();

	}

	return 0;

}

int analisaImagemDemo3(IplImage* frame2) {

	zDetec.dtCestoLixo(frame2);
	if (procuraObstaculo() == true) {
		printf("ACHOU CESTO DE LIXO VAI DESPEJAR AS LATAS!\n");
		zMov.pararRobo();
		zMov.despejarLata();
		return 2;

		acao = 1;

	} else {
		printf("ANDAR FRENTE!\n");
		achouLata = false;
		zMov.andarFrente();

	}
	return 0;

}

int analisaImagemDemo1(IplImage* frame2) {

	zDetec.dtObstaculo1(frame2);
	if (procuraObstaculo() == true) {
		printf("ACHOU MANEQUIM!\n");
		zMov.pararRobo();
		zMov.reRobo(1);
		zMov.virarDireita(2);
		zMov.pararRobo();
		return 2;

	} else {
		printf("ANDAR FRENTE!\n");
		zMov.andarFrente();

	}

	return 0;

}

int videoCBR2013() {
	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

	conn.connect();

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		//zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		analisaImagem(frame2);

		//zDetec.dtCesto(frame2);

		//zDetec.dtMar(frame2);

		//zDetec.dtObstaculo1(frame2);

		//zDetec.dtMar(frame2);

		if (!frame2)
			break;

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

	conn.disconnect();

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;


}

int videoDemo1() {

//initialize and allocate memory to load the video stream from camera
	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

	while (true) {
		IplImage* frame2 = cvQueryFrame(capture2);

		if (!frame2)
			break;

		//show the retrieved frame in the "Video2" window
		cvShowImage("Video2", frame2);
		//	cvShowImage("Video2lata", lata);

		int c = analisaImagemDemo1(frame2);
		;

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if (c == 2)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoDemo2() {

//initialize and allocate memory to load the video stream from camera
	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

	while (true) {
		IplImage* frame2 = cvQueryFrame(capture2);

		if (!frame2)
			break;

		//show the retrieved frame in the "Video2" window
		cvShowImage("Video2", frame2);
		//	cvShowImage("Video2lata", lata);

		int c = analisaImagemDemo2(frame2);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if (c == 2)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoDemo3() {

//initialize and allocate memory to load the video stream from camera
	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

	while (true) {
		IplImage* frame2 = cvQueryFrame(capture2);

		if (!frame2)
			break;

		//show the retrieved frame in the "Video2" window
		cvShowImage("Video2", frame2);
		//	cvShowImage("Video2lata", lata);

		int c = analisaImagemDemo3(frame2);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if (c == 2)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoCap2CamTesteHSV() {

	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		//zDetec.dtCestoLixo(frame2);

		//zDetec.dtLata(frame2);

		//zDetec.dtMar(frame2);

		//zDetec.dtObstaculo1(frame2);

		//zDetec.dtMar(frame2);

		if (!frame2)
			break;

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoCap2CamTesteLATA() {

	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		//zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		//zDetec.dtCestoLixo(frame2);

		zDetec.dtLata(frame2);

		//zDetec.dtMar(frame2);

		//zDetec.dtObstaculo1(frame2);

		//zDetec.dtMar(frame2);

		if (!frame2)
			break;

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoCap2CamTesteCESTO() {

	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		//zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		zDetec.dtCestoLixo(frame2);

		//zDetec.dtCesto(frame2);

		//zDetec.dtMar(frame2);

		//zDetec.dtObstaculo1(frame2);

		//zDetec.dtMar(frame2);

		if (!frame2)
			break;

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoCap2CamTesteMANEQUIM() {

	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		//zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		//zDetec.dtCestoLixo(frame2);

		//zDetec.dtCestoLixo(frame2);

		//zDetec.dtMar(frame2);

		zDetec.dtObstaculo1(frame2);

		//zDetec.dtMar(frame2);

		if (!frame2)
			break;

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoCap2CamTesteCADEIRA() {

	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		//zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		//zDetec.dtCestoLixo(frame2);

		//zDetec.dtCestoLixo(frame2);

		//zDetec.dtMar(frame2);

		zDetec.dtObstaculo2(frame2);

		//zDetec.dtMar(frame2);

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int videoCap2CamTeste() {

	CvCapture *capture2 = cvCaptureFromCAM(1);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH, 160);

	cvSetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT, 140);

	cvNamedWindow("HSV", 1);

	setMouseCallback("HSV", onMouse, 0);

	if (!capture2)
		return 1;

//create a window with the title "Video2"
	cvNamedWindow("Video2");

//testeMovment();

	while (true) {
		//grab and retrieve each frames of the video sequentially
		IplImage* frame2 = cvQueryFrame(capture2);

		zDetec.dtHSV(frame2);
		cvShowImage("Video2", frame2);

		//zDetec.dtCestoLixo(frame2);

		//zDetec.dtLata(frame2);

		//zDetec.dtMar(frame2);

		//zDetec.dtObstaculo1(frame2);

		//zDetec.dtMar(frame2);

		if (!frame2)
			break;

		int c = cvWaitKey(50);

		//exit the loop if user press "Esc" key  (ASCII value of "Esc" is 27)
		if ((char) c == 27)
			break;
	}

//destroy the opened window
//cvDestroyWindow("Video1");
	cvDestroyWindow("Video2");
//release memory
//cvReleaseCapture(&capture1);
	cvReleaseCapture(&capture2);

	return 0;

}

int starZTronics() {
	//zMov.pegarObjeto();
	//sleep(5);
	/*
	 zMov.andarFrente(5);
	 zMov.virarDireita(3);
	 zMov.virarEsquerda(3);
	 zMov.pegarLata();
	 zMov.pegarObjeto();
	 zMov.pararRobo();
	 return 0;
	 */
//return videoCap2Cam();
	return videoCBR2013();

}

int starDemo1() {
	printf("AGUARDANDO 5 SEGUNDOS\n");
	sleep(5);
	/*
	 zMov.andarFrente(5);
	 zMov.virarDireita(3);
	 zMov.virarEsquerda(3);
	 zMov.pegarLata();
	 zMov.pegarObjeto();
	 zMov.pararRobo();
	 return 0;
	 */
//return videoCap2Cam();
	return videoDemo1();

}

int starDemo2() {
	printf("AGUARDANDO 5 SEGUNDOS\n");
	sleep(5);
	/*
	 zMov.andarFrente(5);
	 zMov.virarDireita(3);
	 zMov.virarEsquerda(3);
	 zMov.pegarLata();
	 zMov.pegarObjeto();
	 zMov.pararRobo();
	 return 0;
	 */
//return videoCap2Cam();
	return videoDemo2();

}

int starDemo3() {
	printf("AGUARDANDO 5 SEGUNDOS\n");
	sleep(5);
	/*
	 zMov.andarFrente(5);
	 zMov.virarDireita(3);
	 zMov.virarEsquerda(3);
	 zMov.pegarLata();
	 zMov.pegarObjeto();
	 zMov.pararRobo();
	 return 0;
	 */
//return videoCap2Cam();
	return videoDemo3();

}

void help() {
	cout << "******* ZTronics - ZVision *******" << endl;
	cout << "*******  By - LC Software  *******" << endl;

	printf("1 - *******  DEMO MANEQUIM DETECTION  *******\n");
	printf("2 - *******  DEMO LATA_PEG DETECTION  *******\n");
	printf("3 - *******  DEMO CESTO_DEP DETECTION  *******\n");
	printf("4 - ******     CALIBRAÇÃO DE LATA  *******\n");
	printf("5 - ******     CALIBRAÇÃO DE CESTO  *******\n");
	printf("6 - ******     CALIBRAÇÃO DE MANEQUIM  *******\n");
	printf("7 - ******     CALIBRAÇÃO DE CADEIRA  *******\n");
	printf("8 - ******     CALIBRAÇÃO DE HSV  *******\n");
	printf("9 - *******  MODO CBR 2013 ATIVADO  *******\n");

}

int main(int argc, const char** argv) {
	cout << "******* ZTronics - ZVision *******" << endl;
	cout << "*******  By - LC Software  *******" << endl;

	char _opt[1024];

	strcpy(_opt, argv[1]);

	char* opt = _opt;

	//printf("Opcao: %s\n", opt);

	if (opt[0] == '1') {
		printf("***********  Modo Demonstração  *******\n");
		printf("*******  DEMO MANEQUIM DETECTION  *******\n");
		return starDemo1();

	} else if (opt[0] == '2') {
		printf("***********  Modo Demonstração  *******\n");
		printf("*******  DEMO LATA_PEG DETECTION  *******\n");
		return starDemo2();

	} else if (opt[0] == '3') {
		printf("***********  Modo Demonstração  *******\n");
		printf("*******  DEMO CESTO_DEP DETECTION  *******\n");
		return starDemo3();

	} else if (opt[0] == '4') {
		printf("***********  Modo Calibração  *******\n");
		printf("******     CALIBRAÇÃO DE LATA  *******\n");
		return videoCap2CamTesteLATA();

	} else if (opt[0] == '5') {
		printf("***********  Modo Calibração  *******\n");
		printf("******     CALIBRAÇÃO DE CESTO  *******\n");
		return videoCap2CamTesteCESTO();

	} else if (opt[0] == '6') {
		printf("***********  Modo Calibração  *******\n");
		printf("******     CALIBRAÇÃO DE MANEQUIM  *******\n");
		return videoCap2CamTesteMANEQUIM();

	} else if (opt[0] == '7') {
		printf("***********  Modo Calibração  *******\n");
		printf("******     CALIBRAÇÃO DE CADEIRA  *******\n");
		return videoCap2CamTesteCADEIRA();

	} else if (opt[0] == '8') {
		printf("***********  Modo Calibração  *******\n");
		printf("******     CALIBRAÇÃO DE HSV  *******\n");
		return videoCap2CamTesteHSV();

	} else if (opt[0] == '9') {
		printf("***********  Modo Competição  *******\n");
		printf("*******  MODO CBR 2013 ATIVADO  *******\n");
		return starZTronics();

	} else if (opt[0] == 'h') {
		help();

	} else if (opt[0] == 'j') {
		printf("***********  Modo Demonstração  *******\n");
		printf("*******  MODO DEMO DESPEJAR  *******\n");
		zMov.despejarLata();

	}

	return 1;

//return zVisionStart(argc, argv);

//return videoCap2Cam();

	//return videoCap2CamTeste();

	//return starZTronics();

//testeMovment();

//return 0;

//return zVisionCV();
}

