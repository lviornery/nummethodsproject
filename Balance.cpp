#include <math.h>
#include "matrixFunctions.h"
#define radix 2.0 //2 for most machines, 16 for IBM mainframe

void balance(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in a matrix A and then outputs a balanced matrix with identical eigenvalues 
	// (Reduces sensitivity of eigenvalues to rounding errors)
	//Output: Matrix that is balanced in the norm by summing the absolute magnitudes of the matrix elements
	
	//Need to work on commenting it more in detail 
	int i, k, final;
	double row, g, f, column,sum, SQRDX;
	
	SQRDX = radix*radix;
	final = 0;
	while ( final == 0){
		
		final = 1;
		//This for loop calculates the row and column norms 
		for (i = 1; i<= ARRAYSIZE; i++){
			row= column = 0.0;
			for (k =1; k<=ARRAYSIZE; k++)
				if (k != i {
					column += fabs(A[k][i]);
					row += fabs(A[i][j]);
				}
			//Non-zero case below
			if (column && row) {
				g = row/radix;
				f = 1.0;
				sum = column+row;
				//While loop is searching for the integer power of radix that is closest to balancing matrix
				while (column< g) {
					f *= radix;
					column *= SQRDX;
				}
				g = row*radix;
				while (column>g) {
					f /= radix;
					column /= SQRDX;
				}
				if ((column+row)/f < 0.95*sum) {
					final = 0;
					g = 1.0/f;
					//Similarity transformations 
					for (k =1; k <= ARRAYSIZE; k++){
						A[i][k] *= g;
					}
					for (k =1; k <= ARRAYSIZE; k++){
						A[k][i] *= f;
					}
				}
			}
		}
	}
}
