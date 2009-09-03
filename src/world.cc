#include<world.hh>

world::world(int tw, int th, int trate, char* name) {
	w = tw;
	h = th;
	rate = trate;
	started = 0;
	t = 0;
	lastspawn = 0;
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(w,h);
	glutCreateWindow(name);
}

void world::addBullet(bullet *b) {
	bullets.push_back(b);
}

void world::addPlayer(player *p) {
	players.push_back(p);
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
	if(t - lastspawn >= 10) {
		addBullet(new testBullet(t,w));
		lastspawn = t;
	}
	for(int i = 0; i<bullets.size(); i++) {
		int x = bullets[i]->getX(t);
		int y = bullets[i]->getY(t);
		int bw = bullets[i]->w, bh = bullets[i]->h;
		if(x < -bw/2 || x > w + bw/2 || y < -bw/2 || y > h+bw/2) {
			bullets[i] = bullets[bullets.size()-1];
			bullets.pop_back();
			i--;
		}
	}
	for(int i = 0; i<players.size(); i++) {
		players[i]->update(t);
	}
	for(int i = 0; i<players.size(); i++) {
		for(int j = 0; j<bullets.size(); j++) {
			int dx = players[i]->getX() - bullets[j]->getX(t), dy = players[i]->getY() - bullets[j]->getY(t), r = players[i]->r + bullets[j]->r;
			if(dx*dx + dy*dy < r*r) {
				exit(0);
			}
		}
	}
}

void world::draw() {
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glColor3d(0.0,0.0,0.0);
	glVertex2d(-1.0, 1.0);
	glVertex2d( 1.0, 1.0);
	glVertex2d( 1.0,-1.0);
	glVertex2d(-1.0,-1.0);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc (GL_ONE,GL_ONE);
	for(int i = 0; i<bullets.size(); i++) {
		glBindTexture(GL_TEXTURE_2D,bullets[i]->tex);
		double x = (bullets[i]->getX(t)-w/2.)/(w/2.), y = (h/2.-bullets[i]->getY(t))/(h/2.), dx = (double)bullets[i]->w/(w), dy = -(double)bullets[i]->h/(h);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex2d(x-dx,y-dy);
		glTexCoord2d(0.0,1.0); glVertex2d(x-dx,y+dy);
		glTexCoord2d(1.0,1.0); glVertex2d(x+dx,y+dy);
		glTexCoord2d(1.0,0.0); glVertex2d(x+dx,y-dy);
		glEnd();
	}
	for(int i = 0; i<players.size(); i++) {
		glBindTexture(GL_TEXTURE_2D,players[i]->tex);
		double x = (players[i]->getX()-w/2.)/(w/2.), y = -(players[i]->getY()-h/2.)/(h/2.), dx = (double)players[i]->w/(w), dy = -(double)players[i]->h/(h);
		glBegin(GL_QUADS);
		glTexCoord2d(0.0,0.0); glVertex2d(x-dx,y-dy);
		glTexCoord2d(0.0,1.0); glVertex2d(x-dx,y+dy);
		glTexCoord2d(1.0,1.0); glVertex2d(x+dx,y+dy);
		glTexCoord2d(1.0,0.0); glVertex2d(x+dx,y-dy);
		glEnd();
	}
	glFlush();
}

void world::keyboardHandler(unsigned char key) {
	for(int i = 0; i<players.size(); i++) {
		players[i]->keyboardHandler(key);
	}
}

void world::keyboardUpHandler(unsigned char key) {
	for(int i = 0; i<players.size(); i++) {
		players[i]->keyboardUpHandler(key);
	}
}

void world::specialHandler(int key) {
	for(int i = 0; i<players.size(); i++) {
		players[i]->specialHandler(key);
	}
}

void world::specialUpHandler(int key) {
	for(int i = 0; i<players.size(); i++) {
		players[i]->specialUpHandler(key);
	}
}
