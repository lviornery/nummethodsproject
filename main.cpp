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
	
	/*double M[ARRAYSIZE][ARRAYSIZE] = {{1., 0.},{0.,2.}};
	double K[ARRAYSIZE][ARRAYSIZE] = {{1., 1.},{0.,1.}};
	double D[ARRAYSIZE][ARRAYSIZE] = {{0., 0.},{0.,0.}};
	
	double Q[ARRAYSIZE][ARRAYSIZE] = {{0., 0.},{0.,0.}};
	double R[ARRAYSIZE][ARRAYSIZE] = {{0., 0.},{0.,0.}};*/
	
	double A[ARRAYSIZE][ARRAYSIZE] = {{-0.445293304102772,4.90634972287693,-0.878713477733992,6.30363730185166},
		{-6.39413572242872,13.3536785709153,1.66680187467294,11.9447676898663},
		{3.68424494757762,-6.66171912949050,-0.0600206459796682,-7.00428933839067},
		{3.12092682065852,-5.20521249499678,-1.41298995307265,-2.84836462083286}};
	
	//buildDynamicMatrix(M,K,D);
	gaussianHessenberg(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	hessenbergQRUpdate(A);
	
	//write D to file
	
	for(i=0;i<ARRAYSIZE;i++) {
		for(j=0;j<ARRAYSIZE;j++) {
			//data_out<<D[i][j]<<'\t';
			data_out<<A[i][j]<<'\t';
		}
		data_out<<endl;
	}
	
	//buildQR(D,Q,R);
}