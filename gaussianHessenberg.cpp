#include <math.h>
#include "matrixFunctions.h"
#define SWAP(g,h) {val=(g);(g)=(h);(h)=val;}

void gaussianHessenberg(double A[ARRAYSIZE][ARRAYSIZE]){
	//takes A and turns it into a Hessenberg matrix using pseudo-gaussian elimination
	int i,j,k; // counters
	int imax, swaprow;
	double max, val, mult;
	for(i=0;i<(ARRAYSIZE-1);i++) { //i is the ith column - we start from column 0
		//find the max element below the diagonal
		swaprow = i+1;
		max = 0.;
		imax = swaprow;
		for(j = imax;j<ARRAYSIZE;j++) {
			val = A[j][i];
			if(fabs(val)>fabs(max)) {
				imax = j;
				max = val;
			}
		}
		if(imax != swaprow) {
			//we can start from j = i because we assume all entries in rows j and swaprow prior to column i are zero
			for(j=i;j<ARRAYSIZE;j++) SWAP(A[imax][j],A[swaprow][j]);
			for(j=0;j<ARRAYSIZE;j++) SWAP(A[j][imax],A[j][swaprow]);
		}
		if(max) {
			for(j=i+2;j<ARRAYSIZE;j++) {
				mult = A[j][i];
				if(mult !=0.) {
					mult /= max;
					A[j][i]=0.;
					for(k=swaprow;k<ARRAYSIZE;k++) A[j][k] -= mult*A[swaprow][k];
					for(k=0;k<ARRAYSIZE;k++) A[k][swaprow] += mult*A[k][j];
				}
			}
		}
	}
}