#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "camera.h"
#include "cube.h"

#ifndef _WIN32
#define __stdcall
#endif

#ifndef CALLBACK
#define CALLBACK
#endif

int drawMode = 0;
float pitch, yaw = 0.0;
float sensitivity = 0.05;
int tick = 0;
bool lights_on = true;
bool clipping = true;
bool window_lights_on = true;
bool world_light_on = true;
bool big_cone = true;
bool sunlight_on = true;


int window_width = 720;
int window_height = 720;




//TESTING THINGS HERE--------------------------
float no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
float mat_ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
float mat_ambient_color[] = {0.1f, 0.1f, 0.025f, 1.0f};

float mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
float no_shininess = 0.0f;
float low_shininess = 5.0f;
float high_shininess = 100.0f;
float mat_emission[] = {0.2f,0.2f,0.2f,0.0f};
GLUquadric* quadric = gluNewQuadric();
//----------------------------------------------



GLfloat no_val[] = {0,0,0,0};
GLfloat ambient_val[] = {0,0,0,1};
GLfloat diffuse_val[] = {1,1,1,1};
GLfloat specular_val[] = {1,1,1,1};
GLfloat position_val[] = {0,0,0,0};
GLfloat static_pos[] = {1,1,1,0};
GLfloat light_mat[] = {0.95,0.4,0,1};
//GLfloat low_shininess = 5.0f;
GLfloat light_dir[] = {0,0,-1,0};
GLfloat light_pos[] = {1,1,0,0};
GLfloat model_val[] = {0.2,0.2,0.2,1};

GLfloat blue_val[] = {0,0,1,1};
//GLfloat no_shininess = 0.0f;

Camera camera;
//float position[] = {-25.0f, -35.0f, 20.0f, 1.0f};





//important stuff--------------------------------------------------------------------------
 //direction that the light comes from
float mat_diffuse[] = {0.3f, 0.3f, 0.40f, 1.0f};
float window_light_dir[] = {-1,1,0};
//float window_light_pos[] = {-14.6f,5.0f,-33.0f,1.0f};
float mat_window_light[] = {0.245f,0.1563f,0.03f,1.0f};



//----------------------------------------------------------------------------------------


Cube sun(10,0,150,0,0.98,0.625,0.12,1);
GLfloat sun_rotation = 0.0;

Cube ground(100,50,-100,50,0.65,0.65,0.65,1);
Cube house1(30,-15,0,-15,1,1,1,1);
Cube house2(30,45,0,-15,1,1,1,1);
Cube house3(30,-15,0,45,1,1,1,1);
Cube house4(30,45,0,45,0.5,0.5,0.5,1);

Cube h1window1(8,-14.7,5,-19,0.98,0.625,0.12,0); //light
Cube h1window2(8,-14.7,5,-33, 0.8,0.8,0.8,0); 
Cube h1window3(8,-14.7,17,-19,0.8,0.8,0.8,0);
Cube h1window4(8,-14.7,17,-33,0.8,0.8,0.8,0);

Cube h2window1(8,-14.7,5,41,0.8,0.8,0.8,0);
Cube h2window2(8,-14.7,5,27,0.98,0.625,0.12,0); //light
Cube h2window3(8,-14.7,17,41,0.8,0.8,0.8,0);
Cube h2window4(8,-14.7,17,27,0.8,0.8,0.8,0);

Cube h3window1(8,22.7,5,-19,0.8,0.8,0.8,0);
Cube h3window2(8,22.7,5,-33,0.8,0.8,0.8,0);
Cube h3window3(8,22.7,17,-19,0.98,0.625,0.12,0); //light
Cube h3window4(8,22.7,17,-33,0.8,0.8,0.8,0);

Cube h4window1(8,22.7,5,41,0.8,0.8,0.8,0);
Cube h4window2(8,22.7,5,27,0.8,0.8,0.8,0);
Cube h4window3(8,22.7,17,41,0.8,0.8,0.8,0);
Cube h4window4(8,22.7,17,27,0.98,0.625,0.12,0); //light


Cube collision_shapes[] =
{ground, house1, house2, house3, house4,
h1window2, h1window3, h1window4, h2window1,
h2window3, h2window4, h3window1, h3window2,
h3window4, h4window1, h4window2, h4window3};
	
Cube lights[] = 
{h1window1, h2window2, h3window3, h4window4};


double oldx = camera.eyex;
double oldy = camera.eyey;
double oldz = camera.eyez;


//GLfloat light1_diffuse[] = { 0.98,0.625,0.12, 1.0 };

GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light1_diffuse[] = { 0.25f,0.15,0.03f,1.0};
GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };

GLfloat window_light_pos[] = {-14.6,5,-33,1};
GLfloat spot_dir[] = {1.0, -1.0, 0.0 };

GLfloat window_light_pos2[] = {-14.6,5,27,1};
GLfloat spot_dir2[] = {1,-1,0};

GLfloat window_light_pos3[] = {14.6,24,-19,1};
GLfloat spot_dir3[] = {-1,-1,0};

GLfloat window_light_pos4[] = {14.6,24,27,1};
GLfloat spot_dir4[] = {-1.0, -1.0, 0.0 };

GLfloat world_light_pos[] = {1.0f, 1.0f, 1.0f, 0.0f};
GLfloat sun_light_pos[] = {0,150,0,0};

void drawSun(){
	glTranslatef(0,150,0);
	
	//  http://glprogramming.com/red/chapter05.html
	
	//Need two sets of Push/PopMatrix to move the light with the sphere
	glPushMatrix();
		
		glPushMatrix();
			glTranslatef(0, -150, 0);
			glRotatef(sun_rotation,1,0,0);
			glTranslatef(0, 150, 0);
			glLightfv(GL_LIGHT5, GL_DIFFUSE, mat_diffuse);
			glLightfv(GL_LIGHT5, GL_POSITION, sun_light_pos);
			glColor4f(1,1,1,1);
			glutSolidSphere (10, 40, 40);
		glPopMatrix();
		
	glPopMatrix();
	
	sun_rotation += 1;
}

void generateView(){
	glMatrixMode(GL_MODELVIEW);
	
	//glLightfv(GL_LIGHT1, GL_POSITION, spot_direction);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(GL_LIGHT0, GL_POSITION, world_light_pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
	
	
	//glLightfv(GL_LIGHT1, GL_POSITION, window_light_dir);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_window_light);
	
	
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, window_light_pos);
	
	//glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_dir);
	//glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	
	glLightfv(GL_LIGHT2, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, window_light_pos2);
	
	//glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 45.0);
	//glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_dir2);
	//glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);
	
	
	glLightfv(GL_LIGHT3, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT3, GL_POSITION, window_light_pos3);
	
	
	//glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 45.0);
	//glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_dir3);
	//glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0);
	
	
	glLightfv(GL_LIGHT4, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT4, GL_POSITION, window_light_pos4);
	
	
	//glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 45.0);
	//glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_dir4);
	//glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 2.0);
	
	
	drawSun();
	
	
	//These don't work for some reason
	//glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
	//glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
	//glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
	
	/*
	if(big_cone){
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 70.0);
	} else {
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	}
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction2);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	*/
	
	//glLightfv(GL_LIGHT1, GL_EMISSION, mat_window_light);
	
	
	
	glLoadIdentity();
	
	//Don't forget gluLookAt ...
	gluLookAt(camera.eyex, camera.eyey, camera.eyez,
	camera.centerx, camera.centery, camera.centerz,
	camera.upx, camera.upy, camera.upz);
	
	
	/*
	glPushMatrix();
	glTranslatef(0,10,-75);
	glutSolidSphere (1.0, 20, 16);
	glPopMatrix();
	*/ //sphere example
	
	
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		collision_shapes[i].drawCube();
	}
	for(int i = 0; i < (sizeof(lights) / sizeof(lights[0])); i++){
		lights[i].drawCube();
	}
	
	//sun.drawLight(sun_rotation);
	glEnd();
	
	
	
	
	glutSwapBuffers();
}

bool checkCenterCollision(Cube cube){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((camera.centerx > cube.xmin && camera.centerx < cube.xmax &&
			camera.centery > cube.ymin && camera.centery < cube.ymax &&
			camera.centerz > cube.zmin && camera.centerz < cube.zmax)){
			colliding = true;
		}
	}
	return colliding;
}

bool checkEyeCollision(Cube cube){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((camera.eyex > cube.xmin && camera.eyex < cube.xmax &&
			camera.eyey > cube.ymin && camera.eyey < cube.ymax &&
			camera.eyez > cube.zmin && camera.eyez < cube.zmax)){
			colliding = true;
		}
	}
	return colliding;
}

bool checkForwardCollision(Cube cube[]){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((checkCenterCollision(cube[i])) && (checkEyeCollision(cube[i]))){
			colliding = true;
		}
	}
	return colliding;
}

