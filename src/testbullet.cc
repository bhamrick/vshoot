#include<testbullet.hh>

testBullet::testBullet() {
	tex = loadImage("bullet");
	w = 32; h = 64; t = 0; r = 14;
}

int testBullet::getX(int wt) {
	return 150;
}

int testBullet::getY(int wt) {
	return 8*(wt-t);
}
