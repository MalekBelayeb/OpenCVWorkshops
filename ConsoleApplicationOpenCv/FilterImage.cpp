#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "FilterImage.h"

using namespace cv;
using namespace std;


void FilterImage(Mat imgSource)
{
	Mat dst;
	medianBlur(imgSource, dst, 9);

	imshow("Filtred S&P Noise", dst);
	waitKey(0);
	cvDestroyAllWindows();
	return;

}