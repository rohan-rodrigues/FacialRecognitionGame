//
//  testApp.hpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/9/19.
//

#pragma once

#include "ofMain.h"
#include <ofVideoGrabber.h>
#include <ofTrueTypeFont.h>
#include "ofxCvHaarFinder.h"
#include "ofxCvHaarFinder.h"
#include "JCHaarFinder.h"
#include "ofxXmlSettings.h"

class faceApp : public ofBaseApp{
private:
    ofVideoGrabber videoGrabber;
    ofTrueTypeFont uiFont;
    ofTrueTypeFont uiHeadingFont;
    ofxUICanvas *gui;
    ofxUILabel *fpsLabel;
    ofImage haarInput;
    JCHaarFinder * haarFinder;
    
    bool showOverlays = true;
    
    int camWidth;
    int camHeight;
    float brightness;
    float contrast;
    bool frameNew;
    ofImage * probeImage;
    bool useWebcam;
    float scale;
    int curImage;
    int imageCount;
    ofImage * images;
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void doHaarStuff();
    
    inline float constrain(float amount, float min, float max);
};
