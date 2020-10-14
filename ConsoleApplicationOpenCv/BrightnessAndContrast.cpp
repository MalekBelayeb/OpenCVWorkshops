#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "BrightnessAndContrast.h"

#include <iostream>
using namespace cv;
using namespace std;



void BrightnessAndContrast()
{

	Mat image = imread("av_bourguiba.jpg");

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return ;
	}


	//Tabdil Brightness 
	/*
	
	Fel image koll pixel issir aaleha haka 
	
		new_image (i, j) = image(i, j) + c
	
	Fel cas hedha 
	
		new_image (i, j) = image(i, j) * 1 + 50
 	
	Ou bien najmou naksou 

		new_image (i, j) = image(i, j) * 1 - 50

	*/
	Mat imageBrighnessHigh50;
	image.convertTo(imageBrighnessHigh50, -1, 1, 50); //zedna lel brightness 50 


	//Tabdil Contrast 
	/*

	Fel image koll pixel issir aaleha haka

		new_image (i, j) = image(i, j) * c 

	Fel cas hedha

		new_image (i, j) = image(i, j) * 4 + 0
		
	*/

	Mat imageContrastHigh4;
	image.convertTo(imageBrighnessHigh50, -1, 4, 0); //thrabna contrast fel 4


	imshow("Display Window", image);
	imshow("imageBrighnessHigh50", imageBrighnessHigh50);
	waitKey(0);
	cvDestroyAllWindows();
	return ;
}