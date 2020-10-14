
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "calcHistogramAndEqualization.h"

#include <iostream>
using namespace cv;
using namespace std;



void CalcHistogram()
{
	Mat grayImage = imread("av_bourguiba.jpg",0);

	if (grayImage.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return;
	}

	int histSize = 256;    // kobr l historgram mteena 
	float range[] = { 0, 255 };
	const float* ranges[] = { range };
	MatND hist; // l output mtaa calHist mteena 

	// arg[0] l image input mteena
	// arg[1] kadeeesh men image besh naatehaa 
	// arg[2] = channels nmlt fel cas mteena besh nekhdmou aal intensité barka donc 0 
	// arg[3] = optional mask yaani ena houma les pixels eli will be ignored fel cas mtaana aadina matric 
	// fergha donc les pixels lkol besh nekhdmmou aalehom
	// arg[4] l output mteena besh yethaaat ghadi 
	// arg[5] dimension mtaa histogram mteena 
	// arg[8] uniform
	// arg[9] cumulé
	calcHist(&grayImage, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false);
	
	// Affichage mtaa courbe fi image
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
			Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}



	imshow("Display Window", grayImage);
	
	namedWindow("Result", 1);    
	imshow("Result", histImage);

	waitKey(0);
	cvDestroyAllWindows();
	return;
}




void HistogramEqualization()
{

	Mat image = imread("av_bourguiba.jpg");
	
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return ;
	}
	
	/*
	* EqualizeHist aala image lkoll
	*/

	Mat hist_equalized_image;
	cvtColor(image, hist_equalized_image, COLOR_BGR2GRAY);
	//equalizHist(src , out) 
	equalizeHist(hist_equalized_image, hist_equalized_image);
	
	/*
	* EqualizeHist aala koll plan mel image r g b 
	*/
	Mat hist_equalized_image_splited;
	cvtColor(image, hist_equalized_image_splited, COLOR_BGR2YCrCb);
	vector<Mat> vec_channels;
	split(hist_equalized_image_splited, vec_channels);
	
	// Split/naksmou l image 3 plans Y, Cr et Cb  
	/*
	Koll matrice de plan tethaat fi vector. 
	vec_channels[0] feha l plan Y , 
	vec_channels[1] feha l plan Cr 
	et vec_channels[2] feha l plan Cb.
	*/
	equalizeHist(vec_channels[0], vec_channels[0]);
	merge(vec_channels, hist_equalized_image_splited);
	cvtColor(hist_equalized_image_splited, hist_equalized_image_splited, COLOR_YCrCb2BGR);

	imshow("Display Window", image);
	imshow("hist_equalized_image", hist_equalized_image_splited);
	waitKey(0);
	cvDestroyAllWindows();
	return ;
}

