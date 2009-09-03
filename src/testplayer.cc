#include<testplayer.hh>

testPlayer::testPlayer(int ww, int wh) {
	tex = loadImage("player");
	w = 20;
	h = 80;
	r = 5;
	worldWidth = ww;
	worldHeight = wh;
	x = ww/2;
	y = wh-h/2;
	t = 0;
	dx = 0;
}

void testPlayer::update(int nt) {
	x += dx * (nt - t);
	if(x < w/2) x = w/2;
	if(x > worldWidth-w/2) x = worldWidth-w/2;
	t = nt;
}

void testPlayer::keyboardHandler(unsigned char key) {
	
}

void testPlayer::keyboardUpHandler(unsigned char key) {
	
}

void testPlayer::specialHandler(int key) {
	if(key == GLUT_KEY_LEFT) {
		dx -= 5;
	} else if(key == GLUT_KEY_RIGHT) {
		dx += 5;
	}
}

void testPlayer::specialUpHandler(int key) {
	if(key == GLUT_KEY_LEFT) {
		dx += 5;
	} else if(key == GLUT_KEY_RIGHT) {
		dx -= 5;
	}
}
