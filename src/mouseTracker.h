//
//  mouseTracker.hpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#pragma once

#include "ofMain.h"

class mouseTracker : public ofBaseApp{
public:
    
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofPolyline currentPolyline;
    ofVec2f lastPoint;
    vector <ofPolyline> polylines;
    bool leftMouseButtonPressed;
    float minDistance;
    
};
