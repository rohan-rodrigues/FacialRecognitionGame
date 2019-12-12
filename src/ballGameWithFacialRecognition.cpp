//
//  ballGameWithFacialRecognition.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#include "ballGameWithFacialRecognition.h"
#include "ofxOpenCv.h"
#include <string>
using namespace std;

void ballGameWithFacialRecognition::setup() {
    ofSetWindowShape(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    vector<int> firstBall {5, 100};
    ballPositions.push_back(firstBall);
    counter = 0;
    score = 0;
    playerAlive = true;
    
    finder.setup("haarcascade_frontalface_default.xml");
    webcam.setup(SCREEN_SIZE_X, SCREEN_SIZE_Y);
}

void ballGameWithFacialRecognition::update() {
    webcam.update();
    
    finder.findHaarObjects(webcam.getPixels(),5,5);
    
    faceX = -1;
    faceY = -1;
    int biggestBlobArea = 0;
    for(int i = 0; i < finder.blobs.size(); i++) {
        int blobArea = finder.blobs[i].area;
        if (blobArea > biggestBlobArea) {
            biggestBlobArea = blobArea;
            faceX = finder.blobs[i].boundingRect.x;
            faceY = finder.blobs[i].boundingRect.x;
            faceWidth = finder.blobs[i].boundingRect.width;
            faceHeight = finder.blobs[i].boundingRect.height;
        }
    }
    
    const int MAX_ERROR_X = faceWidth / 2;
    const int MAX_ERROR_Y = faceHeight / 2;
    
    for (int i = 0; i < ballPositions.size(); i++) {
        if (abs(faceX - ballPositions[i][0]) < MAX_ERROR_X &&
            abs(faceY - ballPositions[i][1]) < MAX_ERROR_Y) {
            ballPositions.erase(ballPositions.begin() + i);
            score++;
        }
        else {
            ballPositions[i][0] += 6;
            if(ofGetWidth() < ballPositions[i][0]){  // if horizontal position is off the screen
                // player loses
                playerAlive = false;
            }
        }
    }
    
    
    if (counter % (METHOD_CALLS_PER_SECOND) == 0) {
        int randY = rand() % SCREEN_SIZE_Y;
        
        vector<int> newBall {5, randY};
        ballPositions.push_back(newBall);
    }
    
    counter++;
}

void ballGameWithFacialRecognition::draw() {
    ofBackground(0);
    
    if (playerAlive) {
        webcam.draw(0,0);
        
        ofSetColor(ofColor::red);
        ofFill();
        for (int i = 0; i < ballPositions.size(); i++) {
            ofDrawCircle(ballPositions[i][0], ballPositions[i][1], 10);
        }
        
        ofNoFill();
        ofSetColor(ofColor::blue);
        ofRect(faceX, faceY, faceWidth, faceHeight);
        
        ofSetColor(ofColor::white);
        ofDrawBitmapString("Score:", 20, 20);
        ofDrawBitmapString(score, 80, 20);
    }
    else {
        ofSetColor(ofColor::white);
        ofDrawBitmapString("GAME OVER", SCREEN_SIZE_X / 2 - 20, SCREEN_SIZE_Y / 2);
        ofDrawBitmapString("Final Score:", 20, 20);
        ofDrawBitmapString(score, 130, 20);
    }
    
}
