#include "matrixFunctions.h"

void buildQR(double A[ARRAYSIZE][ARRAYSIZE], double Q[ARRAYSIZE][ARRAYSIZE], double R[ARRAYSIZE][ARRAYSIZE]){
	//takes A and decomposes it into Q and R, with QR = A (Separated into three parts below) 
	//...
	
	//Given matrix A: If nonsymmetric balance and reduce to Hessenberg Form 
	
	//(1) Balancing: Reduce sensitivity of eigenvalues to rounding errors during the execution 
	// (calls Balance Function)
	
	
	//( 2)  Reduction to Hessenberg form by applying the elimination method (analogous to Gaussian elimination with pivoting)
	//  (calls function UpperHessenberg to update matrix A to upper Hessenberg form )
	
	
	// (3) Taking an upper Hessenberg form matrix and solve for eigenvalues 
	
	
}
