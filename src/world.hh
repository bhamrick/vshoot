#ifndef WORLD_H
#define WORLD_H

#include<ctime>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<image.hh>
#include<bullet.hh>
#include<GL/glut.h>
#include<sys/time.h>

class world {
	private:
		int w, h, t, rate;
		timeval starttime;
		bool started;
		std::vector<bullet*> bullets;
	protected:
	public:
		world(int, int, int, char*);
		void addBullet(bullet*);
		int getTime();
		void start();
		void update();
		void draw();
};

#endif
