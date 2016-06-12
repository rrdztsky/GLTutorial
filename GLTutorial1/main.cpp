//
//  main.cpp
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 3/27/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#include "Tut5.h"
#include <memory>
#include <mach/mach_time.h>

std::unique_ptr<Tut5> tut;
void display();
void reshape(int w, int h);
void idle();


int main(int argc, const char * argv[])
{
	glutInit(&argc, (char **)argv); // start up GLUT and consume command line arguments
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_3_2_CORE_PROFILE); // initialize display mode and add gl3.2 features
	glutInitWindowSize(640, 480); // set initial window size
	glutInitWindowPosition(100, 100); // set initial window position
	glutCreateWindow("rachel"); // create window and name it
	glutDisplayFunc(display); // give GLUT a pointer to my display callback function
	glutReshapeFunc(reshape); // give GLUT a pointer to my reshape callback function
	tut.reset(new Tut5); //new makes a thing in dynamic memory
	std::cout << "hello\n";
	glutIdleFunc(idle);
	glutMainLoop(); // enter the GLUT loop never to return, everything happens via callbacks (typical for graphics)
}

// called by GLUT for drawing
void display()
{
	tut->render();
	glutSwapBuffers(); // swaps front and back buffers
}

// called by GLUT when window size changes
void reshape(int w, int h)
{
	tut->reshape(w, h);
}

void idle()
{
	static auto ta = mach_absolute_time(); //will only run the first time, ta initialized
	auto tb = mach_absolute_time();
	double dt = (double)(tb - ta)*1.0e-9;
	tut->tick((float)dt);
	ta = tb;
}