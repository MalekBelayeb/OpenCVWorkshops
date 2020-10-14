#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "BruitageImage.h"

#include <iostream>
using namespace cv;
using namespace std;




Mat get_salt_pepper_Noised_Image(float pa, float pb)
{
	Mat imgSource = imread("av_bourguiba.jpg");

	if (imgSource.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
	}

	imshow("Original Image ", imgSource);

	cvtColor(imgSource, imgSource, CV_RGB2GRAY, 1);
	Mat imgSource1 = imgSource.clone();

	RNG rng; 
	int amount1 = imgSource1.rows * imgSource1.cols * pa;
	int amount2 = imgSource1.rows * imgSource1.cols * pb;
	for (int counter = 0; counter < amount1; ++counter)
	{
		imgSource1.at<uchar>(rng.uniform(0, imgSource1.rows), rng.uniform(0, imgSource1.cols)) = 0;

	}
	for (int counter = 0; counter < amount2; ++counter)
	{
		imgSource1.at<uchar>(rng.uniform(0, imgSource1.rows), rng.uniform(0, imgSource1.cols)) = 255;
	}

	imshow("Noised pepper & salt image", imgSource1);

	return imgSource1;
}



/*
void add_pepper_and_salt_noise(int n)
{

	Mat imgSource = imread("av_bourguiba.jpg");
	
	if (imgSource.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
	}

	
	int i = 0;
	int j = 0;

	for (int i = 0;i < n;i++)
	{
		 i = rand() % imgSource.cols;
		 j = rand() % imgSource.rows;

		 imgSource.at<uchar>(j, i) = 0;
		
	}	
	
	for (int i = 0;i < n;i++)
	{
		 i = rand() % imgSource.cols;
		 j = rand() % imgSource.rows;

		 imgSource.at<uchar>(j, i) = 255;

	}



	imshow("Pepper&Salt Noise", imgSource);
	waitKey(0);
	cvDestroyAllWindows();
	return;

}
*/