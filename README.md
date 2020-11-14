# nummethodsproject
buildDynamicMatrix takes M and K matrices and returns M^-1 K

gaussianHessenberg uses a Gaussian process to reduce a matrix to a Hessenberg matrix

householderHessenberg uses a Householder process to reduce a matrix to a Hessenberg matrix (To-Do)

arbQRUpdate uses a QR decomposition on a given arbitrary matrix A and then updates the matrix as A_k+1 = QA_kQ^T (To-Do)

hessenbergQRUpdate uses a QR decomposition on a given Hessenberg matrix H and then updates the matrix as H_k+1 = QH_kQ^T

shiftHess introduces a spectral shift in a given Hessenberg matrix and then runs hessenbergQRUpdate on the new matrix (To-Do)

matrixFunctions is header file for these functions and also holds the global constant that controls the array size - note that all matrices are assumed to be square

main builds M and K, calls a function to build D = M^-1K, and then iteratively executes the QR algorithm on the matrix D to determine the natural frequencies.

to build, run 'make', then run by running './project'