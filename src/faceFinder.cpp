//
//  faceFinder.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#include "faceFinder.h"
#include "ofxOpenCv.h"

void faceFinder::setup(){
    finder.setup("haarcascade_frontalface_default.xml");
   // finder.setPreset(ofxCv::ObjectFinder::Fast);
    webcam.setup(640, 480);
}

//--------------------------------------------------------------
void faceFinder::update(){
    webcam.update();
    finder.findHaarObjects(webcam.getPixels(),5,5);
//    if (webcam.isFrameNew()){
//        finder.update(webcam);
//    }
}

//--------------------------------------------------------------
void faceFinder::draw(){
    webcam.draw(0,0);
    ofNoFill();
    
    for(int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle cur = finder.blobs[i].boundingRect;
        ofRect(cur.x, cur.y, cur.width, cur.height);
    }
}
