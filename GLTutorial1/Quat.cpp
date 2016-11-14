//
//  Quat.cpp
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 11/13/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#include "Quat.h"
#include <cmath>

using namespace std;

Quat Quat::quatWithAngleAxis(float angle, const Vec3 &axis)
{
	float halfAngle = 0.5f*angle;
	float c = cos(halfAngle);
	float s = sin(halfAngle);
	return Quat(s*axis.x, s*axis.y, s*axis.z, c);
}

Matrix4x4 Quat::getMatrix4x4() const
{
	//TO DO
}