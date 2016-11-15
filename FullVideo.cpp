#include <vector>
#include <Frame.h>
#include <FullVideo.h>
using std::vector;

FullVideo::FullVideo(){

}

FullVideo::FullVideo(vector<Frame>& passedVector, int& lineCount){
	frameVector = passedVector;
	videoLineCount = lineCount;
}

FullVideo::~FullVideo(){
	frameVector.clear();
}	

	

