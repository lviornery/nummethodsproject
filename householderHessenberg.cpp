#include <math.h>
#include "matrixFunctions.h"

void householderHessenberg(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in a matrix A and turns it into a Hessenberg matrix using Householder reflectors
	int i,j, k; //Counters for iterations below
	double x, m,u, p;
	
	//pseudo-code
	//for (i = 1; i <= ARRAYSIZE-2 ; i++) {
	//	p = reflector(A(i+1:end,i));
	//      A(i+1:ARRAYSIZE, i:ARRAYSIZE) = A(:, i+1: ARRAYSIZE) - 2*p*(p'*A(i+1:ARRAYSIZE,i:ARRAYSIZE));
	//      A(:, i+1:ARRAYSIZE) = A(:, i+1:ARRAYSIZE) -2*(A(:,i+1:ARRAYSIZE)*p)*p';
	//      A(i+2: ARRAYSIZE, i) = 0;
	// end 
	//Householder Transform P, where P = I -2uu^T (Householder reflector), u is the real unit vector 
	for (i = 1; i <= ARRAYSIZE-2 ; i++) {
		
		// Householder reflection unit vector u
		x = A((i+1):ARRAYSIZE, i);
		m = fmax(fabs(x));
		u = x/m;
		if (u(i) ==0)
			p = 1;
		elseif (u(i)> 0)
			p = 1;
		else
			p = -1; 
		end
		u(i) = u(i) +p*norm(u);
		u = u/norm(u);
		u = u(:);
		//Fixing syntax errors 
	      A(i+1:ARRAYSIZE, i:ARRAYSIZE) = A(:, i+1: ARRAYSIZE) - 2*u*(u'*A(i+1:ARRAYSIZE,i:ARRAYSIZE)); //Implementing the householder reflector 
	      A(:, i+1:ARRAYSIZE) = A(:, i+1:ARRAYSIZE) -2*(A(:,i+1:ARRAYSIZE)*u)*u';
	      A(i+2: ARRAYSIZE, i) = 0;
	end 
		
		
	}
	
	//
}
