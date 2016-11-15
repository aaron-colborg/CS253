// CS253_P1.cpp : Defines the entry point for the console application.
//
#include <Point3D.h>
#include <PoseDisplay.h>
//#include <stdafx.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
using std::string;
using std::cout;
using std::istream;
using std::ifstream;
using std::ostream;
using std::ofstream;
using std::vector;

int main(int argc, char* argv[])
{
	// check for the correct number of arguments
	ifstream inFile;
	ofstream outFile;
	if (argc == 3) {
		inFile.open(argv[1]);
		outFile.open(argv[2]);
	}
	else {
		std::cerr << "Usage: InputFile.txt OutputFile.txt" << std::endl;
		return -1;
	}

	//check if inFile exists and is openable
	if (inFile.is_open()) {
		//Testing purposes only
		//cout << "File is open.\n";
	}
	else {
		std::cerr << "Cannot Open file.\n";
		return -1;
	}

	//check if outFile exists and is openable
	if (outFile.is_open()) {
		//test wrriting to file... erase in final.
		//outFile << "Wrinting this to the file\n";
		//outFile.close();
	}
	else {
		std::cerr << "Cannot Open Output file.\n";
		return -1;
	}
	//Finished File I/O, now parse line by line and store doubles into vector
		string line;
		vector<double> position;
		int getLineCount = 0;
		vector<Point3D> point3DVector;
	    PoseDisplay a("output.txt", true); 
	
		while (getline(inFile, line)) {
			//create vector to store the 75 doubles
			double passToVector;
			//count to make sure there are exactly 75 doubles
			int count = 0;
			//increment counter to keep track of how many lines I read
			++getLineCount;
			//string stream to read the data from
			std::istringstream lineString(line);
			//begin reading and storing the doubles
			
			if(line == ""){
				if(getline(inFile, line).eof()){
				
				}
				else{
				std::cerr << "Found an empty line on  : " << getLineCount << std::endl;
				return -1;
				}
			}
					
			while (lineString >> passToVector) {
				if (lineString.fail()) {
					lineString.clear();
					std::cerr << "Unsupported datatype detected.\n";
					return -1;
				}
				else {
					position.push_back(passToVector);
					++count;
				}
			}
			//count should be 75 after reading each point from the line and storing it into the vector		
			//cout << count;
			if (count != 75 && !line.empty()) {
				//cout << count;
				std::cerr << "You must pass exactly 75 doubles, Data at point: " << count << ".  On line number: " << getLineCount << " is unsupported or illegal\n" << std::endl;
				position.clear();
				return -1;
			}
			
			//Pass the Vector to point3D then to PoseDisplay!!!
			//All test code for the time being/////////////////////////////////////////
			for(int i = 0; i < 75; i++){
				Point3D test(position[i], position[i+1], position[i+2]);
				point3DVector.push_back(test);
				i = i + 2;
				//std::cerr << "ERROR in pushing to Point3D vector" << std::endl;	
			}
			
			//Check that Pose will accpet my Point3D vector
			if(!a.Pose(point3DVector)){
				std::cerr << "Error in Point3D vector, connot pass to Pose"<< std::endl;
				return -1;
			}
			
			//clear both the point3d vector and the points vector for the next loop
			point3DVector.clear();
			position.clear();
		}	
		if (inFile.bad()) {
			// IO error
			std::cerr << "IO error" << std::endl;
			return -1;
		}
		else if (!inFile.eof()) {
			// format error (not possible with getline but possible with operator>>)
			std::cerr << "Format error" << std::endl;
			return -1;
		}
		else if(inFile.eof()) {
			//end of file
			//std::cerr << "End of file, " << getLineCount << " lines read.\n"<< std::endl;
		}
		


		
		//system("pause");
	inFile.close();
	outFile.close();

	return 0;
}

