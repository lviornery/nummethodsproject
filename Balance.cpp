#include <math.h>
#include "matrixFunctions.h"
#define radix 2.0 //2 for most machines, 16 for IBM mainframe
#define SQRDX 4.0

void balance(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in a matrix A and then outputs a balanced matrix with identical eigenvalues 
	// (Reduces sensitivity of eigenvalues to rounding errors)
	//Output: Matrix that is balanced in the norm by summing the absolute magnitudes of the matrix elements
	
	//Need to work on commenting it more in detail 
	int i, k, last;
	double row, g, f, column, sum;
	
	//intialize last
	last = 0;
	while ( last == 0){
		last = 1; //default to breaking the loop
		//For each row/column
		for (i = 0; i< ARRAYSIZE; i++){
			//initialize rowsum and colsum
			row = column = 0.0;
			//add up the magnitudes of the off-diagonal elements in this row/column
			for (k=0; k<ARRAYSIZE; k++) {
				if (k != i) {
					column += fabs(A[k][i]);
					row += fabs(A[i][k]);
				}
			}
			//If there are off-diagonal elements in this row/column
			if (column && row) {
				//g and f are the elements of the diagonal matrix D we can employ to balance the matrix
				//initialize g as the off-diagonal row magnitude sum divided by the base of the system; rowsum = g*radix
				g = row/radix;
				//initialize f as 1
				f = 1.0;
				//initialize sum as the sum of the magnitudes of all off-diagonal elements in this column/row
				sum = column + row;
				//Find the integer power of radix that balances the matrix
				while (column < g) {
					//if the column sum is less than the row sum over the radix, blow up the column sum until that isn't the case, and track that change using f
					f *= radix;
					column *= SQRDX;
				}
				//set g to the off-diagonal row magnitude sum times the base of the system
				g = row*radix;
				while (column > g) {
					//if the inflated column sum is greater than the row sum times the radix, deflate the column sum until that isn't the case, and track the change using f
					f /= radix;
					column /= SQRDX;
				}
				//now f holds the radix to the power that we inflated/deflated by
				//if the inflated and then deflated column sum plus the row sum, all over the radix to the appropriate power is not close to the sum we calculated earlier, we should balance (inflation followed by deflation significantly changes the matrix)
				if ((column+row)/f < 0.95*sum) {
					//loop again, in case we need to balance iteratively
					last = 0;
					//g = f^-1, so similarity is preserved
					g = 1.0/f;
					//Apply D and D^-1
					for (k = 0; k < ARRAYSIZE; k++){
						A[i][k] *= g;
					}
					for (k = 0; k < ARRAYSIZE; k++){
						A[k][i] *= f;
					}
				}
			}
		}
	}
}
