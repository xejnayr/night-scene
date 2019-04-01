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

void Cube::drawLight(){
	float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
	float mat_ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
	float mat_ambient_color[] = {0.1f, 0.1f, 0.025f, 1.0f};
	float mat_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	float no_shininess = 0.0f;
	float low_shininess = 5.0f;
	float high_shininess = 100.0f;
	float mat_emission[] = {0.98,0.625,0.12,0.0};
	
	
	
	glPushMatrix();
	glTranslatef(transX, transY, transZ);
	
	
	/*
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	*/
	
	//glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	
	
	
	GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };
	//glLightfv(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT1, GL_EMISSION, mat_emission);
	//glLightfv(GL_LIGHT1, GL_CONSTANT_ATTENUATION, t1);
	//glLightfv(GL_LIGHT1, GL_LINEAR_ATTENUATION, t2);
	//glLightfv(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, t3);
	
	
	
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glEnable(GL_LIGHT1);
	
	
	
	/*
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    */
    
    

    
    
	//gluSphere(quadric, 6.0f, 128, 128);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	
	//glMaterialfv(GL_FRONT, GL_AMBIENT, blue_val);
	//glMaterialfv(GL_FRONT, GL_EMISSION, diffuse_val);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, blue_val);
	//glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
	//glMaterialfv(GL_FRONT, GL_EMISSION, blue_val);
	
	//glColor3f(0,0,1);
	
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, light_mat);
	//glMaterialfv(GL_FRONT, GL_POSITION, light_dir);
	//glMaterialfv(GL_FRONT, GL_EMISSION, light_mat);
	
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_mat);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_dir);
	
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

void Cube::drawCube(){
	float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
	float mat_ambient[] = {0.4f, 0.4f, 0.4f, 1.0f};
	float mat_ambient_color[] = {0.1f, 0.1f, 0.025f, 1.0f};
	float mat_diffuse[] = {0.1f, 0.5f, 0.8f, 1.0f};
	float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
	float no_shininess = 0.0f;
	float low_shininess = 5.0f;
	float high_shininess = 100.0f;
	float mat_emission[] = {0.2f,0.2f,0.2f,0.0f};
	
	
	
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
