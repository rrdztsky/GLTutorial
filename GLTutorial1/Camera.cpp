//
//  Camera.cpp
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 12/31/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#include "Camera.h"
#include <cmath>

Camera::Camera()
: position(Vec3(0, 0, 5))
, rotation(Quat::quatWithAngleAxis(0.0f, Vec3(1.0f, 0.0f, 0.0f)))
, fov(1.0f)
, aspect(1.0f)
, near(0.01f)
, far(100.0f)
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