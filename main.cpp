/*! \file main.cpp
    \brief Contains the Main.cpp class declaration
*/
#include <Point3D.h>
///#include <PoseDisplay.h>
#include <Frame.h>
#include <FullVideo.h>
#include <Table.h>
///#include <stdafx.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using std::max_element;
using std::sort;
using std::string;
using std::cout;
using std::istream;
using std::ifstream;
using std::ostream;
using std::ofstream;
using std::vector;
#include <ctime>
const double vectorMin(vector<double>& passed);
const double frameDistance(vector<Point3D>& frame, vector<Point3D>& frame2);
FullVideo normalizeFile(ifstream& myFile);
const vector<vector<double> > distanceCalc(string arg, FullVideo& video1, FullVideo& video2);
const double squaredDistance(vector<Point3D>& frame, vector<Point3D>& frame2);
const double medDistance(vector<Point3D>& frame, vector<Point3D>& frame2);
const double maxDistance(vector<Point3D>& frame, vector<Point3D>& frame2);
const int indexOfMin(double min, vector<double>& results);
//! Main/helper functions 
/*! 
  	Main.cpp is handeling all of the file reading, as well as passing off the results to classes such as Frame
	and Table, it also is holding many helper functions
 */
int main(int argc, char* argv[])
{		
	///FILE I/O///////////////////////////////////////////////////////////////////////////////////////////
	/// check for the correct number of arguments
	ifstream inFile;
	   
	string argString;

	if (argc < 2) {	
		std::cerr << "Too few arguments" << std::endl;
		return -1;
	}
	///FILE 1 I/O
	inFile.open(argv[1]);
	///check if inFile exists and is openable
	if (inFile.is_open()) {
	}
	else {
		std::cerr << "Cannot Open file.\n";
		return -1;
	}
	///normalize File1
	
	FullVideo video1 = normalizeFile(inFile);	
	///cout << video1.size() <<std::endl;
	if(video1.size() != 0){
	}
	else{
		return -1;
	}
	inFile.close();	
	
	//argString = argv[argc-1];
	vector<double> resultsVector;
	//int fileCount = 2;
//for(int i = 0; i < argc-2; i++){
	/*if(fileCount > (argc-2)){
		double min = vectorMin(resultsVector);
		int resIndex = indexOfMin(min,resultsVector);	
		cout << argv[resIndex+2] << std::endl;
		return 0;
	}*/
	
	//ifstream secondInFile;	
	//secondInFile.open(argv[fileCount]);
	///cout << fileCount <<std::endl;
	//fileCount++;

	///check if inFile exists and is openable
	/*if (secondInFile.is_open()) {
		///Testing purposes only
		///cout << "File is open.\n";
	}
	else {
		std::cerr << "Cannot Open file.\n";
		return -1;
	}*/

	///Finished File I/O, now parse line by line and store doubles into vector
	
	/*FullVideo video2 = normalizeFile(secondInFile);
	///cout << "2: " << video2.size() << " 1: " << video1.size() << std::endl;
	if(video2.size() > video1.size()){
		std::cerr << "target cannot be bigger that original" << std::endl;
		return -1;
	}
	else if(video2.size() != 0){
		
	}
	else{
		return -1;
	}*/
	///////NORMALIZED		
	

	//PA9 PA9 PA9 PA9PA9PA9 PA9PA9 PA9PA9PA9PA9PA9PA9 PA9 PA9 PA9 PA9 PA9 PA9 PA9 	
	//Create video2, by taking the elements 31-n of the first video and compare
	FullVideo video2;
	FullVideo video3;
	
	for(int n = 29; n < video1.size() / 2; n++){
		vector<Frame> vid2(video1.retVector().begin() , video1.retVector().begin() + (n+1) );
		int && size = vid2.size();
		cout << "vid2 size: " << size << std::endl;		
		video2 = FullVideo(vid2, size);
	
		vector<Frame> vid3(video1.retVector().begin() + (n+1) , video1.retVector().end());
		int && size2 = vid3.size();
		cout << "vid3 size: " << size2 << std::endl;
		video3 = FullVideo(vid3, size2);

	

	///Find the distance between Frames
	if(video1.size() < 1){
		std::cerr << "Need more than zero frame to compute distance 1" << std::endl;
		return -1;
	}
	else if(video2.size() < 1){
		std::cerr << "Need more than zero frame to compute distance 2" << std::endl;
		return -1;
	}
	else if(video3.size() < 1){
		std::cerr << "Need more than zero frame to compute distance 3" << std::endl;
		return -1;
	}

	///PA6 use function distance calc to to the required calc
	vector<vector<double> > tableVec;
	tableVec = distanceCalc("L2" , video2, video3);
	Table myTable(tableVec);
	
	double min;

	for(int i = 0; i < myTable.size()-1; i++){
		 min = myTable[i][0];
		for(unsigned int j = 0; j < myTable[i+1].size(); j++){
			for(unsigned int k = 0; k <= j; k++){
				///cout << "MIN: " <<  min << "    i: " << i <<  "    k: " << k<<  std::endl;
				if(myTable[i][k] < min){
					min = myTable[i][k];
				}
			}
			myTable.add(i+1,j,min);
		}
	}
	
	int hold = n;
	cout << "Total Frames (n+1) : " << hold + 1 << ". L2 distance: " << vectorMin(myTable[myTable.size()-1]) / (hold+1) << std::endl;
	
	resultsVector.push_back(vectorMin(myTable[myTable.size()-1]) / (hold+1));
	}
	//cout << vectorMin(resultsVector) << std::endl;
	double min = vectorMin(resultsVector);	
	int resIndex = indexOfMin(min,resultsVector);	
	cout << resIndex + 30 << std::endl;


	if (inFile.bad()) {
		/// IO error
		std::cerr << "IO error" << std::endl;
		return -1;
	}
	else if (!inFile.eof()) {
		/// format error (not possible with getline but possible with operator>>)
		std::cerr << "Format error" << std::endl;
		return -1;
	}
	else if(inFile.eof()) {
		///end of file
		///std::cerr << "End of file, " << getLineCount << " lines read.\n"<< std::endl;
	}
	
	
	

	return 0;
}
///END OF MAIN
/////////////
//////////////////////////////
///////////////////////////
//////////////////////////////
const int indexOfMin(double min, vector<double>& results){ 
	int index = 0;
	for(unsigned int i = 0; i < results.size(); i ++){
		if(results[i] == min){
			index = i;
		}
	}
	return index;
} //!< Return the index of the minimum value in a vector of doubles


