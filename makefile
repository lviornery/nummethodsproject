project: arbQRUpdate.o buildDynamicMatrix.o hessenbergQRUpdate.o gaussianHessenberg.o balance.o readMatrices.o shiftHessQRUpdate.o main.o
	g++ -std=c++17 -O3 -o project arbQRUpdate.o buildDynamicMatrix.o hessenbergQRUpdate.o gaussianHessenberg.o balance.o readMatrices.o shiftHessQRUpdate.o main.o

arbQRUpdate.o:
	g++ -std=c++17 -c -O3 arbQRUpdate.cpp
	
buildDynamicMatrix.o:
	g++ -std=c++17 -c -O3 buildDynamicMatrix.cpp
	
hessenbergQRUpdate.o:
	g++ -std=c++17 -c -O3 hessenbergQRUpdate.cpp
	
balance.o:
	g++ -std=c++17 -c -O3 balance.cpp
	
gaussianHessenberg.o:
	g++ -std=c++17 -c -O3 gaussianHessenberg.cpp
	
readmatrices.o:
	g++ -std=c++17 -c -O3 readmatrices.cpp
	
shiftHessQRUpdate.o:
	g++ -std=c++17 -c -O3 shiftHessQRUpdate.cpp
	
main.o:
	g++ -std=c++17 -c -O3 main.cpp

clean:
	rm -f *.o
	rm -f project
	rm -f output.txt