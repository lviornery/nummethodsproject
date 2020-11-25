#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <chrono> 
#include "matrixFunctions.h"
using namespace std;
using namespace std::chrono;

ofstream data_out("output.txt"); // output data

int main() {
	
	int i,j,k; //loop variables
	bool convergence = false;
	
	double M[ARRAYSIZE][ARRAYSIZE];
	double K[ARRAYSIZE][ARRAYSIZE];
	double D[ARRAYSIZE][ARRAYSIZE];
	double eig[ARRAYSIZE];
	
	readMatrices(M,K);
	auto start = high_resolution_clock::now();
	//time building the dynamic matrix
	//---
	buildDynamicMatrix(M,K,D);
	//---
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Dynamic matrix build time :" << duration.count() << "us" << endl; 
	start = high_resolution_clock::now();
	//time eigenvalue finding
	//---
	//balance the dynamic matrix to reduce rounding errors
	balance(D);
	//comment the below out if using arbQRUpdate
	//convert the matrix to upper Hessenberg form 
	gaussianHessenberg(D);
	//initialize eig
	for (i=0;i<ARRAYSIZE;i++) {
		eig[i] = D[i][i];
	}
	k = 0; //initialize loop counter
	//While our eigenvalues haven't converged
	while (!convergence) {
		k++;
		//do a QR iteration - we can use arbQRUpdate, or the Hessenberg version with or without shifts
		shiftHessQRUpdate(D);
		//hessenbergQRUpdate(D);
		//arbQRUpdate(D)
		//assume we've converged
		convergence = true;
		for (i=0;i<ARRAYSIZE;i++) {
			//if any eigenvalue shift is greater than the convergence tolerance
			if (fabs(eig[i]-D[i][i]) > TOL) {
				//we haven't converged
				convergence = false;
			}
			//store the new eigenvalues
			eig[i] = D[i][i];
		}
	}
	//---
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Eigenvalue find time :" << duration.count() << "us" << endl; 
	cout << "QR Algorithm iterations :" << k << endl; 
	for(i=0;i<ARRAYSIZE;i++) {
		data_out<<eig[i]<<endl;
	}
}