#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

namespace
{
	double h, s, l; //HSL
	double r, g, b; //RGB
	double y, u, v; //YUV
}



int checkRange(int pixelValue); //Check if pixel's value is between 0 and 255

void YUV2RGB(Mat image);

void RGB2YUV(Mat image);

void HSL2RGB(Mat img);

void RGB2HSL(Mat img);