const vector<vector<double> > distanceCalc(string arg, FullVideo& video1, FullVideo& video2){
	vector<vector<double> > tabVec;
	
	if(arg == "avg"){
		///determine which file is longer, then compare and output	
		if(video1.size() < video2.size() || video1.size() == video2.size()){
			for(int i = 0; i  < video1.size(); i++){
			vector<Point3D> frame = (video1.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video2.size(); j++){
					vector<Point3D> frame2 = (video2.get(j)).retVector();
					double retDouble = frameDistance(frame, frame2);
					doubVec.push_back(retDouble/25);
				}
				tabVec.push_back(doubVec);
			}
		}
		else if(video1.size() > video2.size()){				
			for(int i = 0; i  < video2.size(); i++){
			vector<Point3D> frame = (video2.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video1.size(); j++){
					vector<Point3D> frame2 = (video1.get(j)).retVector();
					double retDouble = frameDistance(frame, frame2);
					doubVec.push_back(retDouble/25);
				}
			tabVec.push_back(doubVec);
			}
		}		
		return tabVec;
	}
	
	else if(arg == "med"){
			///determine which file is longer, then compare and output	
		if(video1.size() < video2.size() || video1.size() == video2.size()){
			for(int i = 0; i  < video1.size(); i++){
			vector<Point3D> frame = (video1.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video2.size(); j++){
					vector<Point3D> frame2 = (video2.get(j)).retVector();
					double retDouble = medDistance(frame, frame2);
					doubVec.push_back(retDouble);
				}
				tabVec.push_back(doubVec);
			}
		}
		else if(video1.size() > video2.size()){						
			double count;
		for(int i = 0; i  < video2.size(); i++){
			vector<Point3D> frame = (video2.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video1.size(); j++){
					vector<Point3D> frame2 = (video1.get(j)).retVector();
					double retDouble = medDistance(frame, frame2);
					doubVec.push_back(retDouble);
					count += retDouble;
				}
			tabVec.push_back(doubVec);
			}
		}	
		
		return tabVec;
	}

	else if(arg == "Linf"){
		///determine which file is longer, then compare and output	
		if(video1.size() < video2.size() || video1.size() == video2.size()){
			for(int i = 0; i  < video1.size(); i++){
			vector<Point3D> frame = (video1.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video2.size(); j++){
					vector<Point3D> frame2 = (video2.get(j)).retVector();
					double retDouble = maxDistance(frame, frame2);
					doubVec.push_back(retDouble);
				}
				tabVec.push_back(doubVec);
			}
		}
		else if(video1.size() > video2.size()){						
			double count;
		for(int i = 0; i  < video2.size(); i++){
			vector<Point3D> frame = (video2.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video1.size(); j++){
					vector<Point3D> frame2 = (video1.get(j)).retVector();
					double retDouble = maxDistance(frame, frame2);
					doubVec.push_back(retDouble);
					count += retDouble;
				}
			tabVec.push_back(doubVec);
			}
		}	
		
		return tabVec;
	}

	else if(arg == "L2"){
		///determine which file is longer, then compare and output	
		if(video1.size() < video2.size() || video1.size() == video2.size()){
			for(int i = 0; i  < video1.size(); i++){
			vector<Point3D> frame = (video1.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video2.size(); j++){
					vector<Point3D> frame2 = (video2.get(j)).retVector();
					double retDouble = squaredDistance(frame, frame2);
					doubVec.push_back(sqrt(retDouble));
				}
				tabVec.push_back(doubVec);
			}
		}
		else if(video1.size() > video2.size()){				
			for(int i = 0; i  < video2.size(); i++){
			vector<Point3D> frame = (video2.get(i)).retVector();
			vector<double> doubVec;
				for(int j = 0; j  < video1.size(); j++){
					vector<Point3D> frame2 = (video1.get(j)).retVector();
					double retDouble = squaredDistance(frame, frame2);
					doubVec.push_back(sqrt(retDouble));
				}
			tabVec.push_back(doubVec);
			}
		}		
		return tabVec;
	}

	else{
		return tabVec;
	}
} //!< Return a tableVector storing the calculated distances from the dynamic time warping



