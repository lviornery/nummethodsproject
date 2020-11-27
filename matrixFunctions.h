#ifndef MATRIX_FUNCTIONS
#define MATRIX_FUNCTIONS
constexpr int ARRAYSIZE = 300;
constexpr double TOL = 1.e-6;
void readMatrices(double K[ARRAYSIZE][ARRAYSIZE], double M[ARRAYSIZE][ARRAYSIZE]);
void buildDynamicMatrix(double K[ARRAYSIZE][ARRAYSIZE], double M[ARRAYSIZE][ARRAYSIZE], double D[ARRAYSIZE][ARRAYSIZE]);
void balance(double A[ARRAYSIZE][ARRAYSIZE]);
void arbQRUpdate(double A[ARRAYSIZE][ARRAYSIZE]);
void gaussianHessenberg(double A[ARRAYSIZE][ARRAYSIZE]);
void shiftHessQRUpdate(double H[ARRAYSIZE][ARRAYSIZE]);
void hessenbergQRUpdate(double H[ARRAYSIZE][ARRAYSIZE]);
void householderHessenberg(double A[ARRAYSIZE][ARRAYSIZE]);
#endif // MATRIX_FUNCTIONS 
