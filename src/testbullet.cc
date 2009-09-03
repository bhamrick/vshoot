#include<testbullet.hh>

testBullet::testBullet(int wt, int ww) {
	tex = loadImage("bullet");
	w = 32; h = 64; t = wt; r = 7;
	x = rand() % ww;
	speed = rand()%7+5;
}

int testBullet::getX(int wt) {
	return x;
}

int testBullet::getY(int wt) {
	return speed*(wt-t);
}
