#include <math.h>
#include "matrixFunctions.h"

void arbQRUpdate(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in an arbitrary symmetric matrix A and first applies Householder reflectors to 
	// transform the matrix into Hessenberg form and then runs a QR algorithm iteration on it
	
	
	int i,j; // loop counters
	double hessC[ARRAYSIZE-1];
	double hessS[ARRAYSIZE-1];
	double val;
	for(i=0;i<ARRAYSIZE-1;i++) {
		val = sqrt(pow(H[i][i],2)+pow(H[i+1][i],2));
		hessC[i] = H[i][i]/val;
		hessS[i] = -1.*H[i+1][i]/val;
		//these are the coefficients of the Givens rotations. Each zaps away an off-diagonal element
		//we never explicitly calculate Q because it's more efficient to only touch the entries that are modified
		//if we did, it would be the product of the Givens rotations
		
		//Apply QH_k = R
		//Do it the fast and easy way for the first column
		H[i][i] = hessC[i]*H[i][i]-hessS[i]*H[i+1][i];
		H[i+1][i]=0.;
		//Then programatically for the rest
		for(j=i+1;j<ARRAYSIZE;j++) {
			val = hessC[i]*H[i][j]-hessS[i]*H[i+1][j];
			H[i+1][j] = hessS[i]*H[i][j]+hessC[i]*H[i+1][j];
			H[i][j] = val;
		}
	}
	//Apply H_k+1 = RQ
	for(i=0;i<ARRAYSIZE-1;i++) {
		for(j=0;j<=i;j++) {
			val = hessC[i]*H[j][i]-hessS[i]*H[j][i+1];
			H[j][i+1] = hessS[i]*H[j][i]+hessC[i]*H[j][i+1];
			H[j][i] = val;
		}
		H[i+1][i] = -hessS[i]*H[j][i+1];
		H[i+1][i+1] = hessC[i]*H[j][i+1];
	}
}
