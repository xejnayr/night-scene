#include <GL/glut.h>
#include <cmath>
#include "cube.h"

Cube::Cube(GLdouble size, GLdouble tx, GLdouble ty, GLdouble tz){
	//use size to determine position of points in vector space
	//working in modelview, so points are relative
	//this is a cube so all edges will be the same length (hopefully)
	
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
