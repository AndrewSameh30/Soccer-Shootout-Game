#ifndef TEX_H
#define TEX_H

//#include <gl.h>
//#include <glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <glut.h>
using namespace std;

class Texture {
public:
	int loadBMP_custom(const char* imagepath);
};

#endif

