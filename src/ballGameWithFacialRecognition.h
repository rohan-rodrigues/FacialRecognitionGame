//
//  ballGameWithFacialRecognition.hpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ballGameWithFacialRecognition : public ofBaseApp{
public:
    const int SCREEN_SIZE_X = 640;
    const int SCREEN_SIZE_Y = 480;
    
    void setup();
    void update();
    void draw();
    
    bool playerAlive;
    
    vector < vector<int> > ballPositions;
    
    int faceX;
    int faceWidth;
    int faceY;
    int faceHeight;
    
    int counter;
    int score;
    const int METHOD_CALLS_PER_SECOND = 60;
    
    ofVideoGrabber webcam;
    
    ofxCvHaarFinder finder;
};


bool canDetectPersonFromImage(string filepath) {
    ofImage image;
    image.loadImage(filepath);
    ofxCvHaarFinder objectFinder;
    objectFinder.setup("haarcascade_frontalface_default.xml");
    objectFinder.findHaarObjects(image);
    if (objectFinder.blobs.size() > 0) {
        return true;
    }
    return false;
}
