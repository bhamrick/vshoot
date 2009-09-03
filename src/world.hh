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

class world {
	private:
		int w, h, t, rate;
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
		void keyboardHandler(int);
		void keyboardUpHandler(int);
		void specialHandler(int);
		void specialUpHandler(int);
};

#endif
