
//#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
//#include <GL/glut.h>
#include <cstdio>
#include "box.h"
#include "human.h"

//#include "TextureBuilder.h"
//#include "Model_3DS.h"
//#include "GLTexture.h"

#include <glut.h>

Human humanObject;
int mode = -1;
float ballMove = 0;
float ballMoveFlag = 0;


float rotAng;
//GLTexture tex_ground;

void ground() {
    glPushMatrix();
    glTranslatef(-50, -11, -50);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            glPushMatrix();
            glTranslatef(i * 10, 0, j * 10);
            glScalef(10, 0.01, 10);    
            glColor3f(0.0f, ((i + j) % 2) * -0.2 + 0.5f, 0.0f);
            glutSolidCube(1);

            glPopMatrix();
        }
}
    glPopMatrix();
}


void banner() {
    glPushMatrix();
    glTranslatef(-50, -11, -50);
    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 || i == 9){//} || j == 0 || j == 9) {
                glPushMatrix();
                glTranslatef(i * 10, 0, j * 10);
                glScalef(0.02, 10, 10);
                glColor3f(((x) % 2) * -0.2 + 0.5f, ((x) % 2) * -0.2 + 0.5f, ((x) % 2) * -0.2 + 0.5f);
                x++;
                glutSolidCube(1);

                glPopMatrix();
            }

/*
            if ( j == 0 || j == 9) {
                glPushMatrix();
                glTranslatef(i * 10, 0, j * 10);
                glScalef( 10, 10, 0.02);
                glColor3f(((x) % 2) * -0.2 + 0.5f, ((x) % 2) * -0.2 + 0.5f, ((x) % 2) * -0.2 + 0.5f);
                x++;
                glutSolidCube(1);

                glPopMatrix();
            }*/
        }
    }
    glPopMatrix();
}

