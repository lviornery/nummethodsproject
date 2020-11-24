#ifndef MATRIX_FUNCTIONS
#define MATRIX_FUNCTIONS
constexpr int ARRAYSIZE = 4;
void readMatrices(double K[ARRAYSIZE][ARRAYSIZE], double M[ARRAYSIZE][ARRAYSIZE]);
void buildDynamicMatrix(double K[ARRAYSIZE][ARRAYSIZE], double M[ARRAYSIZE][ARRAYSIZE], double D[ARRAYSIZE][ARRAYSIZE]);
void gaussianHessenberg(double A[ARRAYSIZE][ARRAYSIZE]);
void householderHessenberg(double A[ARRAYSIZE][ARRAYSIZE]);
void hessenbergQRUpdate(double A[ARRAYSIZE][ARRAYSIZE]);
#endif // MATRIX_FUNCTIONS 
