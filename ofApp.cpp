#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	
	ofRotateY(ofGetFrameNum());
	ofRotateX(sin(ofGetFrameNum() * 0.05) * 8);

	int size = 30;

	for (int i = 0; i < 3; i++) {
		
		for (int x = size * -1; x <= size * 1; x += size) {

			for (int y = size * -1; y <= size * 1; y += size) {

				for (int z = size * -1; z <= size * 1; z += size) {

					auto noise_seed = ofRandom(1000);

					ofPushMatrix();
					ofTranslate(x, y, z);

					ofDrawSphere(2);

					int param = ofMap(ofNoise(noise_seed, ofGetFrameNum() * 0.0005), 0, 1, 0, 8);
					switch (param) {
					case 0:
					case 1:

						ofDrawLine(0, 0, 0, 0, 0, size * -1);
						ofDrawSphere(0, 0, size * -1, 2);
						break;
					case 2:

						ofDrawLine(0, 0, 0, 0, size * -1, 0);
						ofDrawSphere(0, size * -1, 0, 2);
						break;
					case 3:

						ofDrawLine(0, 0, 0, size * 1, 0, 0);
						ofDrawSphere(size * 1, 0, 0, 2);
						break;
					case 4:

						ofDrawLine(0, 0, 0, 0, size * 1, 0);
						ofDrawSphere(0, size * 1, 0, 2);
						break;
					case 5:

						ofDrawLine(0, 0, 0, -size * 1, 0, 0);
						ofDrawSphere(size * -1, 0, 0, 2);
						break;
					case 6:
					case 7:

						ofDrawLine(0, 0, 0, 0, 0, size * 1);
						ofDrawSphere(0, 0, size * 1, 2);
						break;
					}

					ofPopMatrix();
				}
			}
		}
	}

	this->cam.begin();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}