//
//  Camera.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 12/31/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Camera_h
#define Camera_h

#include "Vec3.h"
#include "Quat.h"
#include "Matrix4x4.h"

class Camera
{
public:
	Camera();
	Matrix4x4 getProjection();
	Matrix4x4 getView();
private:
	Vec3 position;
	Quat rotation;
	float fov;
	float aspect;
	float far;
	float near;
};

#endif /* Camera_h */
