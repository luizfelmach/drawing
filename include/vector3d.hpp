#pragma once

#include <iostream>

using namespace std;

class Vector3D {
   public:
    float x, y, z;
    Vector3D();
    Vector3D(float, float, float);
    void add(Vector3D);
    void sub(Vector3D);
    void mult(float);
    float module();
    Vector3D direction();
    void mult_matrix(float[], int, int);
    void rotateZ(float);
    float distance(Vector3D);
    Vector3D vector3D_copy();
    friend ostream& operator<<(ostream& os, const Vector3D& dt);
};
