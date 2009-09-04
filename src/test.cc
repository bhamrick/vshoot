#include<testbullet.hh>
#include<testplayer.hh>
#include<GL/glut.h>
#include<world.hh>
#include<cstdlib>
#include<cstdio>

world *w;

void displayFunc(int value) {
	w->update();
	w->draw();
	glutTimerFunc(16,displayFunc,0);
}

void keyboardFunc(unsigned char key, int x, int y) {
	w->keyboardHandler(key);
}

void specialFunc(int key, int x, int y) {
	w->specialHandler(key);
}

void keyboardUpFunc(unsigned char key, int x, int y) {
	w->keyboardUpHandler(key);
}

void specialUpFunc(int key, int x, int y) {
	w->specialUpHandler(key);
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	srand(time(NULL));
	w = new world(300,600,80,"Test");
	w->addPlayer(new testPlayer(300,600));
	w->start();
	glutTimerFunc(16,displayFunc,0);
	glutKeyboardFunc(keyboardFunc);
	glutSpecialFunc(specialFunc);
	glutKeyboardUpFunc(keyboardUpFunc);
	glutSpecialUpFunc(specialUpFunc);
	glutMainLoop();
}
