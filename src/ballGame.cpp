//
//  ballGame.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#include "ballGame.h"
#include <string>
using namespace std;

void ballGame::setup() {
    ofSetWindowShape(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    vector<int> firstBall {5, 100};
    ballPositions.push_back(firstBall);
    counter = 0;
    score = 0;
    playerAlive = true;
}

void ballGame::update() {
    mouseX = ofGetMouseX();
    mouseY = ofGetMouseY();
    
    const int MAX_ERROR_X = 10;
    const int MAX_ERROR_Y = 10;
    
    for (int i = 0; i < ballPositions.size(); i++) {
        if (abs(mouseX - ballPositions[i][0]) < MAX_ERROR_X &&
            abs(mouseY - ballPositions[i][1]) < MAX_ERROR_Y) {
            ballPositions.erase(ballPositions.begin() + i);
            score++;
        }
        else {
            ballPositions[i][0] += 2;
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

void ballGame::draw() {
    ofBackground(0);
    
    if (playerAlive) {
        ofSetColor(ofColor::red);
        ofFill();
        for (int i = 0; i < ballPositions.size(); i++) {
            ofDrawCircle(ballPositions[i][0], ballPositions[i][1], 10);
        }
        
        ofNoFill();
        ofSetColor(ofColor::blue);
        ofDrawEllipse (mouseX, mouseY, 30,30);
        
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

