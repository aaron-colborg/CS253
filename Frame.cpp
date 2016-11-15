#include <vector>
#include <iostream> 
#include <Frame.h>
using std::vector;
using std::cout;

Frame::Frame(vector<Point3D>& passedVector){
	poseVector = passedVector;
}

Frame::~Frame(){
	poseVector.clear();
}

void Frame::spineFix(double xAv,double yAv,double zAv){
	for(unsigned int i = 0; i  < poseVector.size(); i++){
		poseVector[i].allignSpine(xAv,yAv,zAv);
	}
	//cout << "x" <<poseVector[0] << std::endl;
}

double Frame::maxFrame(){
	double max = poseVector[0].X();	
	//cout << "vecsize: " << poseVector[40]<< std::endl;
	for(unsigned int i = 0; i < poseVector.size(); i++){
		double temp = 0;
				temp = poseVector[i].X();
				//cout << "maxFrame tem: " << temp << std::endl;
				if(temp < 0){
					temp *= -1;
					if(temp > max){
						max = temp;
					}
				}
				else if(temp > max){
					max = temp;
				}
				//cout << "Max in Frame: " << max << std::endl;
				
				temp = poseVector[i].Y();
				if(temp < 0){
					temp *= -1;
					if(temp > max){
						max = temp;
					}
				}
				else if(temp > max){
					max = temp;
				}
				//cout << "Max in Frame: " << max << std::endl;

				temp = poseVector[i].Z();
				if(temp < 0){
					temp *= -1;
					if(temp > max){
						max = temp;
					}
				}
				else if(temp > max){
					max = temp;
				}
				//cout << "Max in Frame: " << max << std::endl;
	}
		//cout << "maxFrame max: " << max << std::endl;
	return max;	
}

void Frame::reScale(double scale){
	for(unsigned int i = 0; i < poseVector.size(); i++){
		poseVector[i].scalePoints(scale);
	}
}


