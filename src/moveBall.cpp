//
//  moveBall.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#include "moveBall.h"


void moveBall::setup(){
    xPos = 5;  // horizontal start position
    ofBackground(ofColor::black);  // black background
}

void moveBall::update(){
    xPos += 2;
    if(ofGetWidth()<xPos){  // if horizontal position is off the screen (width)
        xPos = 5;             // reset horizontal position
    }
}

void moveBall::draw(){
    ofSetColor(ofColor::red);  // draw everything in red
    ofDrawCircle(xPos, 100, 10);   // draw a circle at the (variable) horizontal position, 100 pixels from the top with a 10 pixel diameter
}
