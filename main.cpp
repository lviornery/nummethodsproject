#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include "matrixFunctions.h"
using namespace std;

ofstream data_out("output.txt"); // output data

int main() {
	
	int i,j,k; //loop variables
	
	double M[ARRAYSIZE][ARRAYSIZE];
	double K[ARRAYSIZE][ARRAYSIZE];
	double D[ARRAYSIZE][ARRAYSIZE];
	
	readMatrices(M,K);
	buildDynamicMatrix(M,K,D);
	
	/*gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);
	gaussianHessenberg(D);*/
	
	//write D to file
	
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