void ball()
{
	glPushMatrix();
	glRotatef(-rotAng, 0, 1, 0);
	glTranslatef(0, -10, ballMove);
    glScalef(10, 10, 10);
	glRotatef(rotAng, 1, 0, 0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();
}

void goalNet()
{
	GLUquadric* mesh;
	mesh = gluNewQuadric();

	glPushMatrix();
    glScalef(40, 30, 20);
	glTranslatef(0, 0.5,-4);
	//glScalef(2, 2, 2);
	glPushMatrix();
	glTranslatef(1.1, 0, 0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glRotatef(90, 1, 0, 0);
	gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	//glColor3f(0.0f, 0.0f, 0.5f);
	glTranslatef(-1.2, 0, 0);
	glScalef(2.4, 1, 1);
	glRotatef(90, 0, 1, 0);
	gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
	glPopMatrix();

	for (int i = 0; i < 5; i++)
	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.5f);
		glTranslatef(-1.2, i*-0.2, 0);
		glScalef(2.4, 0.1, 0.1);
		glRotatef(90, 0, 1, 0);
		gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
		glPopMatrix();
	}

	for (int i = 0; i < 13; i++)
	{
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.5f);
		glTranslatef(i *0.2+ (-1.2), 0, 0);
		glScalef(0.1, 1, 0.1);
		glRotatef(90, 1, 0, 0);
		gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
		glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(-1.1, 0, 0);
	glColor3f(0.5f, 0.5f, 0.5f);
	glRotatef(90, 1, 0, 0);
	gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

void Cup()
{
	glPushMatrix();
	//glRotatef(-rotAng, 0, 1, 0);
	glTranslatef(40, 1, -10);
	//glRotatef(rotAng, 1, 0, 0);
	glColor3f(0.8f, 0.8f, 0.0f);
    glScalef(1, 2, 1);
	glutSolidSphere(1, 25, 25);
    glTranslatef(0, -1, 0);
    glColor3f(0.9f, 0.9f, 0.0f);
    glutSolidCube(1);
    glColor3f(0.0f, .4f, 0.0f);
    glTranslatef(0, -1, 0);
    glRotatef(-90, 1, 0, 0);
    
    glutSolidCone(1, 2, 30, 30);
	glPopMatrix();

	///////////////////////////
	/*glPushMatrix();
	//glRotatef(-rotAng, 0, 1, 0);
	glRotatef(rotAng, 0, 1, 0);
	glTranslatef(2, 1, 0);
	glColor3f(0.8f, 0.7f, 0.0f);
	glutSolidSphere(0.1, 25, 25);
	glPopMatrix();
    

	glPushMatrix();
	glRotatef(rotAng, 0, 1, 0);
	glScalef(0.2, 0.8, 0.2);
	glTranslatef(10.0, 1, -10);
	glColor3f(0.8f, 0.7f, 0.0f);
	
	glPopMatrix();*/
}

void move(int mode) {
    
    if (mode >= 0) {
        if (mode == 0) {
            //Hip Translation
            humanObject.hipTranslatez += 0.1f;
        }
        else if (mode == 1) {
            // Head Rotation
            if (humanObject.headz <= 45.0f)
                humanObject.headz += 2.0f;
        }
        else if (mode == 2) {
            // Neck Rotation
            if (humanObject.neckz <= 25.0f)
                humanObject.neckz += 2.0f;
        }
        else if (mode == 3) {
            // Torso Rotation
            if (humanObject.torsoz <= 25.0f)
                humanObject.torsoz += 2.0f;
        }
        else if (mode == 4) {
            if ((((int)humanObject.leftUpperArmx) % 360 <= 20.0f || ((int)humanObject.leftUpperArmx) % 360 >= 340.0f) && humanObject.leftUpperArmy >= 30.0f) {
                /*cout<<"problem case"<<endl;
                cout<<"angle"<<":"<<4.0/7.0*humanObject.leftLowerArmx<<endl;*/
                if (humanObject.leftUpperArmz < 0.0f && humanObject.leftUpperArmz < 4.0 / 7.0 * humanObject.leftLowerArmx) {
                    humanObject.leftUpperArmz += 2.0f;
                }
            }
            else {
                if (humanObject.leftUpperArmz < 0.0f)
                    humanObject.leftUpperArmz += 2.0f;
            }
        }
        else if (mode == 6) {
            if (humanObject.rightUpperArmz < 180.0f)
                humanObject.rightUpperArmz += 2.0f;
        }
        else if (mode == 8) {
            if (humanObject.hipz < 45.0f)
                humanObject.hipz += 2.0f;
        }
        else if (mode == 9) {
            if (humanObject.leftUpperLegz < 0.0f)
                humanObject.leftUpperLegz += 2.0f;
        }
        else if (mode == 11) {
            if (humanObject.rightUpperLegz < 45.0f)
                humanObject.rightUpperLegz += 2.0f;
        }
    }
    
}
void Rmove() {
    if (mode >= 0) {
        if (mode == 0) {
            //Hip Translation
            humanObject.hipTranslatez -= 0.1f;
        }
        else if (mode == 1) {
            // Head Rotation
            if (humanObject.headz >= -45.0f)
                humanObject.headz -= 2.0f;
        }
        else if (mode == 2) {
            // Neck Rotation
            if (humanObject.neckz >= -25.0f)
                humanObject.neckz -= 2.0f;
        }
        else if (mode == 3) {
            // Neck Rotation
            if (humanObject.torsoz >= -25.0f)
                humanObject.torsoz -= 2.0f;
        }
        else if (mode == 4) {
            // cout<<"AAYA"<<endl;
            if (humanObject.leftUpperArmz >= -180.0f)
                humanObject.leftUpperArmz -= 2.0f;
        }
        else if (mode == 6) {
            // cout<<fabs(4.0/7.0*humanObject.rightLowerArmx)<<endl;
            if ((((int)humanObject.rightLowerArmx) % 360 < 20.0f || ((int)humanObject.rightLowerArmx) % 360 > 340.0f) && humanObject.rightUpperArmy < -30.0f) {
                if (humanObject.rightUpperArmz > 0.0f && humanObject.rightUpperArmz > fabs(4.0 / 7.0 * humanObject.rightLowerArmx)) {
                    humanObject.rightUpperArmz -= 2.0f;
                }
            }
            else {
                if (humanObject.rightUpperArmz > 0.0f) {
                    humanObject.rightUpperArmz -= 2.0f;
                }
            }
        }
        else if (mode == 8) {
            if (humanObject.hipz > -45.0f)
                humanObject.hipz -= 2.0f;
        }
        else if (mode == 9) {
            if (humanObject.leftUpperLegz > -45.0f)
                humanObject.leftUpperLegz -= 2.0f;
        }
        else if (mode == 11) {
            if (humanObject.rightUpperLegz > 0.0f)
                humanObject.rightUpperLegz -= 2.0f;
        }
    }
}

void flag() {
    GLUquadric* mesh;
    mesh = gluNewQuadric();

    glPushMatrix();
    glScalef(10, 10, 10);
    glTranslatef(4, 0, -4);
    //glScalef(2, 2, 2);
    glPushMatrix();
    //glTranslatef(1.1, 0, 0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(90, 1, 0, 0);
    gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.0f, 0.0f, 0.5f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glTranslatef(-0.4, 0, 0);
    glScalef(1, 1, 0.1);
    //glRotatef(90, 0, 1, 0);
    //gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
    glutSolidCube(1);
    glPopMatrix();


    /*let flag */
 

    glPopMatrix();


    glPushMatrix();
    glScalef(10, 10, 10);
    glTranslatef(-5, 0, -4);
    //glScalef(2, 2, 2);
    glPushMatrix();
    //glTranslatef(1.1, 0, 0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(90, 1, 0, 0);
    gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.0f, 0.0f, 0.5f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glTranslatef(-0.4, 0, 0);
    glScalef(1, 1, 0.1);
    //glRotatef(90, 0, 1, 0);
    //gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
    glutSolidCube(1);
    glPopMatrix();




    glPopMatrix();


    glPopMatrix();


    glPushMatrix();
    glScalef(10, 10, 10);
    glTranslatef(-5, 0, 4);
    //glScalef(2, 2, 2);
    glPushMatrix();
    //glTranslatef(1.1, 0, 0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(90, 1, 0, 0);
    gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
    glPopMatrix();

    glPushMatrix();
    //glColor3f(0.0f, 0.0f, 0.5f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glTranslatef(-0.4, 0, 0);
    glScalef(1, 1, 0.1);
    //glRotatef(90, 0, 1, 0);
    //gluCylinder(mesh, 0.1, 0.1, 1, 30, 30);
    glutSolidCube(1);
    glPopMatrix();




    glPopMatrix();
}
/*
void RenderGround()
{
    glDisable(GL_LIGHTING);	// Disable lighting 

    glColor3f(0.6, 0.6, 0.6);	// Dim the ground texture a bit

    glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

    glBindTexture(GL_TEXTURE_2D, tex_ground.texture[0]);	// Bind the ground texture

    glPushMatrix();
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);	// Set quad normal direction.
    glTexCoord2f(0, 0);		// Set tex coordinates ( Using (0,0) -> (5,5) with texture wrapping set to GL_REPEAT to simulate the ground repeated grass texture).
    glVertex3f(-20, 0, -20);
    glTexCoord2f(5, 0);
    glVertex3f(20, 0, -20);
    glTexCoord2f(5, 5);
    glVertex3f(20, 0, 20);
    glTexCoord2f(0, 5);
    glVertex3f(-20, 0, 20);
    glEnd();
    glPopMatrix();

    glEnable(GL_LIGHTING);	// Enable lighting again for other entites coming throung the pipeline.

    glColor3f(1, 1, 1);	// Set material back to white instead of grey used for the ground texture.
}

*/


//////////////////////////////////////

#define _USE_MATH_DEFINES

/* Global variables */
char title[] = "3D Shapes";
float degree = 0.0f;
float verticalDegree = 0.0f;
Box boxObject;



float eyex = 0.0f, eyey = 0.0f;
float eyez = 20.0f;

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
    humanObject.createAllLists();
    boxObject.createQuadList();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(degree, 0.0f, 1.0f, 0.0f);
    glRotatef(verticalDegree, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 1.0f);


    ground();
    banner();
    if (ballMoveFlag == 1 && ballMove>-48) {
        ballMove -= 1;
    }
    else
    {
        ballMoveFlag = 0;
    }
    ball();
    flag();

    goalNet();
    Cup();
    humanObject.drawHuman();
    glTranslatef(5.0f, 0.0f, 15.0f);

    //boxObject.drawBox();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(60.0f, aspect, 0.1f, 100.0f);
}

