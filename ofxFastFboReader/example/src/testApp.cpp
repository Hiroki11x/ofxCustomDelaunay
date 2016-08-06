#include "testApp.h"

#include "ofxTimeMeasurements.h"
#include "ofxFastFboReader.h"

ofFbo fbo;

int mode = 0;

ofxFastFboReader reader;

ofImage image;
ofPixels pix;

//--------------------------------------------------------------
void testApp::setup()
{
//	ofSetFrameRate(60);
//	ofSetVerticalSync(true);
	
	ofBackground(0);
	
	fbo.allocate(1920, 1080, GL_RGB);
}

//--------------------------------------------------------------
void testApp::update()
{
	int c = ofRandom(255);
	
	fbo.begin();
	ofClear(c, c, c);
	fbo.end();
	
	TIME_SAMPLE_START("PBO");	
	if (mode == 0)
	{
		reader.readToPixels(fbo, pix);
	}
	TIME_SAMPLE_STOP("PBO");
	
	TIME_SAMPLE_START("readToPixels");
	if (mode == 1)
	{
		fbo.readToPixels(pix);
	}
	TIME_SAMPLE_STOP("readToPixels");
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofDrawBitmapString("press space to change method", 10, 18);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	if (key == ' ')
	{
		mode++;
		mode = mode % 2;
	}
	else if (key == '1')
	{
		reader.setAsync(true);
	}
	else if (key == '2')
	{
		reader.setAsync(false);
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}