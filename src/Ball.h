//
//  Ball.h
//  oopBalls
//
//  Created by Sam Nosenzo on 12/29/17.
//

#ifndef _BALL // if this class hasn't been defined, the program can define it
#define _BALL // by using this if statement you prevent the class to be called more than once which would confuse the compiler
#include "ofMain.h" // we need to include this to have a reference to the openframeworks framework
#include <stdio.h>

class Ball {
    public: // place public functions or variables here
    
    void setup();
    void update();
    void draw();
    
    // variables
    ofVec2f loc;
    ofVec2f vel;
    float dim;
    float bright;
    float decayRate;
    ofColor color;
    float heading;
    float nx;
    void setup(float, float, float);
    void shrink();
    bool readyToDie();
    void checkBoundaries();
    Ball(); // constructor - used to initialize an object, if no properties are passed the program sets them to the defualt value;
    

    private: // place private functions or variables declerations here
}; // needs semicolon

#endif /* Ball */
