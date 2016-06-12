//
//  Vec3.h
//  GLTutorial1
//
//  Created by Rachel Radeztsky on 6/5/16.
//  Copyright © 2016 Rachel Radeztsky. All rights reserved.
//

#ifndef Vec3_h
#define Vec3_h

class Vec3
{
public:
	float x, y, z;
	Vec3() : x(0.0f), y(0.0f), z(0.0f) {} //declares and defines an (automatically) inline constructor (no .cpp needed)
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {} // second constructor; make x from x, etc
};

inline Vec3 operator+(const Vec3 &a, const Vec3 &b) //reference to a and b, will not change
{
	return Vec3(a.x + b.x, a.y + b.y, a.z + b.z); //return sum of two vectors
}

inline Vec3 operator-(const Vec3 &a, const Vec3 &b) //reference to a and b, will not change
{
	return Vec3(a.x - b.x, a.y - b.y, a.z - b.z); //return subtraction of two vectors
}

#endif /* Vec3_h */
