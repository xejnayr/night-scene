#include <GL/glut.h>
#include <cmath>
#include "cube.h"

Cube::Cube(GLdouble size, GLdouble tx, GLdouble ty, GLdouble tz, GLdouble ir, GLdouble ig, GLdouble ib, GLdouble ia){
	//use size to determine position of points in vector space
	//working in modelview, so points are relative
	//this is a cube so all edges will be the same length (hopefully)
	
	//tx, ty, tz, ir, ig, and ib are input values for class variables
	
	points[0][0] = 0;
	points[0][1] = 0;
	points[0][2] = 0;
	
	points[1][0] = -1 * size;
	points[1][1] = 0;
	points[1][2] = 0;
	
	points[2][0] = -1 * size;
	points[2][1] = 0;
	points[2][2] = -1 * size;
	
	points[3][0] = 0;
	points[3][1] = 0;
	points[3][2] = -1 * size;
	
	points[4][0] = 0;
	points[4][1] = size;
	points[4][2] = 0;
	
	points[5][0] = -1 * size;
	points[5][1] = size;
	points[5][2] = 0;
	
	points[6][0] = -1 * size;
	points[6][1] = size;
	points[6][2] = -1 * size;
	
	points[7][0] = 0;
	points[7][1] = size;
	points[7][2] = -1 * size;
	
	transX = tx;
	transY = ty;
	transZ = tz;
	
	r = ir;
	g = ig;
	b = ib;
	a = ia;
	
	xmin = (points[1][0] + transX) - 1; //(points[1][0] + transX) * 0.03;
	ymin = transY - 1; //(points[1][0] + transY) * 0.03;
	zmin = (points[7][2] + transZ) - 1; //(points[1][0] + transZ) * 0.03;
	xmax = transX + 1; //(points[1][0] + transX) * 0.03;
	ymax = (points[4][1] + transY) + 1; //(points[1][0] + transY) * 0.03;
	zmax = transZ + 1; //(points[1][0] + transZ) * 0.03;
	
	/*
	xmin = 0.95 * (points[1][0] + transX);
	ymin = 0.95 * transY;
	zmin = 0.95 * (points[7][2] + transZ);
	xmax = 1.05 * transX;
	ymax = 1.05 * (points[4][1] + transY);
	zmax = 1.05 * transZ;
	*/
	
	/*
	xmax = 1 * size + transX;
	ymax = 1 * size + transY;
	zmax = 1 * size + transZ;
	*/ 
}

void Cube::drawLight(GLfloat rotation){
	float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
	float mat_ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
	float mat_ambient_color[] = {0.1f, 0.1f, 0.025f, 1.0f};
	float mat_diffuse[] = {0.2, 0.2, 0.2, 1.0};
	float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat no_shininess = 0.0f;
	float low_shininess = 5.0f;
	float high_shininess = 100.0f;
	float mat_emission[] = {0.245f,0.1563f,0.03f,0.0};
	
	
	float window_light_dir[] = {1,0,0,0};
	float window_light_pos[] = {8.0f,-14.7f,5.0f,1.0f};
	float mat_window_light[] = {0.245f,0.1563f,0.03f,1.0f};
	
	
	glTranslatef(transX, transY, transZ);
	glPushMatrix();
	glTranslatef(transX * -1, transY * -1, transZ * -1);
	glRotatef(rotation,1,0,0);
	glTranslatef(transX, transY, transZ);
	
	
	//glLightfv(GL_LIGHT2, GL_AMBIENT, no_mat);
	//glLightfv(GL_LIGHT2, GL_DIFFUSE, mat_window_light);
	//glLightfv(GL_LIGHT2, GL_SPECULAR, mat_diffuse);
	
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	//glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	
	glBegin(GL_TRIANGLES); //setting all color values to white for now
		glColor4f(r, g, b, 1.0); //red, top
			glNormal3f(1,1,-1);
			glVertex3f(points[7][0], points[7][1], points[7][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
		glColor4f(r, g, b, 1.0); //green, right
			glNormal3f(1,1,-1);
			glVertex3f(points[7][0], points[7][1], points[7][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
		glColor4f(r, g, b, 1.0); //blue, front
			glNormal3f(1,1,-1);
			glVertex3f(points[7][0], points[7][1], points[7][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
		glColor4f(r, g, b, 1.0); //orange, bottom
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
		glColor4f(r, g, b, 1.0); //cyan, left
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
		glColor4f(r, g, b, 1.0); //purple, back
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
	glEnd();
	glPopMatrix();
}

void Cube::drawCube(){
	glPushMatrix();
	glTranslatef(transX, transY, transZ);
	
	
	//Draw the cube here
	//Begins at forward upper right corner
	glBegin(GL_TRIANGLES); //setting all color values to white for now
		glColor4f(r, g, b, 1.0); //red, top
			glNormal3f(1,1,-1);
			glVertex3f(points[7][0], points[7][1], points[7][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
		glColor4f(r, g, b, 1.0); //green, right
			glNormal3f(1,1,-1);
			glVertex3f(points[7][0], points[7][1], points[7][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
		glColor4f(r, g, b, 1.0); //blue, front
			glNormal3f(1,1,-1);
			glVertex3f(points[7][0], points[7][1], points[7][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
		glColor4f(r, g, b, 1.0); //orange, bottom
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(1,-1,-1);
			glVertex3f(points[3][0], points[3][1], points[3][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
		glColor4f(r, g, b, 1.0); //cyan, left
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,-1);
			glVertex3f(points[6][0], points[6][1], points[6][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(-1,-1,-1);
			glVertex3f(points[2][0], points[2][1], points[2][2]);
		glColor4f(r, g, b, 1.0); //purple, back
			glNormal3f(-1,1,1);
			glVertex3f(points[5][0], points[5][1], points[5][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
			glNormal3f(1,-1,1);
			glVertex3f(points[0][0], points[0][1], points[0][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[1][0], points[1][1], points[1][2]);
			glNormal3f(-1,1,1);
			glVertex3f(points[4][0], points[4][1], points[4][2]);
	glEnd();
	glPopMatrix();
}
