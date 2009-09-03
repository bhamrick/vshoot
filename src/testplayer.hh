#ifndef TESTPLAYER_H
#define TESTPLAYER_H

#include<player.hh>

class testPlayer : public player {
	public:
	int t, dx, worldWidth, worldHeight;
	testPlayer(int,int);
	void update(int);
	void keyboardHandler(int);
	void keyboardUpHandler(int);
	void specialHandler(int);
	void specialUpHandler(int);
};

#endif
