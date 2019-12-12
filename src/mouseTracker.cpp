//
//  mouseTracker.cpp
//  testNew
//
//  Created by Rohan Rodrigues on 12/11/19.
//

#include "mouseTracker.h"

void mouseTracker::setup() {
    ofSetWindowShape(1024,768);
    leftMouseButtonPressed = false;
    minDistance = 10.0;
}

void mouseTracker::update() {
    if (leftMouseButtonPressed) {
        ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastPoint.distance(mousePos) >= minDistance) {
            // a.distance(b) calculates the Euclidean distance between point a and b.  It's
            // the straight line distance between the points.
            currentPolyline.curveTo(mousePos);
            lastPoint = mousePos;
        }
    }
}

void mouseTracker::draw() {
    ofBackground(0);
    ofSetColor(255);  // White color for saved polylines
    for (int i=0; i<polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        polyline.draw();
    }
    ofSetColor(255,100,0);  // Orange color for active polyline
    currentPolyline.draw();
}

void mouseTracker::mousePressed(int x, int y, int button) {
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }
}

void mouseTracker::mouseReleased(int x, int y, int button) {
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y);   // Necessary duplicate for last control point
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
    }
}
