#include "particle.hpp"

#include <iostream>

#include "vector3d.hpp"

using namespace std;

Particle::Particle(Vector3D pos, Vector3D vel, Vector3D acc, float radius,
                   float color[]) {
    this->set_pos(pos);
    this->set_vel(vel);
    this->set_acc(acc);
    this->radius = radius;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
}