#include <fftw3.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Macros for the real and imaginary parts
#define REAL 0
#define IMAG 1
#define MAX 2200

int main( int argc, char **argv )
{
    FILE *file = fopen(argv[1], "r");
    float arraydata[MAX];
    int i = 0;
    int final = 0;
    if (file != NULL) {
        while (!feof(file) && i < MAX) {
            if (fscanf(file, "%f", &arraydata[i++]) != -1) {
                printf("%f \n", arraydata[i-1]);
		final = i;
            }
        }
        fclose(file);
    } else {
        printf("Unable to open file");
        return EXIT_FAILURE;
    }

	// Define the length of te complex arrays
	int n = final;
	// Input array
	fftw_complex x[n]; // This is equivalent to: double x[n][2];
	// Output array
	fftw_complex y[n]; // 
	// Fill the first array with some data
	for (int i=0; i<n; i++){
		x[i][REAL] = arraydata[i];
		x[i][IMAG] = 0;
	}
	
	// Plan the FFT and execute it
	fftw_plan plan = fftw_plan_dft_1d(n, x, y, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(plan);
	// Do some cleaning
	fftw_destroy_plan(plan);
	fftw_cleanup();
	// Display the results
	cout << "\n\nFFT = " << endl;
	for (int i=0; i<n; i++)
		if (y[i][IMAG]<0)
			cout << y[i][REAL] << " - " << abs(y[i][IMAG]) << "i" << endl;
		else
			cout << y[i][REAL] << " + " << y[i][IMAG] << "i" << endl;

// Write my output
	FILE *salida;
	salida = fopen("salida.fftw","w");
	for (int i=0; i<n; i++){
		fprintf( salida,"%.4f,%.4f\n",y[i][REAL], y[i][IMAG] );
	}
	fclose(salida);

	return 0;
}
