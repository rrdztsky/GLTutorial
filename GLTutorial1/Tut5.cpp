//
//  Tut5.cpp
//  GLTutorial1
//
//	Triangle oscillates with a sine function with respect to time, updates every 60th of a second once the new frame is drawn
//
//  Created by Rachel Radeztsky on 6/12/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#include "Tut5.h"
#include "Vec3.h"
#include <iostream>
#include <cmath>
#include <OpenGL/gl3.h>
#define __gl_h_
#include <GLUT/glut.h>

Tut5::Tut5()
: time(0.0f) //initializer list
{
	verts.emplace_back(-1.0f, -1.0f, 0.0f); //template thingies forward arguments
	verts.emplace_back(1.0f, -1.0, 0.0f);
	verts.emplace_back(0.0f, 1.0, 0.0f);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo); //generate buffers at address of vbo (pointer)
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 3.0*sizeof(Vec3), &verts[0], GL_STATIC_DRAW); //sends OpenGL the three floats.
	
	shaderProgram = glCreateProgram();
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	const char *vsText =
	R"(
#version 150
	in vec3 Position;
	uniform float gScale;
	void main()
	{
		gl_Position = vec4(gScale*Position.x, gScale*Position.y, Position.z, 1.0);
	}
	)";
	const GLchar *p[1] = {(const GLchar *) vsText}; //array of pointers, one of them, one char cast as a GLchar
	GLint l[1] = {(GLint) strlen(vsText)}; //array of one int, initiaized to strlen at vsText. strlen function counts strings
	glShaderSource(vs, 1, p, l); //p and l are passing addresses of the arrays. Shader id'd by vs, one line.
	glCompileShader(vs); //integer id for the shader
	
	//tests if compiler ran successfully, 1 if successful, 0 if not
	GLint success;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(vs, sizeof(infoLog), nullptr, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, infoLog);
	}
	glAttachShader(shaderProgram, vs); //attach the vertex shader to the shader program
	
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	const char *fsText =
	R"(
#version 150
	out vec4 FragColor;
	uniform float gColor;
	void main()
	{
		FragColor = vec4(1.0, gColor, gColor, 1.0); //output a vec4 called FragColor, make whatever pixels it has whatever color I say
	}
	)";
	const GLchar *fp[1] = {(const GLchar *) fsText}; //array of pointers, one of them, one char cast as a GLchar
	GLint fl[1] = {(GLint) strlen(fsText)}; //array of one int, initiaized to strlen at fsText. strlen function counts strings
	glShaderSource(fs, 1, fp, fl); //fp and fl are passing addresses of the arrays. Shader id'd by vs, one line.
	glCompileShader(fs); //integer id for the shader
	
	//tests if compiler ran successfully, 1 if successful, 0 if not
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(fs, sizeof(infoLog), nullptr, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, infoLog);
	}
	glAttachShader(shaderProgram, fs); //attach the fragment shader to the shader program
	
	glLinkProgram(shaderProgram);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(fs, sizeof(infoLog), nullptr, infoLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", infoLog);
	}
	
	scaleLocation = glGetUniformLocation(shaderProgram, "gScale"); //tell us the integer id for the location of the scale variable in OpenGL
	colorLocation = glGetUniformLocation(shaderProgram, "gColor");
	
}

void Tut5::render()
{
	std::cout << "display\n"; // print out to tell us it got called
	glBindVertexArray(vao);
	// make some test calls to show that it works
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // colors: red green blue alpha(transparency)0-1, none-full
	glClear(GL_COLOR_BUFFER_BIT); // clear the main color buffer to set color
	glValidateProgram(shaderProgram);
	glUseProgram(shaderProgram);
	glUniform1f(scaleLocation, 0.5f*std::sin(2.0*time)); //update gScale to sin(time) will oscillate every 6.2 seconds
	float color = 0.5f*(std::sin(2.0*time) + 1.0); //creates a variable to oscillate color between red and white
	glUniform1f(colorLocation, color); //updates gColor
	glEnableVertexAttribArray(0); //enable the first slot
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //for the bound buffer and attribArray, here is what you're getting: three at a time, they're floats, don't normalize them, tightly packed (stride is zero), first one is at zero(beginning)
	glDrawArrays(GL_TRIANGLES, 0, 3); //draw points, start at index zero, draw primitives
	glDisableVertexAttribArray(0); //shuts down the attrib array
	glBindVertexArray(0);
}

void Tut5::reshape(int w, int h)
{
	std::cout << "reshape " << w  << " " << h << "\n";
}

void Tut5::tick(float dt)
{
	std::cout << "tick " << dt << "\n";
	time += dt;
	glutPostRedisplay();
}