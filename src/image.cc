#include<image.hh>

std::map<const char*, GLuint> IMAGE_loaded;

GLuint loadImage(char *name) {
	if(IMAGE_loaded.count(name) > 0) {
		return IMAGE_loaded[name];
	}
	GLuint retval;
	glGenTextures(1,&retval);
	char *file= new char[strlen(name)+12];
	sprintf(file,"../img/%s.ppm",name);
	FILE *fppm = fopen(file,"r");
	sprintf(file,"../img/%s.pbm",name);
	FILE *fpbm = fopen(file,"r");
	fscanf(fppm,"%s ",file);
	fscanf(fpbm,"%s ",file);
	delete[] file;
	int w, h, maxc;
	fscanf(fppm,"%d %d %d ",&w,&h,&maxc);
	fscanf(fpbm,"%d %d ",&w,&h);
	unsigned char* data = new unsigned char[w*h*4];
	for(int i = 0; i<w*h; i++) {
		int r, g, b;
		char a=0;
		fscanf(fppm,"%d%d%d",&r,&g,&b);
		while(a!='0' && a!='1') fscanf(fpbm,"%c",&a);
		data[i*4+0]=r;
		data[i*4+1]=g;
		data[i*4+2]=b;
		if(a=='1') data[i*4+3]=0;
		else data[i*4+3]=(unsigned char)0xFF;
	}
	glBindTexture(GL_TEXTURE_2D,retval);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
	delete[] data;
	IMAGE_loaded[name] = retval;
	return retval;
}
