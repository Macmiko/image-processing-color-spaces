/*Nale�y zaimplementowa� algorytmy przej�cia pomi�dzy przestrzeniami barw RGB oraz HSL i YUV oraz odwrotne. 
Nale�y te� zaimplementowa� jedn� operacj�, kt�ra pozwala na modyfikacj� obrazu z u�yciem przestrzeni HSL lub YUV. 
Algorytmy powinny dzia�a� na obrazach wielokana�owych.

Wiele przestrzeni, opcjonalna normalizacja

*/


#include"ColorsConverter.h"
#include"Interface.h"
#include"colorModifier.h"

using namespace std;
using namespace cv;

int main()
{
	Mat image;
	string img_path="C://Users/Mikolaj/Pictures/lena.jpg"; //get file path
	
	image = imread(img_path);
	menu(image); 

	return 0;
}