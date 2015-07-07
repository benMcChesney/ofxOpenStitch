#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	bool bOpenResult = cameraJson.open("camera_config.json"); 

	int numSources = cameraJson["camera_array"].size(); 
	for (int i = 0; i < numSources; i++)
	{
		//cout << " CAMERA DEVICE ID : " <<  << endl; 
		int id = cameraJson["camera_array"][i]["deviceId"].asInt(); 
		int w = cameraJson["camera_array"][i]["width"].asInt(); 
		int h = cameraJson["camera_array"][i]["height"].asInt(); 
		sources.push_back(new StitchSource()); 
		sources[i]->setup(id, w, h); 

		guis.push_back(new ofxUISuperCanvas("GUI #" + ofToString(i)));

		guis[i]->addLabel("GUI #" + ofToString(i)); 
		guis[i]->addSpacer();
		
		guis[i]->addSlider("X", 0, 1920, &sources[i]->area.x); 
		guis[i]->addSlider("Y", 0, 1080, &sources[i]->area.y);
		guis[i]->addSlider("WIDTH", 0, 1920, &sources[i]->area.width);
		guis[i]->addSlider("HEIGHT", 0, 1080, &sources[i]->area.height);
		guis[i]->setVisible(false); 
		guis[i]->autoSizeToFitWidgets(); 
		
	
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (auto s = sources.begin(); s != sources.end(); s++)
	{
		(*s)->update(); 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofEnableAlphaBlending(); 
	ofPushStyle(); 

	if (bDrawOnionSkin == true)
		ofSetColor(255, 128);
	else
		ofSetColor(255);

	for (auto s = sources.begin(); s != sources.end(); s++)
	{
		(*s)->draw();
	}

	ofPopStyle(); 
}

void ofApp::hideAllGuis()
{
	for (int i = 0; i < guis.size(); i++)
	{
		guis[i]->setVisible(false); 
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch ( key )
	{
		case '1':
			hideAllGuis(); 
			if (guis.size() > 0)
				guis[0]->setVisible(true);
			break; 

		case '2':
			hideAllGuis();
			if (guis.size() > 1)
				guis[1]->setVisible(true);
			break;

		case 'o':
		case 'O':
			bDrawOnionSkin = !bDrawOnionSkin; 
			break; 
	
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
