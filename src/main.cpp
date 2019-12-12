#include "ofMain.h"
#include "ofApp.h"
#include "brightestPointInVideo.h"
#include "brightestPointInImage.h"
#include "moveBall.h"
#include "mouseTracker.h"
#include "ballGame.h"
#include "faceFinder.h"
#include "ballGameWithFacialRecognition.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ballGameWithFacialRecognition());

}
