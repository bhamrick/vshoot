#ifndef TESTBULLET_H
#define TESTBULLET_H

#include<cmath>
#include<image.hh>
#include<bullet.hh>
#include<GL/glut.h>

class testBullet : public bullet {
	public:
	testBullet();
	int getX(int);
	int getY(int);
};

#endif
