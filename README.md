# nummethodsproject
buildDynamicMatrix takes M and K matrices and returns M^-1 K

buildQR takes a matrix A and returns Q and R such that QR = A

Balance takes a matrix A and outputs a balanced form of matrix A with reduced sensitivity of eigenvalues to rounding errors

matrixFunctions is header file for these functions and also holds the global constant that controls the array size - note that all matrices are assumed to be square

main builds M and K, calls a function to build D = M^-1K, and then iteratively executes the QR algorithm on the matrix D to determine the natural frequencies.

to build, run 'make', then run by running './project'
