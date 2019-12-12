//
//  faceFinder.hpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class faceFinder : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber webcam;
    ofImage img;
    
    ofxCvHaarFinder finder;
    
    
};
