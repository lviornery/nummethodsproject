#include <math.h>
#include "matrixFunctions.h"

using namespace std;

void shiftHessQRUpdate(double H[ARRAYSIZE][ARRAYSIZE]){
	//This function takes in am upper Hessenberg matrix H and applies a shift used to get faster eigenvalue convergence
	
	int i,j;
	double subdiag, b, c, d, shift, eig1, eig2;
	for (i=1;i<ARRAYSIZE;i++) {
		j = ARRAYSIZE-i;
		if (j > 0) {
			subdiag = H[j][j-1];
			if (fabs(subdiag) > TOL){
				break;
			}
			else {
				H[j][j-1] = 0.;
			}
		}
	}
	if (i < ARRAYSIZE) { //if we actually found a large subdiagonal element
		//calculate the eigenvalues of the 2x2 submatrix which includes the first subdiagional element from the bottom right larger than the tolerance
		b = -(H[j-1][j-1]+H[j][j]);
		c = H[j-1][j-1]*H[j][j] - H[j-1][j]*H[j][j-1];
		d = b*b-4.*c;
		eig1 = eig2 = -b/2.;
		//the submatrix may have complex eigenvalues; we address this by only using the real part.
		if (d > 0) {
			eig1 += sqrt(d)/2.;
			eig2 -= sqrt(d)/2.;
		}
		//the eigenvalue closer to the furthest diagonal element is used as the shift
		if (fabs(H[j][j]-eig1) < fabs(H[j][j]-eig2)) {
			shift = eig1;
		}
		else {
			shift = eig2;
		}
		for (j=0;j<ARRAYSIZE;j++) {
			H[j][j] -= shift;
		}
	}
	hessenbergQRUpdate(H);
	if (i < ARRAYSIZE) {//shift back if we need to
		for (j=0;j<ARRAYSIZE;j++) {
			H[j][j] += shift;
		}
	}
}
