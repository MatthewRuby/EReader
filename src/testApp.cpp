#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofBackground(255, 255, 255);

	
	
	dict.open(ofToDataPath("phones.txt").c_str());
	while(dict!=NULL){
		string term; //declare a string for storage
		getline(dict, term, '\n');
		
		int pos = term.find(" ");
		string word = term.substr(0,pos);
		string sound = term.substr(pos);
		int length = sound.length();
		
		dl t;
		t.dt = word;
		t.dd = sound;
		t.len = length;
		
		terms.push_back(t);
		cout << word << " = " << sound << " -> " << length << endl;
	}
	
	
	
	fin.open(ofToDataPath("vonnegut.txt").c_str()); //open your text file

	
	
	
	
	
	word = 0;
	wordSpeed = 60;
	controlSpeed = 50;

	size_t findNL;
	
//	data.push_back("");
	while(fin!=NULL){ //as long as theres still text to be read
		
		string str; //declare a string for storage
		getline(fin, str, ' '); // get a WORD from the file, put it in the string
		
		findNL = str.find('\n');
		
		if (findNL != string::npos) {
			
			string str1 = "";
			string str2 = "";
			
			for (int i = 0; i < str.size(); i++) {

				if (i<findNL) {
					str1 += str[i];
					
				}
				
				if (i>findNL) {
					str2 += str[i];
					
				}

			}
			
			data.push_back(str1);
			data.push_back(" ");
			data.push_back(str2);
			
		} else {
			
			data.push_back(str); //push the string onto a vector of strings
		
		}
	}
	
	size_t findPageNum;
	
	for (int i = 0; i < data.size(); i++) {
		 if (isdigit(data[i][0]) != 0) {
			 if (data[i+1] == "of") {
				 if (isdigit(data[i+2][0]) != 0) {
					 if (data[i+7] == "Cities") {
						 data.erase(data.begin()+i, data.begin()+i + 8);
					 }
				 }
			 }
		 }
	}

//	for (int i = 0; i < data.size(); i++) {
//		cout << i << " " << data[i] << endl;
//	}

	times.loadFont("times.ttf", 120);

}

//--------------------------------------------------------------
void testApp::update(){
	
//	cout << word << " = " << data[word].size() << endl;
	
	if (ofGetFrameNum() > 120) {
		
		if (data[word] == " ") {
			wordSpeed = 60;
		} else {
			wordSpeed = data[word].size() + controlSpeed;
		}
		
		if (ofGetFrameNum() % wordSpeed == 0) {
//			cout << word << " = word #  speed = " << wordSpeed << endl;
			word++;
		}
		
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	ofSetColor(0, 0, 0);
	
	ofRectangle rect = times.getStringBoundingBox(data[word], 0,0);

	times.drawString(data[word], (ofGetWidth()/2) - (rect.width/2), (ofGetHeight()/2)+60);
	ofDrawBitmapString(ofToString(word), 10, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if (key == OF_KEY_UP) {
		controlSpeed -= 1;
		if (controlSpeed < 1) {
			controlSpeed = 1;
		}
	}
	if (key == OF_KEY_DOWN) {
		controlSpeed += 1;
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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

