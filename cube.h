//cube.h
#ifndef CUBE_H
#define CUBE_H

#include <GL/glut.h>

//cube class, pretty basic
class Cube {
	public:
		GLdouble points[8][3];
		GLdouble xmax;
		GLdouble ymax;
		GLdouble zmax;
		GLdouble xmin;
		GLdouble ymin;
		GLdouble zmin;
		GLdouble transX;
		GLdouble transY;
		GLdouble transZ;
		
		Cube(GLdouble, GLdouble, GLdouble, GLdouble);
};
#endif
