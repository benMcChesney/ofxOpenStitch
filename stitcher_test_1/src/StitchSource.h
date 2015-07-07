#pragma once
#include "ofMain.h"

class StitchSource
{
public:
	StitchSource() { } 

	ofVideoGrabber cam ;

	void setup(int deviceId, int width, int height); 
	void update(); 
	void draw( ); 

	ofRectangle area; 
	

private:
};