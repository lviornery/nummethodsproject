#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <chrono> 
#include "matrixFunctions.h"
using namespace std;
using namespace std::chrono;

ofstream eigfile("eigenvalues.txt"); // eigenvalue output

int main() {
	
	int i,j; //loop variables
	bool convergence = false;
	
	double M[ARRAYSIZE][ARRAYSIZE];
	double K[ARRAYSIZE][ARRAYSIZE];
	double D[ARRAYSIZE][ARRAYSIZE];
	double eig[ARRAYSIZE];
	double diff, val;
	
	char method;
	
	cout << "Select eigenvalue finding method" << endl << "a: basic QR algorithm" << endl << "b: basic Hessenberg QR algorithm" << endl << "c: Hessenberg QR algorithm with shifts (default)" << endl;
	
	cin >> method;
	
	readMatrices(M,K);
	auto start = high_resolution_clock::now();
	//time building the dynamic matrix
	//---
	buildDynamicMatrix(M,K,D);
	//---
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Dynamic matrix build time: " << duration.count() << "us" << endl; 
	cout << "Starting QR algorithm" << endl; 
	start = high_resolution_clock::now();
	//time eigenvalue finding
	//---
	//balance the dynamic matrix to reduce rounding errors
	balance(D);
	cout << "Dynamic matrix balanced." << endl;
	//convert the matrix to upper Hessenberg form if not using the basic QR algorithm
	if (method != 'a') {
		gaussianHessenberg(D);
		cout << "Dynamic matrix converted to upper Hessenberg form." << endl; 
	}
	//initialize eig
	for (i=0;i<ARRAYSIZE;i++) {
		eig[i] = D[i][i];
	}
	j = 0; //initialize loop counter
	//While our eigenvalues haven't converged
	cout << "Starting QR iterations." << endl; 
	while (!convergence) {
		j++;
		//do a QR iteration - we can use arbQRUpdate, or the Hessenberg version with or without shifts
		if (method == 'a') {
			arbQRUpdate(D);
		}
		else if (method == 'b') {
			hessenbergQRUpdate(D);
		}
		else {
			shiftHessQRUpdate(D);
		}
		//assume we've converged
		convergence = true;
		diff = 0;
		for (i=0;i<ARRAYSIZE;i++) {
			//uncomment if tracking eigenvalue deltas
			/*val = fabs(eig[i]-D[i][i]);
			if (val > diff) {
				diff = val;
			}*/
			//if any eigenvalue shift is greater than the convergence tolerance
			if (fabs(eig[i]-D[i][i]) > TOL) {
				//we haven't converged
				convergence = false;
			}
			//store the new eigenvalues
			eig[i] = D[i][i];
		}
		//this is slow but useful to make sure it's working...
		//cout << "Max eigenvalue difference this iteration: " << diff << endl;
	}
	//---
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Eigenvalue find time: " << duration.count() << "us" << endl; 
	cout << "QR Algorithm iterations: " << k << endl; 
	for(i=0;i<ARRAYSIZE;i++) {
		eigfile<<eig[i]<<endl;
	}
}