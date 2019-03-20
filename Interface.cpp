#include"Interface.h"
#include"ColorsConverter.h"
#include"colorModifier.h"


using namespace std;
using namespace cv;

void showImage(Mat image, string &windowName)
{
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, image);
	waitKey(0);

}



void menu(Mat inputImg)
{
	int inputCS; // color space of input image
	int outputCS; // color space of output image

	string windowName1 = "Input";
	string windowName2 = "Output";
	string windowName3 = "OpenCV_result";

	cout << "Choose the color space of the input image" << endl;
	cout << "1. RGB" << endl;
	cout << "2. HSL" << endl;
	cout << "3. YUV" << endl;

	cin >> inputCS;

	if (inputCS == 1 || inputCS == 2 || inputCS == 3)
		cout << "Choose the color space of the output image" << endl;

	else
	{
		while (inputCS != 1 && inputCS != 2 && inputCS != 3)
		{
			cout << "Write the correct answer (1 or 2 or 3)." << endl;
			cin >> inputCS;

		}
		cout << "Choose the color space of the input image" << endl;

	}


	switch (inputCS)
	{
	case 1:
	{
		cout << "1. HSL" << endl;
		cout << "2. YUV" << endl;
		cin >> outputCS;

		if (outputCS == 1 || outputCS == 2)
			cout << "Click space to see the result" << endl;

		else
		{
			while (outputCS != 1 && outputCS != 2)
			{
				cout << "Write the correct answer (1 or 2)." << endl;
				cin >> outputCS;

			}
			cout << "Click space to see the result" << endl;

		}


		if (outputCS == 1)
		{
			cout << "Input data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName1); //show input image

			RGB2HSL(inputImg); 

			cout << "Output data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName2); //show resualt
		}

		else
		{
			cout << "Input data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName1); //show input image

			RGB2YUV(inputImg);

			cout << "Output data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName2); //show resualt

		}

		break;
	}

	case 2:
	{
		RGB2HSL(inputImg);
		cout << "1. RGB" << endl;
		cout << "2. YUV" << endl;
		cin >> outputCS;

		if (outputCS == 1 || outputCS == 2)
			cout << "Click space to see the result" << endl;

		else
		{
			while (outputCS != 1 && outputCS != 2)
			{
				cout << "Write the correct answer (1 or 2)." << endl;
				cin >> outputCS;

			}
			cout << "Click space to see the result" << endl;

		}



		if (outputCS == 1)
		{
			cout << "Input data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName1); //show input image
			
			HSL2RGB(inputImg);

			cout << "Output data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName2); //show resualt
		}

		else
		{
			cout << "Input data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName1); //show input image

			HSL2RGB(inputImg);
			RGB2YUV(inputImg);

			cout << "Output data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName2); //show resualt
		}
		break;
	}


	case 3:
	{
		RGB2YUV(inputImg);
		cout << "1. RGB" << endl;
		cout << "2. HSL" << endl;
		cin >> outputCS;

		if (outputCS == 1 || outputCS == 2)
			cout << "Click space to see the result" << endl;

		else
		{
			while (outputCS != 1 && outputCS != 2)
			{
				cout << "Write the correct answer (1 or 2)." << endl;
				cin >> outputCS;

			}
			cout << "Click space to see the result" << endl;

		}



		if (outputCS == 1)
		{
			cout << "Input data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName1); //show input image

			YUV2RGB(inputImg);

			cout << "Output data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName2); //show resualt
		}

		else
		{
			cout << "Input data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName1); //show input image

			YUV2RGB(inputImg);
			RGB2HSL(inputImg);

			cout << "Output data successfully found.  Rows:" << inputImg.rows << " cols:" << inputImg.cols << " channels:" << inputImg.channels() << "\n";
			showImage(inputImg, windowName2); //show resualt
		}
		break;
	}

	default:
		break;
	}

	createTrackbars(inputImg); 
}

