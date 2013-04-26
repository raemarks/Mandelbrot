#include "mandelbrot.h"

using namespace std;

void MandelbrotImage::set_corners (void) {
	cout << "Enter the complex number corresponding to the lower left conrner of the image [(a, b)]: ";
	cin >> low_left;
	cout << "Enter the complex number corresponding to the upper right conrner of the image [(a, b)]: ";
	cin >> up_right;
}

void MandelbrotImage::set_size (void) {
	cout << "Input the number of pixels in the x direction: ";
	cin >> size_x;
	size_y = size_x * ((up_right.imag() - low_left.imag()) / (up_right.real() - low_left.real()));
	cout << "Number of pixels in the y direction: " << size_y << endl;
}

void MandelbrotImage::set_filename (void) {
	cout << "Enter the filename you wish to write to, with a .ppm file extension: ";
	cin >> filename;
}

void MandelbrotImage::write (void) {
	ofstream out (filename.c_str(), ios_base::binary);
	out << "P6" << endl << size_x << " " << size_y << endl << 255 << endl;

	double a, b, vn;
	int iterations;
	unsigned char rr, gg, bb;
	for (int y = 0; y < size_y; y++) {
		for (int x = 0; x < size_x; x++) {

			a = low_left.real() + (x*(up_right.real() - low_left.real()) / (size_x - 1));
			b = up_right.imag() - (y*(up_right.imag() - low_left.imag()) / (size_y - 1));

			dcomplex c(a, b); 
			iterations = mandelbrot(c, 0, 255, 1);

			vn = (double) iterations/256;

			rr = 255 * sin(M_PI*vn);
			gg = 255 * (pow(sin(M_PI*vn), 2) + (1-vn))/2;
			bb = 255 * sin(1-vn);

			out << (int) rr << ' '<< (int) gg << ' '<< (int) bb << ' ';
		}
	}
}

int MandelbrotImage::mandelbrot (dcomplex c, dcomplex z, int max, int iterations) {
		while ((iterations <= max) || (norm(z) <= 4)) {
			z = c + z*z;
		}

		return iterations;
		//if ((iterations > max || norm(z) > 4)) {
		//	return iterations; 
		//}

		////cout << "Iterations: " << iterations << " Zn: " << z << " norm of Zn: " << norm(z) << endl;
		//z = c + z*z;

		//mandelbrot (c, z, max, ++iterations);
}
