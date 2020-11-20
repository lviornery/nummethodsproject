project: buildDynamicMatrix.o hessenbergQRUpdate.o gaussianHessenberg.o balance.o main.o
	g++ -std=c++17 -o project buildDynamicMatrix.o hessenbergQRUpdate.o gaussianHessenberg.o main.o

buildDynamicMatrix.o:
	g++ -std=c++17 -c buildDynamicMatrix.cpp
	
hessenbergQRUpdate.o:
	g++ -std=c++17 -c hessenbergQRUpdate.cpp
	
balance.o:
	g++ -std=c++17 -c balance.cpp
	
gaussianHessenberg.o:
	g++ -std=c++17 -c gaussianHessenberg.cpp
	
main.o:
	g++ -std=c++17 -c main.cpp

clean:
	rm -f *.o
	rm -f project
	rm -f output.txt