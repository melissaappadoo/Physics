#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
//------------------------------------------------------------------------
// Vector3 Class and Vector3 functions
//------------------------------------------------------------------------

//Minimum tolerance before treating the value as 0
float const tol = 0.0001f;

class Vector3 {
public:
    float x;
    float y;
    float z;

    Vector3(void);
    Vector3(float xi, float yi, float zi);

    float Magnitude(void);
    void  Normalize(void);
    void  Reverse(void);

    Vector3& operator+=(Vector3 u);
    Vector3& operator-=(Vector3 u);
    Vector3& operator*=(float s);
    Vector3& operator/=(float s);
    Vector3 operator-(void);

};