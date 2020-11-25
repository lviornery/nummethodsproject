#include <math.h>
#include "matrixFunctions.h"
#include <iostream>
#include <stdio.h>
#define SIGN(g) (g < 0 ? -1. : 1.)

void arbQRUpdate(double A[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in an arbitrary symmetric matrix A and first applies Householder reflectors to 
	// transform the matrix into Hessenberg form and then runs a QR algorithm iteration on it
	//This function takes in a matrix A and turns it into a Hessenberg matrix using Householder reflectors
	int i,j,k,l; //Counters for iterations below
	double normx, normu, val;
	double x[ARRAYSIZE];
	double u[ARRAYSIZE];
	double P[ARRAYSIZE][ARRAYSIZE];
	double Q[ARRAYSIZE][ARRAYSIZE];
	double tempM[ARRAYSIZE][ARRAYSIZE];
	
	for (i=0;i<ARRAYSIZE;i++) {
		for (j=0;j<ARRAYSIZE;j++) {
			//Q starts as an identity matrix
			Q[i][j] = (i==j ? 1. : 0.);
		}
	}
	
	for (i=0;i<ARRAYSIZE;i++) {
		//initialize val
		val = 0;
		//skip any entries above the diagonal
		for (j=0;j<i;j++) {
			x[j] = 0.;
			u[j] = 0.;
		}
		//save the jth entry of the ith column of A in x and add x_j^2 to the norm counter
		for (j=i;j<ARRAYSIZE;j++) {
			x[j] = A[j][i];
			val += pow(x[j],2);
		}
		//norm of x = sqrt(sum(x_j^2))
		normx = sqrt(val);
		//norm of u is like norm of x with some extra stuff tacked on
		normu = sqrt(val + 2.*SIGN(x[i])*normx*x[i] + val);
		//the top element of u should be the ith element of x plus the sign of the ith element of x times the norm of x - this is the extra stuff we factored into our norm of u above
		u[i] = (x[i] + SIGN(x[i])*normx)/normu;
		//the other elements of u should just be the elements of x over the norm of u
		for (j=i+1;j<ARRAYSIZE;j++) {
			u[j] = x[j]/normu;
		}
		//the elements of P above the diagonal are just the identity matrix
		for (j=0;j<i;j++) {
			for (k=j+1;k<ARRAYSIZE;k++) {
				P[j][k] = P[k][j] = 0.;
			}
			P[j][j] = 1.;
		}
		//the other elements of P are given by I - 2uu'
		//the matrix is symmetric so we can do this the clever way
		for (j=i;j<ARRAYSIZE;j++) {
			for (k=j+1;k<ARRAYSIZE;k++) {
				P[j][k] = P[k][j] = -2.*u[j]*u[k];
			}
			P[j][j] = 1. - 2.*u[j]*u[j];
		}
		//multiply Q by P to get the new Q
		for (j=0;j<ARRAYSIZE;j++) {
			val = 0.;
			for (k=0;k<ARRAYSIZE;k++) {
				val = 0.;
				for (l=0;l<ARRAYSIZE;l++) {
					val += Q[j][l]*P[l][k];
				}
				tempM[j][k] = val;
			}
		}
		//Store the multiplication result in Q
		for (j=0;j<ARRAYSIZE;j++) {
			for (k = 0;k<ARRAYSIZE;k++) {
				Q[j][k] = tempM[j][k];
			}
		}
		//Calculate the new R
		for (j=0;j<ARRAYSIZE;j++) {
			for (k=0;k<ARRAYSIZE;k++) {
				val = 0.;
				for (l=0;l<ARRAYSIZE;l++) {
					val += P[j][l]*A[l][k];
				}
				tempM[j][k] = val;
			}
		}
		//Store the new R in A
		for (j=0;j<ARRAYSIZE;j++) {
			for (k=0;k<ARRAYSIZE;k++) {
				A[j][k] = tempM[j][k];
			}
		}
	}
	//Perform a QR algorithm iteration by setting A = RQ
	for (i=0;i<ARRAYSIZE;i++) {
		for (j = 0;j<ARRAYSIZE;j++) {
			val = 0.;
			for (k=0;k<ARRAYSIZE;k++) {
				val += A[i][k]*Q[k][j];
			}
			tempM[i][j] = val;
		}
	}
	for (i=0;i<ARRAYSIZE;i++) {
		for (j=0;j<ARRAYSIZE;j++) {
			A[i][j] = tempM[i][j];
		}
	}
}
