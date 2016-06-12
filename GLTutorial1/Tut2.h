//
//  Tut2.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/5/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Tut2_h
#define Tut2_h
#include <OpenGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#include <vector>
#include "Vec3.h"


class Tut2
{
public:
	Tut2();
	void render();
	void reshape(int w, int h);
private:
	GLuint vbo;
	GLuint vao;
	GLuint shaderProgram;
	std::vector<Vec3> verts;
};

#endif /* Tut2_h */
