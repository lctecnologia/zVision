//============================================================================
// Name        : zVision.cpp
// Author      : Leonardo Costa
// Version     :
// Copyright   : LC Software
// Description : Interface de Detecção de Objetos C++, Ansi-style
//============================================================================

#ifndef ZDETECT_H_
#define ZDETECT_H_

#include "zIncludes.h"

class zDetect {
public:
	zDetect();
	virtual ~zDetect();
	bool dtPessoas(Mat img, vector<Rect> &result);
	bool dtCirculos(Mat img, vector<Vec3f> &result);
	void fFiltrGray(IplImage* vstup, IplImage* &vystup);
	void dtAmarelo(IplImage* frame);
	void dtLata(IplImage* frame);
	void dtCestoLixo(IplImage* frame);
	void dtMar(IplImage* frame);
	void dtObstaculo1(IplImage* frame);
	void dtObstaculo2(IplImage* frame);
	void dtObstaculo3(IplImage* frame);
	void dtObstaculo4(IplImage* frame);
	void dtObstaculo5(IplImage* frame);
	bool dtRGB(IplImage* frame);
	bool dtCesto(IplImage* frame);
	bool dtCadeira(IplImage* frame);
	void dtHSV(IplImage* frame);
	int posxL,posyL,lastxL,lastyL, area;
	cv::Point mouse;

};

#endif /* ZDETECT_H_ */
