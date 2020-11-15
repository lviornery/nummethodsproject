#include <math.h>
#include "matrixFunctions.h"

void shiftHess(double H[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in am upper Hessenberg matrix H and applies a shift used to get faster eigenvalue convergence
	
	int i,k, hw;
	double Hnorm, m, P, r,s,w, q;
	
	Hnorm = 0.0;
	hw = ARRAYSIZE;
	//Forming a shift and searching for 2 consecutive subdiagonal elements
	x = H[hw][hw];
	y = H[hw-1][hw-1]
	w = H[hw][hw-1]*H[hw-1][hw];
	for ( i = ( hw -2); i>=1; i--){
		//Grouping terms to reduce possible roundoff when there are small off-diagonal elements
		m = H[i][i];
		r = x-m;
		s = y-m;
		P = (r*s -w)/H[i+1][i] + H[i][i+1]; //The shifts of origin at each stage 
		q= H[i+1][i+1]-m-r-s;
		r= H[i+2][i+1];
		//Scaling 
		s = fabs(P)+fabs(q)+fabs(r);
		P /= s;
		q /= s;
		r /= s;
	}
}
