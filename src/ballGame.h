//
//  ballGame.hpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#pragma once

#include "ofMain.h"

class ballGame : public ofBaseApp{
public:
    const int SCREEN_SIZE_X = 1024;
    const int SCREEN_SIZE_Y = 768;
    
    void setup();
    void update();
    void draw();
    
    bool playerAlive;
    
    vector < vector<int> > ballPositions;
    
    int mouseX;
    int mouseY;
    int counter;
    int score;
    const int METHOD_CALLS_PER_SECOND = 60;
};

