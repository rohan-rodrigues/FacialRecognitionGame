//
//  findingBrightness.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/10/19.
//

#include "brightestPointInImage.h"

//---------------------
void brightestPointInImage::setup(){
    laserTagImage.loadImage("/Users/rohanrodrigues/Pictures/image3.jpg");
}

//---------------------
void brightestPointInImage::draw(){
    ofBackground(255);
    
    int w = laserTagImage.getWidth();
    int h = laserTagImage.getHeight();
    
    float maxBrightness = 0; // these are used in the search
    int maxBrightnessX = 0; // for the brightest location
    int maxBrightnessY = 0;
    
    // Search through every pixel. If it is brighter than any
    // we've seen before, store its brightness and coordinates.
    // After testing every pixel, we'll know which is brightest!
    for(int y=0; y<h; y++) {
        for(int x=0; x<w; x++) {
            ofColor colorAtXY = laserTagImage.getColor(x, y);
            float brightnessOfColorAtXY = colorAtXY.getBrightness();
            if(brightnessOfColorAtXY > maxBrightness){
                maxBrightness = brightnessOfColorAtXY;
                maxBrightnessX = x;
                maxBrightnessY = y;
            }
        }
    }
    
    // Draw the image.
    ofSetColor (255);
    laserTagImage.draw(0,0);
    
    // Draw a circle at the brightest location.
    ofNoFill();
    ofDrawEllipse (maxBrightnessX, maxBrightnessY, 40,40);
}
