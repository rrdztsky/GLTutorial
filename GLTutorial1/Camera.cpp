//
//  Camera.cpp
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 12/31/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#include "Camera.h"
#include <cmath>
#include <iostream>
#include <ApplicationServices/ApplicationServices.h>
#include "rrgl.h"

Camera::Camera()
: position(Vec3(0, 0, 5))
, rotation(Quat::quatWithAngleAxis(0.0f, Vec3(1.0f, 0.0f, 0.0f)))
, fov(1.0f)
, aspect(1.0f)
, near(0.01f)
, far(100.0f)
, track(false)
, centerX(300)
, centerY(300)
{
	
}

Matrix4x4 Camera::getProjection()
{
	return Matrix4x4(1.0f/(aspect*std::tan(0.5f*fov)), 0.0f, 0.0f, 0.0f,
					 0.0f, 1/(std::tan(0.5f*fov)), 0.0f, 0.0f,
					 0.0f, 0.0f, -(far + near)/(far - near), -(2.0f*far*near)/(far - near),
					 0.0f, 0.0f, -1.0f, 0.0f);
}

Matrix4x4 Camera::getView()
{
	Matrix4x4 invr = conj(rotation).getMatrix4x4(); //constructing inverse rotation from conjugate of quaternion rotation
	Matrix4x4 invt = Matrix4x4::translation(-position);
	return invr*invt;
}

void Camera::keyboard(unsigned char key, int x, int y)
{
	std::cout << key << " down\n";
	switch (key)
	{
		case 'q':
			exit(0);
			break;
		default:
			break;
	}
}

void Camera::keyboardUp(unsigned char key, int x, int y)
{
	std::cout << key << " up\n";
	switch (key)
	{
		case 'q':
			break;
		default:
			break;
	}
}

void Camera::motion(int x, int y)
{
	if (!track)
	{
		return;
	}
	int dx = x - centerX;
	int dy = y - centerY;
	Quat dPitch = Quat::quatWithAngleAxis(0.001f*dy, Vec3(1.0f, 0.0f, 0.0f));
	Quat dYaw = Quat::quatWithAngleAxis(0.001f*dx, Vec3(0.0f, -1.0f, 0.0f));
	rotation = normalize(dYaw*rotation*dPitch);
	std::cout << x << " " << y << "\n";
	CGSetLocalEventsSuppressionInterval(0.0); //reduce delay on camera motion
	//non-deprecated attempt at reducing delay
		//CGPoint warpPoint = CGPointMake(centerX, centerY);
		//CGWarpMouseCursorPosition(warpPoint);
		//CGAssociateMouseAndMouseCursorPosition(true);
	glutWarpPointer(centerX, centerY);
}

void Camera::mouse(int button, int state, int x, int y)
{
	switch (button)
	{
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
			{
				glutSetCursor(GLUT_CURSOR_NONE);
				glutWarpPointer(centerX, centerY);
				track = true;
				std::cout << "right mouse button down\n";
			}
			else if (state == GLUT_UP)
			{
				glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
				track = false;
				std::cout << "right mouse button up\n";
			}
	}
}