void mouse(int button, int state, int x, int y) {
    glutPostRedisplay();
}


/*Body movement scheme is designed in the following way
There are modes which designate which body part's degree of freedom are controlled by the keys 'z', 'x' and 'c'
Mode Index :
    0: Hip-Translation
    1: Head
    2: Neck
    3: Torso
    4: Left-Upper-Arm
    5: Left-Lower-Arm
    6: Right-Upper-Arm
    7: Right-Lower-Arm
    8: Hip
    'p': Left-Upper-Leg
    'o': Left-Lower-Leg
    'i': Right-Upper-Leg
    'u': Right-Lower-Leg

If key 'z' would would increase a certain parameter of movement of some joint 'Shift'+'z' or 'Z' would decrease it

Other than that the box lid angle is controlled by '=' and '-'

All joints and box-lid have certain boundaries till which they can rotate in various directions

ALso, r is for reset

Also w, s, a & d control the camera
*/

void inputKey(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT: degree -= 5.0f; glutPostRedisplay(); break;
    case GLUT_KEY_RIGHT: degree += 5.0f; glutPostRedisplay(); break;
    case GLUT_KEY_UP: eyez -= 1.0f; glutPostRedisplay(); break;
    case GLUT_KEY_DOWN: eyez += 1.0f; glutPostRedisplay(); break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
    {
        exit(0);
        break;
    }
    case 'r': {
        humanObject.reset();
        glutPostRedisplay();
    }
    case '0': {
        mode = 0;
        glutPostRedisplay();
        break;
    }
    case '1': {
        mode = 1;
        glutPostRedisplay();
        break;
    }
    case '2': {
        mode = 2;
        glutPostRedisplay();
        break;
    }
    case '3': {
        mode = 3;
        glutPostRedisplay();
        break;
    }
    case '4': {
        mode = 4;
        glutPostRedisplay();
        break;
    }
    case '5': {
        mode = 5;
        glutPostRedisplay();
        break;
    }
    case '6': {
        mode = 6;
        glutPostRedisplay();
        break;
    }
    case '7': {
        mode = 7;
        glutPostRedisplay();
        break;
    }
    case '8': {
        mode = 8;
        glutPostRedisplay();
        break;
    }
    case 'p': {
        mode = 9;
        ballMoveFlag = 1;
        move(mode);
        glutPostRedisplay();
        break;
    }
    case 'P': {
        mode = 9;
        Rmove();
        glutPostRedisplay();
        break;
    }
    case 'o': {
        mode = 10;
        move(mode);
        glutPostRedisplay();
        break;
    }
    case 'i': {
        mode = 11;
        move(mode);
        glutPostRedisplay();
        break;
    }

    case 'I': {
        mode = 11;
        Rmove();
        glutPostRedisplay();
        break;
    }
    case 'u': {
        mode = 12;
        move(mode);
        glutPostRedisplay();
        break;
    }
    case '=':
    {
        boxObject.lidAngle += 1.0f;
        glutPostRedisplay();
        break;
    }
    case '-':
    {
        boxObject.lidAngle -= 1.0f;
        glutPostRedisplay();
        break;
    }
    case 'w':
    {
        verticalDegree -= 3.0f;
        glutPostRedisplay();
        break;
    }
    case 's':
    {
        verticalDegree += 3.0f;
        glutPostRedisplay();
        break;
    }
    case 'z': {
        if (mode >= 0) {
            if (mode == 0) {
                //Hip Translation
                humanObject.hipTranslatez += 0.1f;
            }
            else if (mode == 1) {
                // Head Rotation
                if (humanObject.headz <= 45.0f)
                    humanObject.headz += 2.0f;
            }
            else if (mode == 2) {
                // Neck Rotation
                if (humanObject.neckz <= 25.0f)
                    humanObject.neckz += 2.0f;
            }
            else if (mode == 3) {
                // Torso Rotation
                if (humanObject.torsoz <= 25.0f)
                    humanObject.torsoz += 2.0f;
            }
            else if (mode == 4) {
                if ((((int)humanObject.leftUpperArmx) % 360 <= 20.0f || ((int)humanObject.leftUpperArmx) % 360 >= 340.0f) && humanObject.leftUpperArmy >= 30.0f) {
                    /*cout<<"problem case"<<endl;
                    cout<<"angle"<<":"<<4.0/7.0*humanObject.leftLowerArmx<<endl;*/
                    if (humanObject.leftUpperArmz < 0.0f && humanObject.leftUpperArmz < 4.0 / 7.0 * humanObject.leftLowerArmx) {
                        humanObject.leftUpperArmz += 2.0f;
                    }
                }
                else {
                    if (humanObject.leftUpperArmz < 0.0f)
                        humanObject.leftUpperArmz += 2.0f;
                }
            }
            else if (mode == 6) {
                if (humanObject.rightUpperArmz < 180.0f)
                    humanObject.rightUpperArmz += 2.0f;
            }
            else if (mode == 8) {
                if (humanObject.hipz < 45.0f)
                    humanObject.hipz += 2.0f;
            }
            else if (mode == 9) {
                if (humanObject.leftUpperLegz < 0.0f)
                    humanObject.leftUpperLegz += 2.0f;
            }
            else if (mode == 11) {
                if (humanObject.rightUpperLegz < 45.0f)
                    humanObject.rightUpperLegz += 2.0f;
            }
        }
        glutPostRedisplay();
        break;
    }
    case 'Z': {
        if (mode >= 0) {
            if (mode == 0) {
                //Hip Translation
                humanObject.hipTranslatez -= 0.1f;
            }
            else if (mode == 1) {
                // Head Rotation
                if (humanObject.headz >= -45.0f)
                    humanObject.headz -= 2.0f;
            }
            else if (mode == 2) {
                // Neck Rotation
                if (humanObject.neckz >= -25.0f)
                    humanObject.neckz -= 2.0f;
            }
            else if (mode == 3) {
                // Neck Rotation
                if (humanObject.torsoz >= -25.0f)
                    humanObject.torsoz -= 2.0f;
            }
            else if (mode == 4) {
                // cout<<"AAYA"<<endl;
                if (humanObject.leftUpperArmz >= -180.0f)
                    humanObject.leftUpperArmz -= 2.0f;
            }
            else if (mode == 6) {
                // cout<<fabs(4.0/7.0*humanObject.rightLowerArmx)<<endl;
                if ((((int)humanObject.rightLowerArmx) % 360 < 20.0f || ((int)humanObject.rightLowerArmx) % 360 > 340.0f) && humanObject.rightUpperArmy < -30.0f) {
                    if (humanObject.rightUpperArmz > 0.0f && humanObject.rightUpperArmz > fabs(4.0 / 7.0 * humanObject.rightLowerArmx)) {
                        humanObject.rightUpperArmz -= 2.0f;
                    }
                }
                else {
                    if (humanObject.rightUpperArmz > 0.0f) {
                        humanObject.rightUpperArmz -= 2.0f;
                    }
                }
            }
            else if (mode == 8) {
                if (humanObject.hipz > -45.0f)
                    humanObject.hipz -= 2.0f;
            }
            else if (mode == 9) {
                if (humanObject.leftUpperLegz > -45.0f)
                    humanObject.leftUpperLegz -= 2.0f;
            }
            else if (mode == 11) {
                if (humanObject.rightUpperLegz > 0.0f)
                    humanObject.rightUpperLegz -= 2.0f;
            }
        }
        glutPostRedisplay();
        break;
    }
    case 'x': {
        if (mode >= 0) {
            if (mode == 0) {
                //Hip Translation
                humanObject.hipTranslatex += 0.1f;
            }
            else if (mode == 1) {
                // Head Rotation
                if (humanObject.headx <= 45.0f)
                    humanObject.headx += 2.0f;
            }
            else if (mode == 2) {
                // Neck Rotation
                if (humanObject.neckx <= 25.0f)
                    humanObject.neckx += 2.0f;
            }
            else if (mode == 3) {
                // Neck Rotation
                if (humanObject.torsox <= 25.0f)
                    humanObject.torsox += 2.0f;
            }
            else if (mode == 4) {
                // Upper Arm Rotation
                humanObject.leftUpperArmx += 2.0f;
            }
            else if (mode == 5) {
                if (humanObject.leftLowerArmx <= 0.0f)
                    humanObject.leftLowerArmx += 2.0f;
            }
            else if (mode == 6) {
                // Upper Arm Rotation
                humanObject.rightUpperArmx += 2.0f;
            }
            else if (mode == 7) {
                if (humanObject.rightLowerArmx <= 0.0f)
                    humanObject.rightLowerArmx += 2.0f;
            }
            else if (mode == 8) {
                if (humanObject.hipx < 45.0f)
                    humanObject.hipx += 2.0f;
            }
            else if (mode == 9) {
                if (humanObject.leftUpperLegx < 60.0f)
                    humanObject.leftUpperLegx += 2.0f;
            }
            else if (mode == 10) {
                if (humanObject.leftLowerLegx < 120.0f)
                    humanObject.leftLowerLegx += 2.0f;
            }
            else if (mode == 11) {
                if (humanObject.rightUpperLegx < 60.0f)
                    humanObject.rightUpperLegx += 2.0f;
            }
            else if (mode == 12) {
                if (humanObject.rightLowerLegx < 120.0f)
                    humanObject.rightLowerLegx += 2.0f;
            }
        }
        glutPostRedisplay();
        break;
    }
    case 'X': {
        if (mode >= 0) {
            if (mode == 0) {
                //Hip Translation
                humanObject.hipTranslatex -= 0.1f;
            }
            else if (mode == 1) {
                // Head Rotation
                if (humanObject.headx >= -45.0f)
                    humanObject.headx -= 2.0f;
            }
            else if (mode == 2) {
                // Head Rotation
                if (humanObject.neckx >= -25.0f)
                    humanObject.neckx -= 2.0f;
            }
            else if (mode == 3) {
                // Head Rotation
                if (humanObject.torsox >= -25.0f)
                    humanObject.torsox -= 2.0f;
            }
            else if (mode == 4) {
                //Upper Arm Rotation
                humanObject.leftUpperArmx -= 2.0f;
            }
            else if (mode == 5) {
                if ((((int)humanObject.leftUpperArmx) % 360 <= 20.0f || ((int)humanObject.leftUpperArmx) % 360 >= 340.0f) && humanObject.leftUpperArmy >= 30.0f) {
                    cout << "problem case" << endl;
                    if (humanObject.leftUpperArmz > -90.0f && humanObject.leftLowerArmx > -135.0f && humanObject.leftLowerArmx > 7.0 / 4.0 * humanObject.leftUpperArmz) {
                        humanObject.leftLowerArmx -= 2.0f;
                    }
                    else if (humanObject.leftUpperArmz < -90.0f) {
                        if (humanObject.leftLowerArmx > -135.0f) {
                            humanObject.leftLowerArmx -= 2.0f;
                        }
                    }
                }
                else {
                    if (humanObject.leftLowerArmx > -135.0f) {
                        humanObject.leftLowerArmx -= 2.0f;
                    }
                }
            }
            else if (mode == 6) {
                //Upper Arm Rotation
                humanObject.rightUpperArmx -= 2.0f;
            }
            else if (mode == 7) {
                if ((((int)humanObject.rightUpperArmx) % 360 <= 20.0f || ((int)humanObject.rightUpperArmx) % 360 >= 340.0f) && humanObject.rightUpperArmy < -30.0f) {
                    cout << "problem case" << endl;
                    if (humanObject.rightUpperArmz < 90.0f && humanObject.rightLowerArmx > -135.0f && humanObject.rightLowerArmx > -1.0 * 7.0 / 4.0 * humanObject.rightUpperArmz) {
                        humanObject.rightLowerArmx -= 2.0f;
                    }
                    else if (humanObject.rightUpperArmz > 90.0f) {
                        if (humanObject.rightLowerArmx > -135.0f) {
                            humanObject.rightLowerArmx -= 2.0f;
                        }
                    }
                }
                else {
                    if (humanObject.rightLowerArmx > -135.0f) {
                        humanObject.rightLowerArmx -= 2.0f;
                    }
                }
            }
            else if (mode == 8) {
                if (humanObject.hipx > -45.0f)
                    humanObject.hipx -= 2.0f;
            }
            else if (mode == 9) {
                if (humanObject.leftUpperLegx > -90.0f)
                    humanObject.leftUpperLegx -= 2.0f;
            }
            else if (mode == 10) {
                if (humanObject.leftLowerLegx > 0.0f)
                    humanObject.leftLowerLegx -= 2.0f;
            }
            else if (mode == 11) {
                if (humanObject.rightUpperLegx > -90.0f)
                    humanObject.rightUpperLegx -= 2.0f;
            }
            else if (mode == 12) {
                if (humanObject.rightLowerLegx > 0.0f)
                    humanObject.rightLowerLegx -= 2.0f;
            }
        }
        glutPostRedisplay();
        break;
    }
    case 'c': {
        if (mode >= 0) {
            if (mode == 0) {
                //Hip Translation
                humanObject.hipTranslatey += 0.1f;
            }
            else if (mode == 1) {
                // Head Rotation
                if (humanObject.heady <= 60.0f)
                    humanObject.heady += 2.0f;
            }
            else if (mode == 2) {
                // Head Rotation
                if (humanObject.necky <= 45.0f)
                    humanObject.necky += 2.0f;
            }
            else if (mode == 3) {
                // Head Rotation
                if (humanObject.torsoy <= 45.0f)
                    humanObject.torsoy += 2.0f;
            }
            else if (mode == 4) {
                // Left Upper Arm Rotation
                // cout<<(90+humanObject.leftUpperArmz)<<":"<<(180.0/M_PI)*acos(0.75*(sin(-1*humanObject.leftUpperArmz))) <<endl;
                if (((int)humanObject.rightUpperArmx) % 360 <= 20.0f || ((int)humanObject.rightUpperArmx) % 360 >= 340.0f) {
                    // cout<<"problem case"<<endl;
                    cout << humanObject.leftUpperArmz << ":" << humanObject.leftLowerArmx << endl;
                    if (humanObject.leftUpperArmz > 4.0 / 7.0 * humanObject.leftLowerArmx) {
                        if (humanObject.leftUpperArmy < 30.0f)
                            humanObject.leftUpperArmy += 2.0f;
                    }
                    else {
                        // cout<<"case 2"<<endl;
                        if (humanObject.leftUpperArmy < 90.0f)
                            humanObject.leftUpperArmy += 2.0f;
                    }
                }
                else {
                    // cout<<"no roblem"<<endl;
                    if (humanObject.leftUpperArmy < 90.0f)
                        humanObject.leftUpperArmy += 2.0f;
                }
            }
            else if (mode == 6) {
                // Head Rotation
                if (humanObject.rightUpperArmy < 90.0f)
                    humanObject.rightUpperArmy += 2.0f;
            }
            else if (mode == 8) {
                if (humanObject.hipy < 30.0f)
                    humanObject.hipy += 2.0f;
            }
            else if (mode == 9) {
                if (humanObject.leftUpperLegy < 30.0f)
                    humanObject.leftUpperLegy += 2.0f;
            }
            else if (mode == 11) {
                if (humanObject.rightUpperLegy < 30.0f)
                    humanObject.rightUpperLegy += 2.0f;
            }
        }
        glutPostRedisplay();
        break;
    }
    case 'C': {
        if (mode >= 0) {
            if (mode == 0) {
                //Hip Translation
                humanObject.hipTranslatey -= 0.1f;
            }
            else if (mode == 1) {
                // Head Rotation
                if (humanObject.heady >= -60.0f)
                    humanObject.heady -= 2.0f;
            }
            else if (mode == 2) {
                // Head Rotation
                if (humanObject.necky >= -45.0f)
                    humanObject.necky -= 2.0f;
            }
            else if (mode == 3) {
                // Head Rotation
                if (humanObject.torsoy >= -45.0f)
                    humanObject.torsoy -= 2.0f;
            }
            else if (mode == 4) {
                // Head Rotation
                if (humanObject.leftUpperArmy >= -90.0f)
                    humanObject.leftUpperArmy -= 2.0f;
            }
            else if (mode == 6) {
                // Right Upper Arm Rotation
                if (((int)humanObject.rightUpperArmx) % 360 <= 20.0f || ((int)humanObject.rightUpperArmx) % 360 >= 340.0f) {
                    // cout<<"problem"<<endl;
                    if (humanObject.rightUpperArmz < fabs(4.0 / 7.0 * humanObject.rightLowerArmx)) {
                        if (humanObject.rightUpperArmy > -30.0f) {
                            humanObject.rightUpperArmy -= 2.0f;
                        }
                    }
                    else  if (humanObject.rightUpperArmy > -90.0f) {
                        humanObject.rightUpperArmy -= 2.0f;
                    }
                    else {
                        // cout<<"no problem"<<endl;
                        if (humanObject.rightUpperArmy > -90.0f) {
                            humanObject.rightUpperArmy -= 2.0f;
                        }
                    }
                }
            }
            else if (mode == 8) {
                if (humanObject.hipy > -30.0f)
                    humanObject.hipy -= 2.0f;
            }
            else if (mode == 9) {
                if (humanObject.leftUpperLegy > -30.0f)
                    humanObject.leftUpperLegy -= 2.0f;
            }
            else if (mode == 11) {
                if (humanObject.rightUpperLegy > -30.0f)
                    humanObject.rightUpperLegy -= 2.0f;
            }
        }
        glutPostRedisplay();
        break;
    }
            /*	float headx;
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
    */
    default:
    {

    }
    }
}
//////////////////////////////////////
void Display2(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//ground();

	ball();

	goalNet();

	Cup();

	glPushMatrix();
	glRotatef(rotAng, 0, 1, 0);
	glScalef(1, 0.3, 1);
	glTranslatef(2.9, 1, -0.3);
	glColor3f(0.8f, 0.7f, 0.0f);
	glutSolidCube(0.3);
	glPopMatrix();

	glFlush();
}

void Anim() {
	rotAng += 0.01;

	glutPostRedisplay();
}

void main2(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("OpenGL - 3D Template");
	glutDisplayFunc(display);
    //glutDisplayFunc(display);
	glutIdleFunc(Anim);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, 300 / 300, 0.1f, 300.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 2.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glutMainLoop();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(inputKey);
    glutMouseFunc(mouse);
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
