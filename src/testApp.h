#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <fstream>

class testApp : public ofBaseApp{

	struct dl {
		string dt;
		string dd;
		int len;
	};
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	
//		ofSerial	serial;
		ofTrueTypeFont 	times;
	
		ifstream dict;
		vector <dl> terms;
	
		ifstream fin; //declare a file stream
		vector <string> data; //declare a vector of strings to store data
		vector <int> time;
	
		int word;
		int wordSpeed;
		int controlSpeed;

};

#endif
