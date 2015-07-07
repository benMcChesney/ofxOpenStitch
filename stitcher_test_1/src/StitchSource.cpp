#include "StitchSource.h"

void StitchSource::setup(int deviceId, int width, int height)
{
	cam.setDeviceID(deviceId); 
	cam.initGrabber(width, height); 

	area.width = width; 
	area.height = height; 

}

void StitchSource::update()
{
	cam.update(); 
	if ( cam.isFrameNew() )
	{

	}

}

void StitchSource::draw( )
{
	ofPushMatrix();
	cam.draw( area.x, area.y, area.width , area.height );
	ofPopMatrix(); 
}