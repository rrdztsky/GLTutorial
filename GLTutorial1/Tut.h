//
//  Tut.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/19/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Tut_h
#define Tut_h
#include "rrgl.h"
#include <vector>
#include "Vec3.h"
#include "Camera.h"


class Tut
{
public:
	Tut();
	void render();
	void reshape(int w, int h);
	void keyboard(unsigned char key, int x, int y);
	void keyboardUp(unsigned char key, int x, int y);
	void motion(int x, int y);
	void mouse(int button, int state, int x, int y);
	void tick(float dt);
private:
	GLuint vbo;
	GLuint vao;
	GLuint shaderProgram;
	GLuint ibo;
	GLint worldLocation;
	float time;
	std::vector<Vec3> verts;
	std::vector<unsigned int> indices;
	Camera camera;
};



#endif /* Tut_h */
