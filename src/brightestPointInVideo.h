//
//  brightestPointInVideo.hpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/10/19.
//

#pragma once
#include "ofMain.h"

class brightestPointInVideo : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    ofVideoGrabber myVideoGrabber;
    ofTexture myTexture;
    
    int maxBrightnessX = 0;
    int maxBrightnessY = 0;
    
    //unsigned char* updatedVideoData;
    int camWidth;
    int camHeight;
};


