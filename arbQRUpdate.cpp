#include <math.h>
#include "matrixFunctions.h"
#define SIGN(g) (g < 0 ? -1. : 1.)

void arbQRUpdate(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in an arbitrary symmetric matrix A and first applies Householder reflectors to 
	// transform the matrix into Hessenberg form and then runs a QR algorithm iteration on it
	//This function takes in a matrix A and turns it into a Hessenberg matrix using Householder reflectors
	int i,j,k,l; //Counters for iterations below
	double normx, normu, val;
	//P holds the u Householder reflectors
	double P[ARRAYSIZE][ARRAYSIZE];
	double tempM[ARRAYSIZE][ARRAYSIZE];
	
	for (i=0;i<ARRAYSIZE;i++) {
		//initialize val
		val = 0;
		//The ith column of A will be x. Add x_j^2 to the norm counter
		for (j=i;j<ARRAYSIZE;j++) {
			val += pow(A[j][i],2);
		}
		//norm of x = sqrt(sum(x_j^2))
		normx = sqrt(val);
		//norm of u is like norm of x with some extra stuff tacked on
		normu = sqrt(val + 2.*SIGN(A[i][i])*normx*A[i][i] + val);
		//the top element of u should be the ith element of x plus the sign of the ith element of x times the norm of x - this is the extra stuff we factored into our norm of u above
		for (j=0;j<i;j++) {
			P[j][i] = 0.;
		}
		P[i][i] = (A[i][i] + SIGN(A[i][i])*normx)/normu;
		//the other elements of u should just be the elements of x over the norm of u
		for (j=i+1;j<ARRAYSIZE;j++) {
			P[j][i] = A[j][i]/normu;
		}
		//Calculate the new A
		//the jth row kth column will get itself minus 2*[(the kth element of u)*(the lth element of u)*(the lth row kth column element of A)]
		//we calculate the quantity in brackets below
		for (j=0;j<ARRAYSIZE;j++) { //jth row
			for (k=0;k<ARRAYSIZE;k++) { //kth column
				val = 0.;
				for (l=0;l<ARRAYSIZE;l++) {
					val += P[j][i]*P[l][i]*A[l][k]; 
				}
				tempM[j][k] = 2.*val;
			}
		}
		//And then modify A
		for (j=0;j<ARRAYSIZE;j++) {
			for (k=0;k<ARRAYSIZE;k++) {
				if (k<=i && j > k) {
					A[j][k] = 0.;
				}
				else {
					A[j][k] -= tempM[j][k];
				}
			}
		}
	}
	//Perform a QR algorithm iteration by setting A = RQ
	//the jth row kth column will get itself minus 2*[(the kth element of u)*(the lth element of u)*(the lth row kth column element of A)]
	for (i=0;i<ARRAYSIZE;i++) { //for each u in P
		for (j = 0;j<ARRAYSIZE;j++) { //for each row
			for (k=0;k<ARRAYSIZE;k++) { //for each column
				val = 0.;
				for (l=0;l<ARRAYSIZE;l++) {
					val += P[k][i]*P[l][i]*A[j][l]; 
				}
				tempM[j][k] = 2.*val;
			}
		}
		for (j=0;j<ARRAYSIZE;j++) {
			for (k=0;k<ARRAYSIZE;k++) {
				A[j][k] -= tempM[j][k];
			}
		}
	}
}
