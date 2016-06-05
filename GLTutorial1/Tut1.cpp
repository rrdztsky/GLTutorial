//
//  Tut1.cpp
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/5/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#include "Tut1.h"
#include <iostream>
#include <OpenGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>

Tut1::Tut1()
{
	
}

void Tut1::render()
{
	std::cout << "display\n"; // print out to tell us it got called
	// make some test calls to show that it works
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // colors: red green blue alpha(transparency)0-1, none-full
	glClear(GL_COLOR_BUFFER_BIT); // clear the main color buffer to set color

}

void Tut1::reshape(int w, int h)
{
	std::cout << "reshape " << w  << " " << h << "\n";
}