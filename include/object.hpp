#pragma once

#include "vector3d.hpp"

class Object {
    Vector3D pos;
    Vector3D vel;
    Vector3D acc;

   public:
    void update();
    void set_pos(Vector3D);
    void set_vel(Vector3D);
    void set_acc(Vector3D);
    Vector3D get_pos();
    Vector3D get_vel();
    Vector3D get_acc();
};
