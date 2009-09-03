#include<testbullet.hh>

testBullet::testBullet() {
	tex = loadImage("bullet");
	w = 16; h = 16; t = 0; r = 8;
}

int testBullet::getX(int wt) {
	return 150 + 30*sin((wt-t)/10.);
}

int testBullet::getY(int wt) {
	return 2*(wt-t);
}
