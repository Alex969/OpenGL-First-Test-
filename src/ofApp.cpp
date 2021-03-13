#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Load the GLSL vertex and fragment shaders from bin/data
	colorCircleShader.load("colorCircle");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Get the size of the display window
 	float windowWidth = ofGetWidth();
	float windowHeight = ofGetHeight();

	// Get the mouse position as a vec2 to pass to the shader
	vec2 mousePos = vec2(mouseX, mouseY);

	// Calculate size of the circle that will just touch the sides of the display window
	float circleRadius = mousePos.x;

	if (mousePos.y < circleRadius) {
		circleRadius = mousePos.y;
	}

	if (windowWidth - mousePos.x < circleRadius) {
		circleRadius = windowWidth - mousePos.x;
	}

	if (windowHeight - mousePos.y < circleRadius) {
		circleRadius = windowHeight - mousePos.y;
	}

	// Start the colorCircleShader
	colorCircleShader.begin();

	// Pass the parameters needed by the shader as uniforms
	colorCircleShader.setUniform1f("windowWidth", windowWidth);
	colorCircleShader.setUniform1f("windowHeight", windowHeight);
	colorCircleShader.setUniform2f("mousePos", mousePos);
	colorCircleShader.setUniform1f("circleRadius", circleRadius);

	// Draw a rectangle that fills the display window
	ofDrawRectangle(0, 0, windowWidth, windowHeight);

	// Stop the colorCircleShader
	colorCircleShader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}