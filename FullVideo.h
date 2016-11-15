#ifndef FULLVIDEO_H
#define FULLVIDEO_H

#include <vector>
#include <Frame.h>
using std::vector;

class FullVideo{
 public:
	FullVideo(vector<Frame>& passedVector, int& lineCount);
	FullVideo();
	~FullVideo();
	
	inline int size(){return frameVector.size();}
	inline int lineCount(){return videoLineCount;}
	inline Frame& get(int index){return frameVector[index];}
	inline vector<Frame>& retVector(){return frameVector;}
 protected:    
	vector<Frame> frameVector;
	int videoLineCount;
};

#endif //FRAME_H
	

