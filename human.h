#ifndef HUM_H
#define HUM_H

//#include <gl.h>
//#include <glu.h>
#include <stdlib.h>
#include <iostream>
#include "tex.h"
#include <glut.h>
using namespace std;

class Human {
public:
	float headx;
	float heady;
	float headz;

	float neckx;
	float necky;
	float neckz;

	float torsox;
	float torsoy;
	float torsoz;

	float leftUpperArmx;
	float leftUpperArmy;
	float leftUpperArmz;

	float rightUpperArmx;
	float rightUpperArmy;
	float rightUpperArmz;

	float leftLowerArmx;
	float rightLowerArmx;

	float hipx;
	float hipy;
	float hipz;
	float hipTranslatex;
	float hipTranslatey;
	float hipTranslatez;

	float leftUpperLegx;
	float leftUpperLegy;
	float leftUpperLegz;

	float rightUpperLegx;
	float rightUpperLegy;
	float rightUpperLegz;

	float leftLowerLegx;
	float rightLowerLegx;

	int headList;
	int neckList;
	int torsoList;
	int upperArmList;
	int lowerArmList;
	int hipList;
	int upperLegList;
	int lowerLegList;

	void createAllLists();
	void drawHuman();
	void  reset();
	Human();


private:
	void  createHeadList();
	void  createNeckList();
	void  createTorsoList();
	void  createUpperArmList();
	void  createLowerArmList();
	void  createHipList();
	void  createUpperLegList();
	void  createLowerLegList();
	int humanTexture;
};
#endif