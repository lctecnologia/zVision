/*
 * zDetect.cpp
 *
 *  Created on: 18/08/2013
 *      Author: ztronics
 */

#include "zDetect.h"

IplImage* GetThresholdedYellowImageTraced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(20, 100, 100), cvScalar(30, 255, 255),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedLataImageTraced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(0, 0, 0), cvScalar(20, 20, 20), imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedLataCestoLixoTraced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(0, 70, 115), cvScalar(31, 256, 256), imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedMarTraced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(90, 120, 120), cvScalar(140, 140, 180),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedOb1Traced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(105, 110, 95), cvScalar(160, 135, 135),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedOb2Traced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(0, 0, 0), cvScalar(132, 132, 125),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedOb3Traced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(195, 100, 100), cvScalar(180, 100, 100),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedOb4Traced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(195, 100, 100), cvScalar(180, 100, 100),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

IplImage* GetThresholdedOb5Traced(IplImage* img) {
// Convert the image into an HSV image
	IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);
	cvCvtColor(img, imgHSV, CV_BGR2HSV);

	IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);

// Values 20,100,100 to 30,255,255 working perfect for yellow at around 6pm
	//cvInRangeS(imgHSV, cvScalar(112, 100, 100), cvScalar(124, 255, 255),
	cvInRangeS(imgHSV, cvScalar(195, 100, 100), cvScalar(180, 100, 100),
			imgThreshed);

	cvReleaseImage(&imgHSV);

	return imgThreshed;
}

//Funkce pøevede na šedou
void zDetect::fFiltrGray(IplImage* vstup, IplImage* &vystup) {
/*
	IplImage* gray = cvCreateImage(cvGetSize(vstup), IPL_DEPTH_8U, 1);
	cvCvtColor(vstup, gray, CV_BGR2GRAY);
	cvCvtColor(gray, vystup, CV_GRAY2BGR);
	cvReleaseImage(&gray);
	*/
	int height = vstup->height;
	int width = vstup->width;
	CvScalar s;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			s = cvGet2D(vstup, i, j);
			s.val[0] = 255;
			s.val[2] = 255;
			cvSet2D(vystup, i, j, s);
		}
	}

}
//Zeleny filtr
void fFiltrGreen(IplImage* vstup, IplImage* vystup) {
	int height = vstup->height;
	int width = vstup->width;
	CvScalar s;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			s = cvGet2D(vstup, i, j);
			s.val[0] = 255;
			s.val[2] = 255;
			cvSet2D(vystup, i, j, s);
		}
	}
}
//Mondrý filtr
void fFiltrBlue(IplImage* vstup, IplImage* vystup) {
	int height = vstup->height;
	int width = vstup->width;
	CvScalar s;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			s = cvGet2D(vstup, i, j);
			s.val[1] = 0;
			s.val[2] = 0;
			cvSet2D(vystup, i, j, s);
		}
	}
}
//Èervený filtr
void fFiltrRed(IplImage* vstup, IplImage* vystup) {
	int height = vstup->height;
	int width = vstup->width;
	CvScalar s;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			s = cvGet2D(vstup, i, j);
			s.val[1] = 0;
			s.val[0] = 0;
			cvSet2D(vystup, i, j, s);
		}
	}
}

void fFiltrBlur(IplImage* vstup, IplImage* vystup) {
	cvSmooth(vstup, vystup, CV_BLUR, 7, 7);
}

void fFiltrGauss(IplImage* vstup, IplImage* vystup) {
	cvSmooth(vstup, vystup, CV_GAUSSIAN, 7, 7);
}

void fFiltrMedian(IplImage* vstup, IplImage* vystup) {
	cvSmooth(vstup, vystup, CV_MEDIAN, 7, 7);
}

void fErode(IplImage* vstup, IplImage* vystup) {
	cvErode(vstup, vystup, NULL, 1);
}

