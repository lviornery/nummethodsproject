#include <math.h>
#include "matrixFunctions.h"

void householderHessenberg(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in a matrix A and turns it into a Hessenberg matrix using Householder reflectors
	int i,j, k; //Counters for iterations below
	double p, scaling, hh, h, g, f;
	
	//pseudo-code
	//for (i = 1; i <= ARRAYSIZE-2 ; i++) {
	//	p = reflector(A(i+1:end,i));
	//      A(i+1:ARRAYSIZE, i:ARRAYSIZE) = A(:, i+1: ARRAYSIZE) - 2*p*(p'*A(i+1:ARRAYSIZE,i:ARRAYSIZE));
	//      A(:, i+1:ARRAYSIZE) = A(:, i+1:ARRAYSIZE) -2*(A(:,i+1:ARRAYSIZE)*p)*p';
	//      A(i+2: ARRAYSIZE, i) = 0;
	// end 
		
		
	}
	
	//
}
