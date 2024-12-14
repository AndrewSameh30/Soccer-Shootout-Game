
#ifndef BOX_H
#define BOX_H

//#include <gl.h>
//#include <glu.h>
#include <stdlib.h>
#include <stdio.h>
#include "tex.h"
#include <glut.h>
using namespace std;

class Box {
public:
	int quadList;
	void createQuadList();
	void drawBox();
	float lidAngle;
	Box();
private:
	int boxTexture;
	float boxSize;
};

#endif
