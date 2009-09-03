#include<testbullet.hh>
#include<testplayer.hh>
#include<GL/glut.h>
#include<world.hh>
#include<cstdio>

world *w;

void displayFunc(int value) {
	w->update();
	w->draw();
	glutTimerFunc(16,displayFunc,0);
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	w = new world(300,600,80,(char*)"Test");
	glutTimerFunc(16,displayFunc,0);
	w->addBullet(new testBullet());
	w->addPlayer(new testPlayer(300,600));
	w->start();
	glutMainLoop();
}
