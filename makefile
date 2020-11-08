project: buildDynamicMatrix.o buildQR.o main.o
	g++ -std=c++17 -o project buildDynamicMatrix.o buildQR.o main.o

buildDynamicMatrix.o:
	g++ -std=c++17 -c buildDynamicMatrix.cpp
	
buildQR.o:
	g++ -std=c++17 -c buildQR.cpp
	
main.o:
	g++ -std=c++17 -c main.cpp

clean:
	rm -f *.o
	rm -f project
	rm -f output.txt