////////////////////////////////////////////////////////////
const double frameDistance(vector<Point3D>& frame, vector<Point3D>& frame2){
	double dist = 0;
	for(unsigned int i = 0; i  < frame.size(); i++){			
		double deltaX = (frame[i].X() - frame2[i].X());
		double deltaY = (frame[i].Y() - frame2[i].Y());
		double deltaZ = (frame[i].Z() - frame2[i].Z());	
		dist += sqrt((deltaX * deltaX) + (deltaY * deltaY) + (deltaZ * deltaZ));
	}
	///cout <<dist<<std::endl;
	return dist;
} //!< Return the distance between 2 frames (standard)

const double squaredDistance(vector<Point3D>& frame, vector<Point3D>& frame2){
	double dist = 0;
	for(unsigned int i = 0; i  < frame.size(); i++){			
		double deltaX = (frame[i].X() - frame2[i].X());
		double deltaY = (frame[i].Y() - frame2[i].Y());
		double deltaZ = (frame[i].Z() - frame2[i].Z());	
		dist += (deltaX * deltaX) + (deltaY * deltaY) + (deltaZ * deltaZ);
	}
	return dist;
}//!< Return the distance between 2 frames (squared)

const double medDistance(vector<Point3D>& frame, vector<Point3D>& frame2){
	vector<double> distVec;
	for(unsigned int i = 0; i  < frame.size(); i++){	
		double dist = 0;		
		double deltaX = (frame[i].X() - frame2[i].X());
		double deltaY = (frame[i].Y() - frame2[i].Y());
		double deltaZ = (frame[i].Z() - frame2[i].Z());	
		dist = sqrt((deltaX * deltaX) + (deltaY * deltaY) + (deltaZ * deltaZ));
		///cout << dist << std::endl;
		distVec.push_back(dist);
	}
	sort(distVec.begin(), distVec.end());

	return distVec[12];
} //!< Return the distance between 2 frames (median)

const double maxDistance(vector<Point3D>& frame, vector<Point3D>& frame2){
	vector<double> distVec;
	unsigned int length = frame.size();
	for(unsigned int i = 0; i  < length; i++){	
		double dist = 0;		
		double deltaX = (frame[i].X() - frame2[i].X());
		double deltaY = (frame[i].Y() - frame2[i].Y());
		double deltaZ = (frame[i].Z() - frame2[i].Z());	
		dist = sqrt((deltaX * deltaX) + (deltaY * deltaY) + (deltaZ * deltaZ));
		///cout << dist << std::endl;
		distVec.push_back(dist);
	}
	sort(distVec.begin(), distVec.end());

	return distVec[24];
}//!< Return the distance between 2 frames (max)

