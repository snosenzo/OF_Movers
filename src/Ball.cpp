//
//  Ball.cpp
//  oopBalls
//
//  Created by Sam Nosenzo on 12/29/17.
//

#include "Ball.h"

Ball::Ball() {
    
}
void Ball::setup(float _x, float _y, float _dim) {
    loc = ofVec2f(_x, _y);
    vel = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
    bright = 255.0f;
    dim = _dim;
    nx = ofRandom(200000);
    heading = ofMap(ofNoise(nx), 0, 1, -TWO_PI*2, TWO_PI*2);
    decayRate = ofRandom(.98, .99);
    vel = ofVec2f(cosf(heading), sinf(heading));
//    color.set(ofRandom(255), ofRandom(255), ofRandom(255));

    color.set(bright);
    
}
void Ball::setup() {
    nx = ofRandom(200000);
    heading = ofMap(ofNoise(nx), 0, 1, 0, TWO_PI);
    loc = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
    vel = ofVec2f(cos(heading), sin(heading));
    
    dim = 20;
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::shrink() {
    if(dim > 0.1) {
        dim*=decayRate;
        bright*=decayRate;
    }
}

bool Ball::readyToDie() {
    if(dim <= .2f) {
        return true;
    }
    return false;
}

void Ball::update() {
    heading = ofMap(ofNoise(nx), 0, 1, 0, -PI);
    vel = ofVec2f(cosf(heading), sinf(heading));
//    checkBoundaries();
    loc = loc + vel;
    nx+=.01;
    shrink();
}

void Ball::checkBoundaries() {
    if(loc.x < 0) {
        loc.x = 0;
        vel.x *= -1;
    } else if( loc.x > ofGetWidth() ) {
        loc.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if( loc.y < 0 ) {
        loc.y = 0;
        vel.y *= -1;
    } else if (loc.y > ofGetHeight()) {
        loc.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Ball::draw() {
    color.set(255 - bright);
    ofSetColor(color);
    ofDrawCircle(loc.x, loc.y, dim);
}
