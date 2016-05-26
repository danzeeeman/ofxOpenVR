#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofSetVerticalSync(true);
	ofSetFrameRate(120);
	ofSetWindowShape(1280, 720);
	ofSetWindowPosition(700, 100);

	vive.setup();

	sphere.set(0.25, 100);
	sphere.setPosition(0, 0, 0);
	sphere.enableColors();
	sphere.enableNormals();
	
	
}


//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::exit() {
	vive.shutdown();
}

//--------------------------------------------------------------
void ofApp::draw(){
	vive.beginScene(vr::Hmd_Eye::Eye_Left);
	ofSetColor(255, 0, 255);
	sphere.draw();
	vive.endScene(vr::Hmd_Eye::Eye_Left);

	vive.beginScene(vr::Hmd_Eye::Eye_Right);
	ofSetColor(255, 255, 0);
	sphere.draw();
	vive.endScene(vr::Hmd_Eye::Eye_Right);

	vive.renderDistortion();
	vive.renderFrame();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
