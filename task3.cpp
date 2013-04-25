#include <iostream>
#include <complex>
#include "colorbar.h"
#include "mandelbrot.h"
typedef std::complex<double> dcomplex;
using namespace std;

void mandelbrot (dcomplex c, dcomplex z, int max, int iterations);

int main (void) {
	//TASK 3
	/*dcomplex c;
	int iterations;
	cout << "Enter a complex number c in the form (a, b) followed by the maximum number of iterations: ";
	cin >> c >> iterations;
	mandelbrot(c, c, iterations, 1);
	*/

	//TASK 4
	//ColorBar bar;
	//bar.set_filename();
	//bar.set_pixel_dimensions();
	//bar.write();

	//TASK 5
	MandelbrotImage image;
	image.set_corners();
	image.set_size();
	image.set_filename();
	image.write();
}

void mandelbrot (dcomplex c, dcomplex z, int max, int iterations) {
	if ((iterations > max || norm(z) > 4)) {
		return; 
	}

	cout << "Iterations: " << iterations << " Zn: " << z << " norm of Zn: " << norm(z) << endl;
	z = c + z*z;

	mandelbrot (c, z, max, ++iterations);
}

