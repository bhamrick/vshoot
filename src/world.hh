#ifndef WORLD_H
#define WORLD_H

#include<ctime>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<image.hh>
#include<player.hh>
#include<bullet.hh>
#include<GL/glut.h>
#include<sys/time.h>
#include<testbullet.hh>

class world {
	private:
		int w, h, t, rate, lastspawn;
		timeval starttime;
		bool started;
		std::vector<bullet*> bullets;
		std::vector<player*> players;
	protected:
	public:
		world(int, int, int, char*);
		void addBullet(bullet*);
		void addPlayer(player*);
		int getTime();
		void start();
		void update();
		void draw();
		void keyboardHandler(unsigned char);
		void keyboardUpHandler(unsigned char);
		void specialHandler(int);
		void specialUpHandler(int);
};

#endif
