#ifndef PLAYER_H
#define PLAYER_H

#include<image.hh>
#include<GL/glut.h>

class player {
	private:
	protected:
	public:
		int r, x, y;
		int w, h;
		GLuint tex;
		int getX();
		int getY();
		virtual void update(int)=0;
		virtual void keyboardHandler(int)=0;
		virtual void keyboardUpHandler(int)=0;
		virtual void specialHandler(int)=0;
		virtual void specialUpHandler(int)=0;
};

#endif
