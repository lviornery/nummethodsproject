#include <math.h>
#include "matrixFunctions.h"

using namespace std;

void buildDynamicMatrix(double M[ARRAYSIZE][ARRAYSIZE], double K[ARRAYSIZE][ARRAYSIZE], double D[ARRAYSIZE][ARRAYSIZE]){
	//takes M and K and calculates D = M^-1 K using the LU decomposition
	int i,j,k,f; // loop counters
	
	double L[ARRAYSIZE][ARRAYSIZE]; // lower triangular matrix
	double U[ARRAYSIZE][ARRAYSIZE]; // upper triangular matrix
	
	double y[ARRAYSIZE]; // intermediate solution vector
	
	double sum; // dummy variable to keep track of sums in decomposition
	
	// initialize L and U
	for(i=0;i<ARRAYSIZE;i++) {
		for(j=0;j<ARRAYSIZE;j++){
			L[i][j] = 0.;
			U[i][j] = 0.;
		}
	}
	
	for(i=0;i<ARRAYSIZE;i++) U[i][i] = 1.; // for Crout reduction
	
	// Do the LU decomposition using the Crout reduction
   
	for(i=0;i<ARRAYSIZE;i++) { // loop over pairs of L columns and U rows. The three levels of loop indicate n^3 behavior

		// first, column i of L

		for(j=i;j<ARRAYSIZE;j++) { // i is the row
			sum=0.;
			for(k=0;k<=i-1;k++) sum = sum + L[j][k]*U[k][i];
			L[j][i] = M[j][i] - sum;
		}

		// second, row i of U

		for(j=i+1;j<ARRAYSIZE;j++){ // j is the column
			sum = 0.;
			for(k=0;k<=i-1;k++) sum = sum + L[i][k]*U[k][j];
			U[i][j] = (M[i][j] - sum)/L[i][i];
		}
	}
	//calculate M^-1 K as a matrix whose columns are the solution vectors to the equation Mx=K_i
	
	for(i=0;i<ARRAYSIZE;i++) { //for each column of k
	
		//calculate the intermediate solution first
	
		y[0] = K[0][i]/L[0][0];
		for(j=1;j<ARRAYSIZE;j++) {
			sum = 0.;
			for(k=0;k<j;k++) sum = sum + L[j][k]*y[k];
			y[j] = (K[j][i]-sum)/L[j][j];
		}
		
		//now the ith column of D
		
		D[ARRAYSIZE-1][i] = y[ARRAYSIZE-1];
		for(j=1;j<ARRAYSIZE;j++) {
			k = ARRAYSIZE-j-1;
			sum = 0;
			for(f=k+1;f<ARRAYSIZE;f++) sum = sum + U[k][f]*D[f][i];
			D[k][i] = y[k] - sum;
		}
	}
}