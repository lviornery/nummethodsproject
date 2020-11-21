#include <math.h>
#include "matrixFunctions.h"

void arbQRUpdate(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in an arbitrary symmetric matrix A and first applies Householder reflectors to 
	// transform the matrix into Hessenberg form and then runs a QR algorithm iteration on it
	//This function takes in a matrix A and turns it into a Hessenberg matrix using Householder reflectors
	int i,j, k; //Counters for iterations below
	double x, m,u, p;
	double hessC[ARRAYSIZE-1];
	double hessS[ARRAYSIZE-1];
	double val;
	
	for (i = 1; i <= ARRAYSIZE-2 ; i++) {
		
		// Creating the Householder reflection unit vector u
		x = A(i+1:ARRAYSIZE, i);
		m = max(fabs(x));
		u = x/m;
		if u(i) ==0
			p = 1;
		elseif u(i)> 0
			p = 1;
		else
			p = -1; 
		end
		u(i) = u(i) +p*norm(u); 
		u = u/norm(u);
		u = u(:);
		//Applying the Householder Transformation along A 
	      A(i+1:ARRAYSIZE, i:ARRAYSIZE) = A(:, i+1: ARRAYSIZE) - 2*u*(u'*A(i+1:ARRAYSIZE,i:ARRAYSIZE)); //Implementing the householder reflector 
	      A(:, i+1:ARRAYSIZE) = A(:, i+1:ARRAYSIZE) -2*(A(:,i+1:ARRAYSIZE)*u)*u';
	      A(i+2: ARRAYSIZE, i) = 0;
	end 	
	}
	
									  
	double hessC[ARRAYSIZE-1];
	double hessS[ARRAYSIZE-1];
	double val;
	for(i=0;i<ARRAYSIZE-1;i++) {
		val = sqrt(pow(A[i][i],2)+pow(A[i+1][i],2));
		hessC[i] = A[i][i]/val;
		hessS[i] = -1.*A[i+1][i]/val;
		//these are the coefficients of the Givens rotations. Each zaps away an off-diagonal element
		//we never explicitly calculate Q because it's more efficient to only touch the entries that are modified
		//if we did, it would be the product of the Givens rotations
		
		//Apply QH_k = R
		//Do it the fast and easy way for the first column
		A[i][i] = hessC[i]*A[i][i]-hessS[i]*A[i+1][i];
		A[i+1][i]=0.;
		//Then programatically for the rest
		for(j=i+1;j<ARRAYSIZE;j++) {
			val = hessC[i]*A[i][j]-hessS[i]*A[i+1][j];
			A[i+1][j] = hessS[i]*A[i][j]+hessC[i]*A[i+1][j];
			A[i][j] = val;
		}
	}
	//Apply H_k+1 = RQ
	for(i=0;i<ARRAYSIZE-1;i++) {
		for(j=0;j<=i;j++) {
			val = hessC[i]*A[j][i]-hessS[i]*A[j][i+1];
			A[j][i+1] = hessS[i]*A[j][i]+hessC[i]*A[j][i+1];
			A[j][i] = val;
		}
		A[i+1][i] = -hessS[i]*A[j][i+1];
		A[i+1][i+1] = hessC[i]*A[j][i+1];
	}
}
