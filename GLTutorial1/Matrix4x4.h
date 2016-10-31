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
	Matrix4x4(); //Default constructor
	Matrix4x4(
				float xx, float xy, float xz, float xw,
			 	float yx, float yy, float yz, float yw,
			  	float zx, float zy, float zz, float zw,
			  	float wx, float wy, float wz, float ww
			  );
	float &operator()(int i, int j) { return m[(4*i) + j]; } //overloads () operator for referencing
									 						 //and indexing matrix location
	const float &operator()(int i, int j) const { return m[(4*i) + j]; }
	
	float *get() { return &m[0]; } //returns address of the first element of m
	const float *get() const { return &m[0]; }
	
private:
	float m[16];
};

inline Matrix4x4 operator*(const Matrix4x4 &a, const Matrix4x4 &b)
{
	Matrix4x4 r;
	for (int i = 0; i < 4; ++i) //looping over rows of result
	{
		for (int j = 0; j < 4; ++j) //looping over columns of result
		{
			r(i,j) = 0.0f;
			for (int k = 0; k < 4; ++k)
				{
					r(i,j) += a(i,k)*b(k,j);
				}
		}
	}
	return r;
}

inline Matrix4x4 scaleMatrix(float scaleX, float scaleY, float scaleZ)
{
	return Matrix4x4 ( scaleX, 0.0f, 0.0f, 0.0f,
					   0.0f, scaleY, 0.0f, 0.0f,
					   0.0f, 0.0f, scaleZ, 0.0f,
					   0.0f, 0.0f, 0.0f, 1.0f );
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
