#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
	ofSetFrameRate(120);
	ofSetWindowShape(1280, 720);
	ofSetWindowPosition(700, 100);

	vive.setup();

	sphere.set(0.1, 100);
	sphere.setPosition(0, 0, 0);
	sphere.enableColors();
	sphere.enableNormals();
	

	
}


//--------------------------------------------------------------
void ofApp::update(){
	time = ofGetElapsedTimef();
	sphere.setRadius(abs(sin(time*0.41231)) * 2);
	
}

void ofApp::exit() {
	vive.shutdown();
}

//--------------------------------------------------------------
void ofApp::draw() {

	vive.beginScene(vr::Eye_Left);
	drawScene();
	vive.endScene(vr::Eye_Left);

	vive.beginScene(vr::Eye_Right);
	drawScene();
	vive.endScene(vr::Eye_Right);

	vive.renderDistortion();
	vive.renderFrame();


}

void ofApp::drawScene() {
	sphere.drawWireframe();
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
