#ifndef TESTBULLET_H
#define TESTBULLET_H

#include<cmath>
#include<cstdlib>
#include<image.hh>
#include<bullet.hh>
#include<GL/glut.h>

class testBullet : public bullet {
	public:
	int speed, x;
	testBullet(int, int);
	int getX(int);
	int getY(int);
};

#endif
