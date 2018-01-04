#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(2000,2000);
    ofBackground(0);
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){
    if(myBalls.size() >= 1) {
        if(myBalls[0].readyToDie() == true) {
            myBalls.erase(myBalls.begin());
        }
    }
    for(auto &ball: myBalls) {
        ball.update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto &ball: myBalls) {
        ball.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's') {
        ofSaveScreen("swirlycircles" + ofGetTimestampString() + ".png");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Ball newBall;
    newBall.setup(x, ofGetHeight() - 200, 20.0f);
    myBalls.push_back(newBall);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Ball newBall;
    newBall.setup(x, ofGetHeight() - 200, 20.0f);
    myBalls.push_back(newBall);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