////////////////////////////////////////////////////
const double vectorMin(vector<double>& passed){
	double min = passed[0];
	for(unsigned int i = 0; i < passed.size(); i++){
		if(passed[i] < min){
			min = passed[i];
		}
	}
	return min;
} //!< find the minimum value in a vector and doubles

FullVideo normalizeFile(ifstream& myFile){	
	//////////////////////////////////////////////		
	string line;
	double max = 0;
	vector<double> position(75);
	vector<Point3D> point3DVector(25);
	vector<Frame> fullVideo;		
	double xAvg = 0; 
	double yAvg = 0;
	double zAvg = 0;
	int getLineCount = 0;
	
	while (getline(myFile, line)) {
			double passToVector; //!< Create vector to store the 75 doubles
			int count = 0;       //!< Count to make sure there are exactly 75 doubles
			++getLineCount;		 //!< Increment counter to keep track of how many lines I read
			///cout << "count: " << getLineCount <<std::endl;
			std::istringstream lineString(line); //!< String stream to read the data from
			
			
			if(line == ""){
				if(getline(myFile, line).eof()){
					///cout<< "?" << std::endl;
				}
				else{
				std::cerr << "Found an empty line on  : " << getLineCount << std::endl;
				FullVideo myVideo;
				return myVideo;
				}
			} //!< Begin reading and storing the doubles
					
			while (lineString >> passToVector) {
				if (lineString.fail()) {
					lineString.clear();
					std::cerr << "Unsupported datatype detected.\n";
					FullVideo myVideo;
					return myVideo;
				}
				else {
					position.push_back(passToVector);
					++count;
				}
			}
			
			//cout << count
			if (count != 75 && !line.empty()) {
				///cout << count;
				std::cerr << "You must pass exactly 75 doubles, Data at point: " << count << ".  On line number: " 					<< getLineCount << " is unsupported or illegal\n" << std::endl;
				position.clear();
				FullVideo myVideo;
				return myVideo;
			}//!< Count should be 75 after reading each point from the line and storing it into the vector		
			
			///PA2 ALLIGN SPINE TO (0,0,0)			
			xAvg += position[0];
			yAvg += position[1];
			zAvg += position[2];


			///Pass the Vector to point3D then to PoseDisplay!!!
			///All test code for the time being/////////////////////////////////////////////////////////////
			for(int i = 0; i < 75; i++){
				Point3D test(position[i], position[i+1], position[i+2]);
				point3DVector.push_back(test);
				i = i + 2;
				///std::cerr << "ERROR in pushing to Point3D vector" << std::endl;	
			}
			///cout << point3DVector[0] << std::endl;
			Frame myFrame(point3DVector);
			fullVideo.push_back(myFrame);
			///clear both the point3d vector and the points vector for the next loop
			point3DVector.clear();
			position.clear();
	}
	
	///Spine allign
	xAvg = xAvg/getLineCount;
	yAvg = yAvg/getLineCount;
	zAvg = zAvg/getLineCount;
	///got Averages for the spine, now subtract all points by them
	for(unsigned int i = 0; i  < fullVideo.size(); i++){
		fullVideo[i].spineFix(xAvg,yAvg,zAvg);
	}
	///end spine allign
	///cout << "video1 size: " << fullVideo.size() << std::endl;
	for(unsigned int i = 0; i  < fullVideo.size(); i++){
		double temp = fullVideo[i].maxFrame();
		///cout << "i: " << i << std::endl;
		if(temp > max){
			max = temp;
			///cout << max << std::endl;
		}
	}
	///cout << max << std::endl;
	///cout<< "LINECOUNT: " << getLineCount << std::endl;
	if(getLineCount == 0){
		std::cerr << "Cannot have an empty file, must be at least 1 line!" << std::endl;
		FullVideo myVideo;
		return myVideo;
	}
	///test is max = 0. cant normalize
	if(max == 0){
		
		std::cerr << "Max cannot = 0. Impossible to normalize" << std::endl;
		FullVideo myVideo;
		return myVideo;
	}
	
	///Max calculated, now scale all other points.
	double scale;
	///cout << "Max: " << max << std::endl;	
	if(max < 1){
		scale = (1/max);
	}else{
		scale = (1/max);
	}
	for(unsigned int i = 0; i  < fullVideo.size(); i++){
		fullVideo[i].reScale(scale);
	}
	FullVideo myVideo = FullVideo(fullVideo, getLineCount);
	return myVideo;
}





