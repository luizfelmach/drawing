#pragma once

#include "object.hpp"
#include "vector3d.hpp"

class Particle : public Object {
   public:
    float radius, color[3];
    Particle(Vector3D, Vector3D, Vector3D, float, float[]);
};