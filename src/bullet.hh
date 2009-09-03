#ifndef BULLET_H
#define BULLET_H

#include<cstdio>
#include<cstdlib>
#include<image.hh>

class bullet {
	private:
	protected:
	public:
		int w, h, t;
		GLuint tex;
		virtual int getX(int) = 0;
		virtual int getY(int) = 0;
};

#endif
