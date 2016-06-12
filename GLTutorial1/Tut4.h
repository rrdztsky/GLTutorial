//
//  Tut4.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/12/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Tut4_h
#define Tut4_h
#include <OpenGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#include <vector>
#include "Vec3.h"


class Tut4
{
public:
	Tut4();
	void render();
	void reshape(int w, int h);
private:
	GLuint vbo;
	GLuint vao;
	GLuint shaderProgram;
	std::vector<Vec3> verts;
};


#endif /* Tut4_h */
