#include "object.hpp"

void Object::update() {
    this->vel.add(this->acc);
    this->pos.add(this->vel);
}

void Object::set_pos(Vector3D v) { this->pos = v; }

void Object::set_vel(Vector3D v) { this->vel = v; }

void Object::set_acc(Vector3D v) { this->acc = v; }

Vector3D Object::get_pos() { return this->pos; }

Vector3D Object::get_vel() { return this->vel; }

Vector3D Object::get_acc() { return this->acc; }