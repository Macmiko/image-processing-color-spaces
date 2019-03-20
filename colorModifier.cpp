#include "colorModifier.h"


using namespace std;
using namespace cv;


void on_trackbar(int, void* param)
{
	Mat mainImage, convertImg;
	mainImage = *((Mat*)param);

	//copy values of pixels from main image to convert image
	mainImage.copyTo(convertImg);

	int Channel1, Channel2, Channel3;
	double slider1, slider2, slider3;
	if (First_Channel > 0)
	{
		for (int i = 0; i < mainImage.rows; i++)
		{
			for (int j = 0; j < mainImage.cols; j++)
			{
				slider1 = (double)First_Channel / 100; //get value of the first slider  
				Channel1 = (int)mainImage.at<Vec3b>(i, j)[0] * slider1; //save new value of pixel
				convertImg.at<Vec3b>(i, j)[0] = (uchar)Channel1; //put new value of pixel 

			}
		}
	}

	//the same things for 2nd and 3th channel like with the first channel
	if (Second_Channel > 0)
	{
		for (int i = 0; i < mainImage.rows; i++)
		{
			for (int j = 0; j < mainImage.cols; j++)
			{
				slider2 = (double)Second_Channel / 100;
				Channel2 = (int)mainImage.at<Vec3b>(i, j)[1] * slider2;
				convertImg.at<Vec3b>(i, j)[1] = (uchar)Channel2;
			}
		}
	}
	if (Third_Channel > 0)
	{
		for (int i = 0; i < mainImage.rows; i++)
		{
			for (int j = 0; j < mainImage.cols; j++)
			{
				slider3 = (double)Third_Channel / 100;
				Channel3 = (int)mainImage.at<Vec3b>(i, j)[2] * slider3;
				convertImg.at<Vec3b>(i, j)[2] = (uchar)Channel3;
			}
		}
	}

	imshow(trackbarWindowName, convertImg);

}


void createTrackbars(Mat image)
{
	//create window for trackbars
	namedWindow(trackbarWindowName, WINDOW_AUTOSIZE);
	
	//create trackbars
	createTrackbar("First(%)", trackbarWindowName, &First_Channel, First_Channel_MAX, on_trackbar,&image);

	createTrackbar("Second(%)", trackbarWindowName, &Second_Channel, Second_Channel_MAX, on_trackbar,&image);

	createTrackbar("Third(%)", trackbarWindowName, &Third_Channel, Third_Channel_MAX, on_trackbar,&image);

	imshow(trackbarWindowName, image);
	waitKey(0);

}
