#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(24.0);
    ofSetVerticalSync(true);
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    mySequence.loadSequence("sequence",24.0f); // 24 FPS
    
    mySequence.play();
}

//--------------------------------------------------------------
void testApp::update(){
    mySequence.update();
    
    if(mySequence.isPlaying() && mySequence.isComplete()) {
        mySequence.stop();
        ofLog(OF_LOG_VERBOSE,"The sequence is complete.");
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    mySequence.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}