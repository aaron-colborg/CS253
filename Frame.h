#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include <Point3D.h>
using std::vector;

class Frame{
 public:
	Frame(vector<Point3D>& passedVector);
	~Frame();
	void spineFix(double xAv,double yAv,double zAv);
	Point3D& operator [] (int index)
  	{
    	return poseVector[index];
  	}
	double maxFrame();
	void reScale(double scale);
	inline int vectorSize()	{return poseVector.size();}
	inline void pushVector(vector<Point3D>& myVector)	{poseVector = myVector;}
	inline vector<Point3D>& retVector()	{return poseVector;}

 protected:
	vector<Point3D> poseVector;
};

#endif //FRAME_H


