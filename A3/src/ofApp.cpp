#include "Main.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//Physics - new map
	bgImage.load("images/map.png");

	enemy.x = 310;
	enemy.y = 250;
	//enemy.img.load("images/l0.gif");
	enemy.GetImage()->load("images/l0.gif");

	//Physics - set the character at the right Y for the new map
	player.x = 10;
	player.y = 660 - 152; // ground level minus character height 
	player.GetImage()->load("images/r0.gif");
	player.SetNumFrames(3);
	player.frames[0].load("images/r0.gif");
	player.frames[1].load("images/r1.gif");
	player.frames[2].load("images/r2.gif");

	for (int i = 0; i < 255; i++)
		keyDown[i] = false;

	ofSetFrameRate(40);
}

//--------------------------------------------------------------
void ofApp::update(){

	//player movement
	int targetX = player.x;
	if (keyDown[OF_KEY_RIGHT] == true)
	{
		//player.x++;
		targetX+=2;
		player.Advance();
	}
	if (keyDown[OF_KEY_LEFT] == true)
	{
		//player.x--;
		targetX-=2;
		player.Advance();
	}
	//////////////////////////////////////////////////////////////
	//Physics - gravity-based jump and fall for physics
	if (keyDown[' '] == true && player.jump == false)
	{
		player.jump = true;
		player.t = 0;
		player.y0 = player.y;
	}
	physics.Move(&player, targetX);

	///////////////////////////////////////////////////////////
}

//--------------------------------------------------------------
void ofApp::draw(){
	bgImage.draw(0, 0);

	//draw player
	//method 1
	//player.img.draw(player.x, player.y);

	//method 2
	//player.Draw();
	//enemy.Draw();

	//method 3
	//render.Draw(&enemy);
	render.Draw(&player);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	keyDown[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	keyDown[key] = false;
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
