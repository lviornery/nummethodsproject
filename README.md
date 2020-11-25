# nummethodsproject
arbQRUpdate uses a QR decomposition on a given arbitrary matrix A and then updates the matrix as A_k+1 = QA_kQ^T (once householderHessenberg syntax issues are fixed, it should work)

balance takes a matrix A and outputs a balanced form of matrix A with reduced sensitivity of eigenvalues to rounding errors 

buildDynamicMatrix takes M and K matrices and returns M^-1 K

gaussianHessenberg uses a Gaussian process to reduce a matrix to an upper Hessenberg matrix

genMatrices is a Matlab script that generates mmat and kmat, where mmat has only diagonal entries and kmat is a symmetric positive definite matrix

hessenbergQRUpdate uses a QR decomposition on a given upper Hessenberg matrix H and then updates the matrix as H_k+1 = QH_kQ^T

householderHessenberg uses a Householder process to reduce a matrix to a Hessenberg matrix (syntax issues)

main builds M and K, calls a function to build D = M^-1K, and then iteratively executes the QR algorithm on the matrix D to determine the natural frequencies.

matrixFunctions is header file for these functions and also holds the global constants that control the array size and tolerance - note that all matrices are assumed to be square

readMatrices reads mmat.csv and kmat.csv and imports the contents for this program

shiftHessQRUpdate introduces a spectral shift in a given Hessenberg matrix and then runs hessenbergQRUpdate on the new matrix

to build, run 'make', then run by running './project'
