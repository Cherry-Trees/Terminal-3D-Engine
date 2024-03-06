#pragma once
#include "globals.h"
#include "Vec3.h"
#include "Mat44.h"

Vec3 vec3_x_mat44(Vec3 &v, Mat44 &m) 
{
    struct Vec3 out;
    out.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + m.m[3][0];
    out.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + m.m[3][1];
    out.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + m.m[3][2];
    float w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + m.m[3][3];

    if (w != 0.0f)
    {
        out.x /= w;
        out.y /= w;
        out.z /= w;
    }

    return out;
}

Vec3 rotateX(Vec3 &v, float delta)
{
    struct Mat44 Rx;
    Rx.m[0][0] = 1.f;             Rx.m[0][1] = 0.f;             Rx.m[0][2] = 0.f;             Rx.m[0][3] = 0.f;
    Rx.m[1][0] = 0.f;             Rx.m[1][1] = cosf(delta);     Rx.m[1][2] = sinf(delta);     Rx.m[1][3] = 0.f;
    Rx.m[2][0] = 0.f;             Rx.m[2][1] = -sinf(delta);    Rx.m[2][2] = cosf(delta);     Rx.m[2][3] = 0.f;
    Rx.m[3][0] = 0.f;             Rx.m[3][1] = 0.f;             Rx.m[3][2] = 0.f;             Rx.m[3][3] = 1.f;

    return vec3_x_mat44(v, Rx);
}

Vec3 rotateY(Vec3 &v, float delta)
{
    struct Mat44 Ry;
    Ry.m[0][0] = cosf(delta);     Ry.m[0][1] = 0.f;             Ry.m[0][2] = -sinf(delta);    Ry.m[0][3] = 0.f;
    Ry.m[1][0] = 0.f;             Ry.m[1][1] = 1.f;             Ry.m[1][2] = 0.f;             Ry.m[1][3] = 0.f;
    Ry.m[2][0] = sinf(delta);     Ry.m[2][1] = 0.f;             Ry.m[2][2] = cosf(delta);     Ry.m[2][3] = 0.f;         
    Ry.m[3][0] = 0.f;             Ry.m[3][1] = 0.f;             Ry.m[3][2] = 0.f;             Ry.m[3][3] = 1.f;
    
    return vec3_x_mat44(v, Ry);
}

Vec3 rotateZ(Vec3 &v, float delta)
{
    struct Mat44 Rz;
    Rz.m[0][0] = cosf(delta);     Rz.m[0][1] = -sinf(delta);    Rz.m[0][2] = 0.f;             Rz.m[0][3] = 0.f;
    Rz.m[1][0] = sinf(delta);     Rz.m[1][1] = cosf(delta);     Rz.m[1][2] = 0.f;             Rz.m[1][3] = 0.f;
    Rz.m[2][0] = 0.f;             Rz.m[2][1] = 0.f;             Rz.m[2][2] = 1.f;             Rz.m[2][3] = 0.f;         
    Rz.m[3][0] = 0.f;             Rz.m[3][1] = 0.f;             Rz.m[3][2] = 0.f;             Rz.m[3][3] = 1.f;
    
    return vec3_x_mat44(v, Rz);
}
