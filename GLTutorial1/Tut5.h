//
//  Tut5.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/12/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Tut5_h
#define Tut5_h
#include <OpenGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>
#include <vector>
#include "Vec3.h"


class Tut5
{
public:
	Tut5();
	void render();
	void reshape(int w, int h);
	void tick(float dt);
private:
	GLuint vbo;
	GLuint vao;
	GLuint shaderProgram;
	GLint scaleLocation;
	GLint colorLocation;
	float time;
	std::vector<Vec3> verts;
};


#endif /* Tut5_h */