bool zDetect::dtCirculos(Mat img, vector<Vec3f> &result) {
	bool ret = false;

	Mat cimg;

	//medianBlur(img, img, 5);
	//cvtColor(img, cimg, CV_GRAY2BGR);

	double t = (double) getTickCount();

	vector<Vec3f> circles;
	HoughCircles(img, circles, CV_HOUGH_GRADIENT, 1, 10, 100, 30, 1, 30 // change the last two parameters
																		// (min_radius & max_radius) to detect larger circles
			);
	t = (double) getTickCount() - t;
	printf("tdetection time = %gms\n", t * 1000. / cv::getTickFrequency());

	if (circles.size() > 0) {
		ret = true;
		result = circles;
	}

	for (size_t i = 0; i < circles.size(); i++) {
		Vec3i c = circles[i];
		circle(cimg, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, CV_AA);
		circle(cimg, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, CV_AA);
	}

	imshow("detected circles", cimg);

	return ret;

}

bool zDetect::dtPessoas(Mat img, vector<Rect> &result) {
	bool ret = false;

	HOGDescriptor hog;
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	namedWindow("people detector", 1);

	for (;;) {

		fflush(stdout);
		vector<Rect> found, found_filtered;
		double t = (double) getTickCount();
		// run the detector with default parameters. to get a higher hit-rate
		// (and more false alarms, respectively), decrease the hitThreshold and
		// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).

		hog.detectMultiScale(img, found, 0, Size(4, 4), Size(8, 8), 1.05, 2);

		t = (double) getTickCount() - t;
		printf("tdetection time = %gms\n", t * 1000. / cv::getTickFrequency());
		size_t i, j;
		if (found.size() > 0) {
			ret = true;
			result = found;
		}
		for (i = 0; i < found.size(); i++) {
			Rect r = found[i];
			for (j = 0; j < found.size(); j++)
				if (j != i && (r & found[j]) == r)
					break;
			if (j == found.size())
				found_filtered.push_back(r);
		}
		for (i = 0; i < found_filtered.size(); i++) {
			Rect r = found_filtered[i];
			// the HOG detector returns slightly larger rectangles than the real objects.
			// so we slightly shrink the rectangles to get a nicer output.
			r.x += cvRound(r.width * 0.1);
			r.width = cvRound(r.width * 0.8);
			r.y += cvRound(r.height * 0.07);
			r.height = cvRound(r.height * 0.8);
			rectangle(img, r.tl(), r.br(), cv::Scalar(255, 255, 0), 3);
		}

		imshow("people detector", img);
		break;
	}

	return ret;

}

