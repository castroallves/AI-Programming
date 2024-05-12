#include "pbPlots.h"
#include "supportLib.h"

int main(){
	double xs[] = {-2, -1, 0, 1, 2};
	double ys[] = {2, -1, -2, -1, 2};
	double t[35] = {1.0000,-1.0000,-1.0000,-1.0000,1.0000,1.0000,1.0000,1.0000,-1.0000,1.0000 ,-1.0000,-1.0000,1.0000,1.0000,-1.0000,
               -1.0000,1.0000,-1.0000,-1.0000,1.0000,1.0000,-1.0000,-1.0000,1.0000,-1.0000,1.0000,-1.0000,1.0000,-1.0000,1.0000,
                1.0000,1.0000,-1.0000,-1.0000,-1.0000};

                double x[4][35] = {{0.4329,0.3024,0.1349,0.3374,1.1434,1.3749,0.7221,0.4403,-0.5231,0.3255,0.5824,0.1340,0.1480,0.7359,0.7115,
                   0.8251,0.1569,0.0033,0.4243,1.0490,1.4276,0.5971,0.8475,1.3967,0.0044,0.2201,0.6300,-0.2479,-0.3088,-0.5180,
                   0.6833,0.4353,-0.1069,0.4662,0.8298}};
	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	DrawScatterPlot(canvasReference, 800, 800, xs, 8, ys, 8);

	size_t length;
	double *pngdata = ConvertToPNG(&length, canvasReference->image);
	WriteToFile(pngdata, length, "example1.png");
	DeleteImage(canvasReference->image);

	return 0;
}
