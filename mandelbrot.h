#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <complex>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef std::complex<double> dcomplex;
using namespace std;

class MandelbrotImage {
public:
	void set_corners (void);

	void set_size (void);

	void set_filename (void);

	void write (void);

private:
	int mandelbrot (dcomplex c, dcomplex z, int max, int iterations);
	string filename;
	dcomplex low_left;
	dcomplex up_right;
	int size_x;
	int size_y;
};
