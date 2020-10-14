#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "calcHistogramAndEqualization.h"
#include "BrightnessAndContrast.h"
#include "BruitageImage.h"
#include "FilterImage.h"

#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat srcArr;

	//HistogramEqualization();
	//CalcHistogram();

	//add_pepper_and_salt_noise(10);
	


	Mat imgToFilter = get_salt_pepper_Noised_Image(0.5, 0.6);

	FilterImage(imgToFilter);
}