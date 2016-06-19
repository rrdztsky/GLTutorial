//
//  Matrix4x4.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/19/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Matrix4x4_h
#define Matrix4x4_h
#include <cmath>
#include "Vec3.h"

class Matrix4x4
{
public:
	float m[4][4];
};

inline Matrix4x4 operator*(const Matrix4x4 &a, const Matrix4x4 &b)
{
	Matrix4x4 r;
	for (int i = 0; i < 4; ++i) //looping over rows of result
	{
		for (int j = 0; j < 4; ++j) //looping over columns of result
		{
			r.m[i][j] = 0.0f;
			for (int k = 0; k < 4; ++k)
				{
					r.m[i][j] += a.m[i][k]*b.m[k][j];
				}
		}
	}
	return r;
}

inline Matrix4x4 scaleMatrix(float scaleX, float scaleY, float scaleZ)
{
	Matrix4x4 r;
	r.m[0][0] = scaleX; r.m[0][1] = 0.0f; r.m[0][2] = 0.0f; r.m[0][3] = 0.0f;
	r.m[1][0] = 0.0f; r.m[1][1] = scaleY; r.m[1][2] = 0.0f; r.m[1][3] = 0.0f;
	r.m[2][0] = 0.0f; r.m[2][1] = 0.0f; r.m[2][2] = scaleZ; r.m[2][3] = 0.0f;
	r.m[3][0] = 0.0f; r.m[3][1] = 0.0f; r.m[3][2] = 0.0f; r.m[3][3] = 1.0f;
	return r;
}

inline Matrix4x4 rotateZMatrix(float angle)
{
	Matrix4x4 r;
	float c = std::cos(angle);
	float s = std::sin(angle);
	r.m[0][0] = c; r.m[0][1] = -s; r.m[0][2] = 0.0f; r.m[0][3] = 0.0f;
	r.m[1][0] = s; r.m[1][1] = c; r.m[1][2] = 0.0f; r.m[1][3] = 0.0f;
	r.m[2][0] = 0.0f; r.m[2][1] = 0.0f; r.m[2][2] = 1.0f; r.m[2][3] = 0.0f;
	r.m[3][0] = 0.0f; r.m[3][1] = 0.0f; r.m[3][2] = 0.0f; r.m[3][3] = 1.0f;
	return r;
}

inline Matrix4x4 transMatrix(float transX, float transY, float transZ)
{
	Matrix4x4 r;
	r.m[0][0] = 1.0f; r.m[0][1] = 0.0f; r.m[0][2] = 0.0f; r.m[0][3] = transX;
	r.m[1][0] = 0.0f; r.m[1][1] = 1.0f; r.m[1][2] = 0.0f; r.m[1][3] = transY;
	r.m[2][0] = 0.0f; r.m[2][1] = 0.0f; r.m[2][2] = 1.0f; r.m[2][3] = transZ;
	r.m[3][0] = 0.0f; r.m[3][1] = 0.0f; r.m[3][2] = 0.0f; r.m[3][3] = 1.0f;
	return r;
}

inline Matrix4x4 transMatrix(const Vec3 &T)
{
	return transMatrix(T.x, T.y, T.z);
}

inline Matrix4x4 scaleMatrix(const Vec3 &S)
{
	return scaleMatrix(S.x, S.y, S.z);
}

inline Matrix4x4 scaleMatrix(float S)
{
	return scaleMatrix(S, S, S);
}

#endif /* Matrix4x4_h */
