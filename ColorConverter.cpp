#include"ColorsConverter.h"


using namespace std;
using namespace cv;


int checkRange(int pixelValue) //check if value of pixel is between 0-255
{
	if (pixelValue > 255)
		pixelValue = 255;
	if (pixelValue < 0)
		pixelValue = 0;

	return pixelValue;
} 

void YUV2RGB(Mat image)
{

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{

			y = (int)image.at<Vec3b>(i, j)[0];
			u = (int)image.at<Vec3b>(i, j)[1];
			v = (int)image.at<Vec3b>(i, j)[2];

			//Get RGB values from YUV values
			r = 1.164*(y - 16) + 2.018*(v - 128);
			g = 1.164*(y - 16) - 0.813*(u - 128) - 0.391*(v - 128);
			b = 1.164*(y - 16) + 1.596*(u - 128);

			r = checkRange(r);
			g = checkRange(g);
			b = checkRange(b);

			image.at<Vec3b>(i, j)[0] = (uchar)b;
			image.at<Vec3b>(i, j)[1] = (uchar)g;
			image.at<Vec3b>(i, j)[2] = (uchar)r;
		}
	}

}


void RGB2YUV(Mat image)
{

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{

			b = (int)image.at<Vec3b>(i, j)[0];
			g = (int)image.at<Vec3b>(i, j)[1];
			r = (int)image.at<Vec3b>(i, j)[2];

			y = (0.257*r) + (0.504*g) + (0.098*b) + 16;
			v = (0.439*r) - (0.368 * g) - (0.071*b) + 128;
			u = -(0.148*r) - (0.291*g) + (0.439*b) + 128;
		
			image.at<Vec3b>(i, j)[0] = (uchar)y;
			image.at<Vec3b>(i, j)[1] = (uchar)u;
			image.at<Vec3b>(i, j)[2] = (uchar)v;

		}
	}
}

void HSL2RGB(Mat img)
{
	
	float c, x, m;

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{

			h = (double)img.at<Vec3b>(i, j)[0] * 2;
			l = (double)img.at<Vec3b>(i, j)[1] / 255;
			s = (double)img.at<Vec3b>(i, j)[2] / 255;

			c = (1 - abs(2 * l - 1))*s;
			x = c * (1 - (abs(fmod((h / 60), 2) - 1)));
			m = l - (c / 2);


			if (h >= 0 && h < 60)
			{
				r = c;
				g = x;
				b = 0;
			}

			if (h >= 60 && h < 120)
			{
				r = x;
				g = c;
				b = 0;
			}

			if (h >= 120 && h < 180)
			{
				r = 0;
				g = c;
				b = x;
			}

			if (h >= 180 && h < 240)
			{
				r = 0;
				g = x;
				b = c;
			}

			if (h >= 240 && h < 300)
			{
				r = x;
				g = 0;
				b = c;
			}

			if (h >= 300 && h < 360)
			{
				r = c;
				g = 0;
				b = x;
			}

			r = (r + m) * 255;
			g = (g + m) * 255;
			b = (b + m) * 255;



			img.at<Vec3b>(i, j)[0] = (uchar)b;
			img.at<Vec3b>(i, j)[1] = (uchar)g;
			img.at<Vec3b>(i, j)[2] = (uchar)r;
		}
	}

}

void RGB2HSL(Mat img)
{

	double Vmin = 0, Vmax = 0, delta = 0;

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{

			b = (double)img.at<Vec3b>(i, j)[0] / 255;
			g = (double)img.at<Vec3b>(i, j)[1] / 255;
			r = (double)img.at<Vec3b>(i, j)[2] / 255;

			//find min
			Vmin = r;
			if (b < Vmin)
				Vmin = b;
			if (g < Vmin)
				Vmin = g;

			//find max
			Vmax = r;
			if (b > Vmax)
				Vmax = b;
			if (g > Vmax)
				Vmax = g;

			delta = Vmax - Vmin;

			//L
			l = (Vmax + Vmin) / 2;
		
			//S
			if (l < 0.5)
			{
				s = delta / (Vmax + Vmin);
			}
			else
			{
				s = delta / (2 - (Vmax + Vmin));
			}

			//H
			if (Vmax == r)
				h = (g - b) / delta;

			else if (Vmax == g)
				h = 2 + ((b - r) / delta);


			else if (Vmax == b)
				h = 4 + ((r - g) / delta);

			h = h * 60;

			if (h < 0)
				h += 360;

			cout << h << " " << l << " " << s << endl;


			img.at<Vec3b>(i, j)[0] = h;
			img.at<Vec3b>(i, j)[1] = l;
			img.at<Vec3b>(i, j)[2] = s;

		}
	}
}

