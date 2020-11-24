#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <chrono> 
#include <stdio.h>
#include "matrixFunctions.h"
using namespace std;
using namespace std::chrono;

ofstream data_out("output.txt"); // output data

int main() {
	
	int i,j,k; //loop variables
	
	double M[ARRAYSIZE][ARRAYSIZE];
	double K[ARRAYSIZE][ARRAYSIZE];
	double D[ARRAYSIZE][ARRAYSIZE];
	
	readMatrices(M,K);
	auto start = high_resolution_clock::now();
	//time building the dynamic matrix
	buildDynamicMatrix(M,K,D);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Dynamic matrix build time :" << duration.count() << "us" << endl; 
	start = high_resolution_clock::now();
	//time eigenvalue finding
	
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Eigenvalue find time :" << duration.count() << "us" << endl; 
	for(i=0;i<ARRAYSIZE;i++) {
		for(j=0;j<ARRAYSIZE;j++) {
			data_out<<M[i][j]<<'\t';
		}
		data_out<<endl;
	}
	
	data_out<<endl;
	
	for(i=0;i<ARRAYSIZE;i++) {
		for(j=0;j<ARRAYSIZE;j++) {
			data_out<<K[i][j]<<'\t';
		}
		data_out<<endl;
	}
	
	data_out<<endl;
	
	for(i=0;i<ARRAYSIZE;i++) {
		for(j=0;j<ARRAYSIZE;j++) {
			data_out<<D[i][j]<<'\t';
		}
		data_out<<endl;
	}
	
	//buildQR(D,Q,R);
}