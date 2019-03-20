#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>


using namespace std;
using namespace cv;

namespace

{
	//setting the range of channels values ​​(range of trackbars)

	int First_Channel = 0; //we need it to save current value of trackbar for first channel
	const int First_Channel_MAX = 100; //maximum range of trackbar (100%)
	int Second_Channel = 0; //we need it to save current value of trackbar for second channel
	const int Second_Channel_MAX = 100;
	int Third_Channel = 0; //we need it to save current value of trackbar for third channel
	const int Third_Channel_MAX = 100;

	const string trackbarWindowName = "Trackbars";

}

void on_trackbar(int, void* param); //the function is automatically called after every movement of the sliders

void createTrackbars(Mat image);




