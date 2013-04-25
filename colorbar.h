#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <fstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class ColorBar {
public:
	ColorBar() {};

	void set_pixel_dimensions (void) {
		cout << "Input the number of pixels in the x direction followed by the number of pixels in the y direction: ";
		cin >> size_x >> size_y;
	}

	void set_filename (void) {
		cout << "Enter the filename you wish to write to, with a .ppm file extension: ";
		cin >> filename;
	}

	void write (void) {
		ofstream out (filename.c_str(), ios_base::binary);
		out << "P6" << endl << size_x << " " << size_y << endl << 255 << endl;

		unsigned char rr, gg, bb;
		for (int y = size_y; y > 0; y--) {
			double vn = (double) y / (double) size_y;
			rr = 255 * sin(M_PI*vn);
			gg = 255 * (pow(sin(M_PI*vn), 2) + (1-vn))/2;
			bb = 255 * sin(1-vn);

			for (int x = 0; x < size_x; x++) {
				out << rr << gg << bb;
			}
		}

	}

private:
	int size_x;
	int size_y;

	string filename;


};