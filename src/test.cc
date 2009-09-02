#include<GL/glut.h>
#include<image.hh>
#include<cstdio>

GLuint textures[2];

void displayFunc() {
	int w = glutGet(GLUT_WINDOW_WIDTH), h = glutGet(GLUT_WINDOW_HEIGHT);
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glColor3f(0.0,0.0,0.0);
	glTexCoord2d(0.0,0.0); glVertex2d(-1.0,-1.0);
	glTexCoord2d(0.0,1.0); glVertex2d(-1.0, 1.0);
	glTexCoord2d(1.0,1.0); glVertex2d( 1.0, 1.0);
	glTexCoord2d(1.0,0.0); glVertex2d( 1.0,-1.0);
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textures[1]);
	double hsize = 8.0/w, vsize = 8.0/h;
	glBegin(GL_QUADS);
	glTexCoord2d(0.0,0.0); glVertex2d(-hsize,-vsize);
	glTexCoord2d(0.0,1.0); glVertex2d(-hsize, vsize);
	glTexCoord2d(1.0,1.0); glVertex2d( hsize, vsize);
	glTexCoord2d(1.0,0.0); glVertex2d( hsize,-vsize);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutCreateWindow("Test");
	glutDisplayFunc(displayFunc);

	glGenTextures(1,textures);
	glBindTexture(GL_TEXTURE_2D,textures[0]);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	unsigned char data[8] = {0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF};
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,2,1,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
	textures[1] = loadImage((char*)"bullet");
	glutMainLoop();
}
