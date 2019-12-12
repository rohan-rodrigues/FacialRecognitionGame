#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
//    void setup();
//    void draw();
//
//    ofImage myImage;
    
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber myVideoGrabber;
    ofTexture myTexture;
    
    unsigned char* invertedVideoData;
    int camWidth;
    int camHeight;
};
