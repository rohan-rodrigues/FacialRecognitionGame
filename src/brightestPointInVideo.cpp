//
//  findingBrightness.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/10/19.
//

#include "brightestPointInVideo.h"

using namespace std;

//---------------------
void brightestPointInVideo::setup(){
    camWidth = 640;
    camHeight = 480;
    
    myVideoGrabber.initGrabber (camWidth,camHeight);
    
    myTexture.allocate (camWidth,camHeight, GL_RGB);
}



void brightestPointInVideo::update(){
    myVideoGrabber.update();
    
    if(myVideoGrabber.isFrameNew()){
        unsigned char* pixelData = myVideoGrabber.getPixels().getData();
        int nTotalBytes = camWidth * camHeight * 3;
        
        int max_brightness = 0;
        
        for(int i=0; i<nTotalBytes; i++){
            if (pixelData[i] > max_brightness) {
                max_brightness = pixelData[i];
                maxBrightnessX = nTotalBytes % camWidth;
                maxBrightnessY = nTotalBytes / camWidth;
            }
        }
        
        cout << "max brightness " << max_brightness;
      //  cout << "max X: " << maxBrightnessX << ", max Y: " << maxBrightnessY;
        
        // Now stash the inverted data in an ofTexture
       // myTexture.loadData (invertedVideoData, camWidth,camHeight, GL_RGB);
    }
}


void brightestPointInVideo::draw(){
    ofBackground(100,100,100);
    //ofSetColor(255,255,255);
    
    // Draw the grabber, and next to it, the "negative" ofTexture.
    myVideoGrabber.draw(10,10);
    
    // Draw a circle at the brightest location.
    ofNoFill();
    ofDrawEllipse (maxBrightnessX, maxBrightnessY, 20,20);
}


