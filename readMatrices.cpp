#include "matrixFunctions.h"
#include <fstream>
#include <sstream>
#include <string>

void readMatrices(double M[ARRAYSIZE][ARRAYSIZE], double K[ARRAYSIZE][ARRAYSIZE])
{
	int i,j,k;
    std::stringstream line;
	std::string value;
    std::ifstream file("mmat.csv");
	i = 0;
	getline(file,value); // read the first csv line
	while (file.good()) { // while we haven't reached the end of the file
		line.str(value); //line is now the stringstream representation of the csv line
		j = 0; //reset j
		while (line.good()) { // while we haven't reached the end of the line
			getline(line,value,','); //split the line along commas
			M[i][j] = std::stod(value); //convert string to double and store in M
			j++;//increment j
		}
		line.clear(); //clear the flag that says we've reached the end of the line
		i++; //increment i
		getline(file,value); // read the next csv line
	}
	file.close();
	file.clear(); // clear flags
	file.open("kmat.csv");
	i = 0;
	getline(file,value); // read the first csv line
	while (file.good()) { // while we haven't reached the end of the file
		line.str(value); //line is now the stringstream representation of the csv line
		j = 0; //reset j
		while (line.good()) { // while we haven't reached the end of the line
			getline(line,value,','); //split the line along commas
			K[i][j] = std::stod(value); //convert string to double and store in M
			j++;//increment j
		}
		line.clear(); //clear the flag that says we've reached the end of the line
		i++; //increment i
		getline(file,value); // read the csv line
	}
}