bool checkBackwardCollision(Cube cube[]){
	bool colliding = false;
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if(
		((2 * camera.eyex - camera.centerx) > (cube[i].xmin)) &&
		((2 * camera.eyex - camera.centerx) < (cube[i].xmax)) &&
		((2 * camera.eyey - camera.centery) > (cube[i].ymin)) &&
		((2 * camera.eyey - camera.centery) < (cube[i].ymax)) &&
		((2 * camera.eyez - camera.centerz) > (cube[i].zmin)) &&
		((2 * camera.eyez - camera.centerz) < (cube[i].zmax))
		){
			colliding = true;
		}
	}
	return colliding;
}

bool checkLeftCollision(Cube cube[]){
	bool colliding = false;
	camera.updateDeltas(camera.deltax, camera.deltaz);
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((fmod(abs(yaw), 360)) >= 0 && (fmod(abs(yaw), 360) <= 180) && yaw >= 0){
			if( //check y values here too
			(camera.eyex + (-1 * camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex + (-1 * camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez + (-1 * camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez + (-1 * camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		} else {
			if(
			(camera.eyex - (-1 * camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex - (-1 * camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez - (-1 * camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez - (-1 * camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		}
	}
	//std::cout<<"Collision: "<<colliding<<" yaw: "<<yaw<<std::endl;
	return colliding;
}

bool checkRightCollision(Cube cube[]){
	bool colliding = false;
	camera.updateDeltas(camera.deltax, camera.deltaz);
	for(int i = 0; i < (sizeof(collision_shapes) / sizeof(collision_shapes[0])); i++){
		if((fmod(abs(yaw), 360)) >= 0 && (fmod(abs(yaw), 360) <= 180) && yaw >= 0){
			if(
			(camera.eyex + (camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex + (camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez + (camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez + (camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		} else {
			if(
			(camera.eyex - (camera.deltax * camera.speed) > (cube[i].xmin)) &&
			(camera.eyex - (camera.deltax * camera.speed) < (cube[i].xmax)) &&
			(camera.eyez - (camera.deltaz * camera.speed) > (cube[i].zmin)) &&
			(camera.eyez - (camera.deltaz * camera.speed) < (cube[i].zmax)) &&
			(camera.eyey > cube[i].ymin && camera.eyey < cube[i].ymax)
			){
				colliding = true;
			}
		}
	}
	//std::cout<<"Collision: "<<colliding<<" yaw: "<<yaw<<std::endl;
	return colliding;
}

void mouseMove(int x, int y){
	//moving left/right - adjust centerx and centery
	//moving up/down - adjust centerz
	

	double mousex = x - 360;
	double mousey = 360 - y;

	yaw += mousex * sensitivity;
	pitch += mousey * sensitivity;
	
	//make sure yaw is between 0 and 360 at all times
	if(yaw >= 360){
		yaw -= 360;
	}
	if(yaw <= 0){
		yaw += 360;
	}
	
	//Clamp to looking straight up or straight down at most
	if(pitch > 89.0f){
		pitch = 89.0f;
	}
	if(pitch < -89.0f){
		pitch = -89.0f;
	}
	
	//keeps pointer at the center of the screen, as a game would
	//works well with hiding the cursor, also as a game would (usually)
	if(tick % 10 == 0){
		glutWarpPointer(window_width / 2, window_width / 2);
		//for some reason there's a problem here when I set window width higher
		//std::cout<<window_width / 2<<" "<<window_height / 2<<std::endl;
	}
	if(tick % 120 == 0){ 
		tick = 0; 
	}
	tick++; 
}

void keyPressed(unsigned char key, int x, int y){
	switch(key){
		case 27:
			glutDestroyWindow(glutGetWindow());
			break;
		case 'w':
			oldx = camera.eyex;
			oldy = camera.eyey;
			oldz = camera.eyez;
			if(not checkForwardCollision(collision_shapes) || not clipping){
				camera.moveForward();
			}
			break;
		case 's':
			if(not checkBackwardCollision(collision_shapes) || not clipping){
				camera.moveBackward();
			}
			break;
		case 'd':
			if
			(not checkRightCollision(collision_shapes) || not clipping){
				camera.updateDeltas(camera.deltax, camera.deltaz);
				camera.strafeRight(pitch, yaw);
			}
			break;
		case 'a':
			if
			(not checkLeftCollision(collision_shapes) || not clipping){
				camera.updateDeltas(camera.deltax, camera.deltaz);
				camera.strafeLeft(pitch, yaw);
			}
			break;
		case ' ':
			//Defaults to a normal view. 
			//Pressing space switches to wireframe mode.
			//Pressing space again breaks everything for some reason.
			drawMode = ++drawMode % 3;
			if(drawMode == 0) { // fill mode
			
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_CULL_FACE);
			}
			else if(drawMode == 1) { // wireframe mode
			
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_CULL_FACE);
			}
			else if(drawMode == 2) { // point mode
				glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
				glDisable(GL_DEPTH_TEST);
				glDisable(GL_CULL_FACE);
			}
			//std::cout<<drawMode<<std::endl;
			break;
		case 't':
			std::cout<<"centerx: "<<camera.centerx<<" centery: "<<camera.centery<<" centerz: "<<camera.centerz<<std::endl;
			std::cout<<"eyex: "<<camera.eyex<<" eyey: "<<camera.eyey<<" eyez: "<<camera.eyez<<std::endl;
			std::cout<<"yaw: "<<yaw<<std::endl;
			break;
		case '+':
			if(camera.speed < 2){
				camera.speed += 0.05;
			}
			break;
		case '-':
			if(camera.speed > 0.5){
				camera.speed -= 0.05;
			}
			break;
		case 'l':
			if(lights_on){
				lights_on = false;
				glDisable(GL_LIGHTING);
			}
			else{
				lights_on = true;
				glEnable(GL_LIGHTING);
			}
			std::cout<<lights_on<<std::endl;
			break;
		case 'c':
			if(clipping){
				clipping = false;
			} else {
				clipping = true;
			}
			//std::cout<<"Clipping: "<<clipping<<std::endl;
			break;
		case '1':
			if(world_light_on){
				glDisable(GL_LIGHT0);
				world_light_on = false;
			} else {
				glEnable(GL_LIGHT0);
				world_light_on = true;
			}
			std::cout<<"World light: "<<world_light_on<<" "<<"Window lights: "<<window_lights_on<<std::endl;
			break;
		case '2':
			if(window_lights_on){
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT3);
				glDisable(GL_LIGHT4);
				window_lights_on = false;
			} else {
				glEnable(GL_LIGHT1);
				glEnable(GL_LIGHT2);
				glEnable(GL_LIGHT3);
				glEnable(GL_LIGHT4);
				window_lights_on = true;
			}
			std::cout<<"World light: "<<world_light_on<<" "<<"Window lights: "<<window_lights_on<<std::endl;
			break;
		case '3':
			big_cone = !big_cone;
			std::cout<<"big_cone: "<<big_cone<<std::endl;
			break;
		case '4':
			if(sunlight_on){
				glDisable(GL_LIGHT2);
				sunlight_on = false;
			} else {
				glEnable(GL_LIGHT2);
				sunlight_on = true;
			}
			break;
	}
	
	
}

void reshape(GLsizei width, GLsizei height){
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	
	glViewport(0, 0, width, height);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f, aspect, 0.1f, 500.0f);
}

void idleFunction(){
	
	//std::cout<<"Yaw: "<<yaw<<std::endl;
	
	//dir variables say whether left is positive or negative
	if(camera.centerx - camera.eyex <= 0){
		camera.zdir = 1;
	} else {
		camera.zdir = -1;
	}
	if(camera.centerz - camera.eyez <= 0){
		camera.xdir = 1;
	} else {
		camera.xdir = -1;
	}
	
	//2I - P = B
	//I = initial point, P = looking at, B = backwards
	
	camera.centerx = cos(yaw * M_PI / 180) * cos(pitch * M_PI / 180) + camera.eyex;
	camera.centery = sin(pitch * M_PI / 180) + camera.eyey;
	camera.centerz = sin(yaw * M_PI / 180) * cos(pitch * M_PI / 180) + camera.eyez;
	
	position_val[0] = camera.eyex;
	position_val[1] = camera.eyey;
	position_val[2] = camera.eyez;
	
	
	
	generateView();
}

void initLighting(){
	float ambient[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	
	glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0); //overworld light
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5); //sun
    
	//enabling blending for good effects
	glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //need these for blending and shading
	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA); //maybe change src to color
	glEnable(GL_NORMALIZE);
	glEnable(GL_RESCALE_NORMAL); //not sure why this
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	
	
	

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Collision and Lighting");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutKeyboardFunc(keyPressed);
	glutPassiveMotionFunc(mouseMove);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutDisplayFunc(generateView);
	glClearColor(0,0,0.15,1);
	initLighting();
	glutReshapeFunc(reshape);
	glutIdleFunc(idleFunction);
	glutMainLoop();
	return 0;
}
