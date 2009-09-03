#include<world.hh>

world::world(int tw, int th, int trate, char* name) {
	w = tw;
	h = th;
	rate = trate;
	started = 0;
	t = 0;
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(w,h);
	glutCreateWindow(name);
}

int world::getTime() {
	if(!started) return 0;
	timeval now;
	gettimeofday(&now,NULL);
	t = (int)((now.tv_sec + now.tv_usec/1000000. - starttime.tv_sec - starttime.tv_usec/1000000.)*rate);
	return t;
}

void world::start() {
	t = 0;
	gettimeofday(&starttime,NULL);
	started = 1;
}

void world::update() {
	getTime(); //not much to do here yet
}

void world::draw() {
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glColor3d(0.0,0.0,0.0);
	glVertex2d(-1.0, 1.0);
	glVertex2d( 1.0, 1.0);
	glVertex2d( 1.0,-1.0);
	glVertex2d(-1.0,-1.0);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	for(int i = 0; i<bullets.size(); i++) {
		glBindTexture(GL_TEXTURE_2D,bullets[i]->tex);
		double x = (bullets[i]->getX(t)-w/2.)/(w/2.), y = (bullets[i]->getY(t)-h/2.)/(h/2.), dx = bullets[i]->w/(4.*w), dy = bullets[i]->h/(4.*h);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex2d(x-dx,y-dy);
		glTexCoord2d(0.0,1.0); glVertex2d(x-dx,y+dy);
		glTexCoord2d(1.0,1.0); glVertex2d(x+dx,y+dy);
		glTexCoord2d(1.0,0.0); glVertex2d(x+dx,y-dy);
		glEnd();
	}
	glFlush();
}
