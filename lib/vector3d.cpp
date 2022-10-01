#include <math.h>

#include <iostream>
#include <vector3d.hpp>

using namespace std;

Vector3D::Vector3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3D::add(Vector3D v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}
void Vector3D::sub(Vector3D v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

float Vector3D::module() {
    float x_2 = pow(this->x, 2);
    float y_2 = pow(this->y, 2);
    float z_2 = pow(this->z, 2);

    return sqrt(x_2 + y_2 + z_2);
}

void Vector3D::mult(float k) {
    this->x *= k;
    this->y *= k;
    this->z *= k;
}

Vector3D Vector3D::direction() {
    Vector3D v = this->vector3D_copy();
    float mod = this->module();
    v.mult(1 / mod);
    return v;
}

void Vector3D::mult_matrix(float matrix[], int m, int n) {
    if (n != 3 or m != 3) {
        return;
    }

    float n_x = this->x * matrix[0] + this->y * matrix[1] + this->z * matrix[2];
    float n_y = this->x * matrix[3] + this->y * matrix[4] + this->z * matrix[5];
    float n_z = this->x * matrix[6] + this->y * matrix[7] + this->z * matrix[8];

    this->x = n_x;
    this->y = n_y;
    this->z = n_z;
}

void Vector3D::rotateZ(float angle) {
    float m[] = {cos(angle), -sin(angle), 0, sin(angle), cos(angle),
                 0,          0,           0, 1};
    this->mult_matrix(m, 3, 3);
}

float Vector3D::distance(Vector3D v) {
    Vector3D u = this->vector3D_copy();
    u.sub(v);
    return u.module();
}

Vector3D Vector3D::vector3D_copy() {
    float x = this->x;
    float y = this->y;
    float z = this->z;

    return Vector3D(x, y, z);
}

ostream& operator<<(ostream& os, const Vector3D& v) {
    os << "Vector3D ";
    os << "<" << v.x << ", " << v.y << ", " << v.z << ">";
    return os;
}