void zDetect::dtAmarelo(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgYellowThresh = GetThresholdedYellowImageTraced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgYellowThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;

	if (posX < 340 && posX > 280) {
		printf("Andar Frente\n");

	}

	else if (posX < 280 && posX > 0) {
		printf("Virar Esquerda\n");

	}

	else if (posX < 640 && posX > 340) {
		printf("Virar Direita\n");

	}

	else

	{
		printf("Andar Frente\n");
	}

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("last position (%d,%d)\n", lastX, lastY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(110, 110, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgYellowThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgYellowThresh);

	delete moments;

}

void zDetect::dtLata(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgLataThresh = GetThresholdedLataImageTraced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgLataThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;
	this->area = area;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", this->area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgLataThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgLataThresh);

	delete moments;

}

void zDetect::dtCestoLixo(IplImage* frame) {

	// The two windows we'll be using
	//cvNamedWindow("video");
	//cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedLataCestoLixoTraced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;
	this->area = area;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("area (%d)\n", this->area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	//cvShowImage("thresh", imgThresh);
	//cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

void zDetect::dtMar(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedMarTraced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;
	this->area = area;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", this->area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

void zDetect::dtObstaculo1(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedOb1Traced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	//printf("spatial Moment (%d,%d)\n", moment10, moment01);




	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	static int areaV = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;
	areaV = area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;
	this->area = area;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("areaVL (%d)\n", areaV);


	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

void zDetect::dtObstaculo2(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedOb2Traced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;
	this->area = area;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

void zDetect::dtObstaculo3(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedOb3Traced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

void zDetect::dtObstaculo4(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedOb4Traced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

void zDetect::dtObstaculo5(IplImage* frame) {

	// The two windows we'll be using
	cvNamedWindow("video");
	cvNamedWindow("thresh");

	// This image holds the "scribble" data...
	// the tracked positions of the ball
	IplImage* imgScribble = NULL;

	// An infinite loop

	// Will hold a frame captured from the camera

	// If this is the first frame, we need to initialize it
	if (imgScribble == NULL) {
		imgScribble = cvCreateImage(cvGetSize(frame), 8, 3);
	}

	// Holds the yellow thresholded image (yellow = white, rest = black)
	IplImage* imgThresh = GetThresholdedOb5Traced(frame);

	// Calculate the moments to estimate the position of the ball
	CvMoments *moments = (CvMoments*) malloc(sizeof(CvMoments));
	cvMoments(imgThresh, moments, 1);

	// The actual moment values
	double moment10 = cvGetSpatialMoment(moments, 1, 0);
	double moment01 = cvGetSpatialMoment(moments, 0, 1);
	double area = cvGetCentralMoment(moments, 0, 0);

	// Holding the last and current ball positions
	static int posX = 0;
	static int posY = 0;

	int lastX = posX;
	int lastY = posY;

	posX = moment10 / area;
	posY = moment01 / area;

	this->lastxL = lastX;
	this->lastyL = lastY;
	this->posxL = posX;
	this->posyL = posY;

	// Print it out for debugging purposes
	printf("position (%d,%d)\n", posX, posY);

	printf("spatial Moment (%d,%d)\n", moment10, moment01);

	printf("area (%d)\n", area);

	// We want to draw a line only if its a valid position
	if (lastX > 0 && lastY > 0 && posX > 0 && posY > 0) {
		// Draw a yellow line from the previous point to the current point
		cvLine(imgScribble, cvPoint(posX, posY), cvPoint(lastX, lastY),
				cvScalar(111, 200, 0), 5);
	}

	// Add the scribbling image and the frame... and we get a combination of the two
	cvAdd(frame, imgScribble, frame);
	cvShowImage("thresh", imgThresh);
	cvShowImage("video", frame);

	// Release the thresholded image... we need no memory leaks.. please
	cvReleaseImage(&imgThresh);

	delete moments;

}

bool zDetect::dtRGB(IplImage* frame) {

	// Assign the file name to a character array
	printf("PROCURANDO CESTO LIXO");
	IplImage* src = frame; // Loading the image
	bool ret = false;
	IplImage* copy = cvCreateImage(cvGetSize(src), 8, 3); //Create a new image of,8 bit,3 channel
	CvScalar s, c; // create two scalar variables
	cout << "Searching Green color...\n";
	for (int i = 0; i < (src->height); i++) //In the 2D array of the img..count till the vertical pixel reaches the height of src
			{
		for (int j = 0; j < (src->width); j++) //In the 2D array of the img..count till orizontal pixel reaches the width o src
				{
			s = cvGet2D(src, i, j); //Get the RGB values of src's i,j into a scalar s
			//printf ("R: %d G: %d B: %d", s.val[0], s.val[1], s.val[2]);
			printf("R: %f G: %f B: %f\n", s.val[0], s.val[1], s.val[2]);

			if ((s.val[0] > 30) && (s.val[0] < 60) ) { // if RGB values (in the order as in code) are
																		   //satisfying threshold

				//condn ie
				printf ("ACHOU CESTO LIXO\n");
				return true;														   //. RED<50 & GREEN>100 & BLUE<100
																		   //Remember s.val[2],s.val[1],s.val[0] are RGB correspondingly{
																		   //ie. if the pixel is predominantly Green
		//		c.val[2] = 0;			//Set R to 0
		//		c.val[1] = 255;		//Set G to 255
		//		c.val[0] = 0;		//Set B to 0
		//		cvSet2D(copy, i, j, c);	//Change the pixel value of copy img to pure green(G=255 R=0 B=0)

			} else {

				return false;
			//	c.val[2] = 255; // Red
			//	c.val[1] = 255; // Green
			//	c.val[0] = 255; // Blue
			//	cvSet2D(copy, i, j, c); // Now set the scalar c(now white) to the pixel in i,j in copy
			}
		}
		return ret;
	}
	//cout << "Color found...\n";
	//cvNamedWindow("Input", CV_WINDOW_AUTOSIZE); //Create a window “Input”
	//cvShowImage("Input", src); //Display src in a window named “Input”
	//cvNamedWindow("Output", CV_WINDOW_AUTOSIZE); //Create a window “Output”
	//cvShowImage("Output", copy); //Display copy in a window named “Output”
	//cvReleaseImage(&src);
}

bool zDetect::dtCadeira(IplImage* frame) {

	// Assign the file name to a character array
	printf("PROCURANDO CADEIRA\n");
	IplImage* src = frame; // Loading the image
	bool ret = false;
	IplImage* copy = cvCreateImage(cvGetSize(src), 8, 3); //Create a new image of,8 bit,3 channel
	CvScalar s, c; // create two scalar variables
	cout << "Searching Green color...\n";
	for (int i = 0; i < (src->height); i++) //In the 2D array of the img..count till the vertical pixel reaches the height of src
			{
		for (int j = 0; j < (src->width); j++) //In the 2D array of the img..count till orizontal pixel reaches the width o src
				{
			s = cvGet2D(src, i, j); //Get the RGB values of src's i,j into a scalar s
			//printf ("R: %d G: %d B: %d", s.val[0], s.val[1], s.val[2]);
			printf("R: %f G: %f B: %f\n", s.val[0], s.val[1], s.val[2]);

			if ((s.val[0] > 118) && (s.val[0] < 135) && (s.val[1] > 118) && (s.val[1] < 133) && (s.val[2] > 118) && (s.val[2] < 133)) { // if RGB values (in the order as in code) are
																		   //satisfying threshold

				//condn ie
				printf ("ACHOU CADEIRA\n");
				return true;														   //. RED<50 & GREEN>100 & BLUE<100
																		   //Remember s.val[2],s.val[1],s.val[0] are RGB correspondingly{
																		   //ie. if the pixel is predominantly Green
		//		c.val[2] = 0;			//Set R to 0
		//		c.val[1] = 255;		//Set G to 255
		//		c.val[0] = 0;		//Set B to 0
		//		cvSet2D(copy, i, j, c);	//Change the pixel value of copy img to pure green(G=255 R=0 B=0)

			} else {

				return false;
			//	c.val[2] = 255; // Red
			//	c.val[1] = 255; // Green
			//	c.val[0] = 255; // Blue
			//	cvSet2D(copy, i, j, c); // Now set the scalar c(now white) to the pixel in i,j in copy
			}
		}
		return ret;
	}
	//cout << "Color found...\n";
	//cvNamedWindow("Input", CV_WINDOW_AUTOSIZE); //Create a window “Input”
	//cvShowImage("Input", src); //Display src in a window named “Input”
	//cvNamedWindow("Output", CV_WINDOW_AUTOSIZE); //Create a window “Output”
	//cvShowImage("Output", copy); //Display copy in a window named “Output”
	//cvReleaseImage(&src);
}

bool zDetect::dtCesto(IplImage* frame) {

	// Assign the file name to a character array
	printf("PROCURANDO CESTO LIXO");
	IplImage* src = frame; // Loading the image
	bool ret = false;
	IplImage* copy = cvCreateImage(cvGetSize(src), 8, 3); //Create a new image of,8 bit,3 channel
	CvScalar s, c; // create two scalar variables
	cout << "Searching Green color...\n";
	for (int i = 0; i < (src->height); i++) //In the 2D array of the img..count till the vertical pixel reaches the height of src
			{
		for (int j = 0; j < (src->width); j++) //In the 2D array of the img..count till orizontal pixel reaches the width o src
				{
			s = cvGet2D(src, i, j); //Get the RGB values of src's i,j into a scalar s
			//printf ("R: %d G: %d B: %d", s.val[0], s.val[1], s.val[2]);
			printf("R: %f G: %f B: %f\n", s.val[0], s.val[1], s.val[2]);

			if ((s.val[0] > 40) && (s.val[0] < 90) && (s.val[1] > 70) && (s.val[1] < 100) && (s.val[2] > 80) && (s.val[2] < 100)) { // if RGB values (in the order as in code) are
																		   //satisfying threshold

				//condn ie
				printf ("ACHOU CESTO LIXO\n");
				return true;														   //. RED<50 & GREEN>100 & BLUE<100
																		   //Remember s.val[2],s.val[1],s.val[0] are RGB correspondingly{
																		   //ie. if the pixel is predominantly Green
		//		c.val[2] = 0;			//Set R to 0
		//		c.val[1] = 255;		//Set G to 255
		//		c.val[0] = 0;		//Set B to 0
		//		cvSet2D(copy, i, j, c);	//Change the pixel value of copy img to pure green(G=255 R=0 B=0)

			} else {

				return false;
			//	c.val[2] = 255; // Red
			//	c.val[1] = 255; // Green
			//	c.val[0] = 255; // Blue
			//	cvSet2D(copy, i, j, c); // Now set the scalar c(now white) to the pixel in i,j in copy
			}
		}
		return ret;
	}
	//cout << "Color found...\n";
	//cvNamedWindow("Input", CV_WINDOW_AUTOSIZE); //Create a window “Input”
	//cvShowImage("Input", src); //Display src in a window named “Input”
	//cvNamedWindow("Output", CV_WINDOW_AUTOSIZE); //Create a window “Output”
	//cvShowImage("Output", copy); //Display copy in a window named “Output”
	//cvReleaseImage(&src);
}



static void onMouse( int event, int x, int y, int, void* )
{

	printf("Mouse Movendo");

}



void zDetect::dtHSV(IplImage* frame) {

	//load image from directory
	IplImage* img = frame;//cvLoadImage("C:\\Users\\Nathan\\Desktop\\SnookerPic.png");

	IplImage* gray = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	CvMemStorage* storage = cvCreateMemStorage(0);

	//covert to grayscale
	cvCvtColor(img, gray, CV_BGR2GRAY);

	// This is done so as to prevent a lot of false circles from being detected
	cvSmooth(gray, gray, CV_GAUSSIAN, 7, 7);

	IplImage* canny = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	IplImage* rgbcanny = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
	cvCanny(gray, canny, 50, 100, 3);

	//detect circles
	CvSeq* circles = cvHoughCircles(gray, storage, CV_HOUGH_GRADIENT, 1, 35.0,
			75, 60, 0, 0);
	cvCvtColor(canny, rgbcanny, CV_GRAY2BGR);

	//draw all detected circles
	if (mouse.x > 0 && mouse.y > 0) {

		CvScalar s;

		s = cvGet2D(img, mouse.y, mouse.x);	         //colour of circle
		printf("H: %f S: %f V: %f\n", s.val[0], s.val[1], s.val[2]);

		// draw the circle center
		//cvCircle(img, center, 3, CV_RGB(0,255,0), -1, 8, 0);

		// draw the circle outline
		//cvCircle(img, center, radius + 1, CV_RGB(0,0,255), 2, 8, 0);

		//display coordinates
		//printf("x: %d y: %d r\n", mouse.x, mouse.y);

	}

	//create window
	//cvNamedWindow("circles", 1);

	//show image in window
	//cvShowImage("circles", rgbcanny);
	cvShowImage("HSV", img);

	//cvSaveImage("out.png", img);
	//cvDestroyWindow("SnookerImage");
	//cvDestroyWindow("circles");
	//cvReleaseMemStorage("storage");


}

zDetect::zDetect() {
	// TODO Auto-generated constructor stub

}

zDetect::~zDetect() {
	// TODO Auto-generated destructor stub
}

