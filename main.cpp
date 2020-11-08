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
	double M[ARRAYSIZE][ARRAYSIZE] = {{1., 0.},{0.,2.}};
	double K[ARRAYSIZE][ARRAYSIZE] = {{1., 1.},{0.,1.}};
	double D[ARRAYSIZE][ARRAYSIZE] = {{0., 0.},{0.,0.}};
	
	int i,j,k;
	
	buildDynamicMatrix(M,K,D);
	buildQR(M,K,D);
	
	for(i=0;i<ARRAYSIZE;i++) {
		for(j=0;j<ARRAYSIZE;j++) {
			data_out<<D[i][j]<<'\t';
		}
		data_out<<endl;
	}
}