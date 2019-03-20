/*Nale¿y zaimplementowaæ algorytmy przejœcia pomiêdzy przestrzeniami barw RGB oraz HSL i YUV oraz odwrotne. 
Nale¿y te¿ zaimplementowaæ jedn¹ operacjê, która pozwala na modyfikacjê obrazu z u¿yciem przestrzeni HSL lub YUV. 
Algorytmy powinny dzia³aæ na obrazach wielokana³owych.

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