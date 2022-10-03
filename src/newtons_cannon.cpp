#include <vector>
#include <xd/xd.hpp>

#include "particle.hpp"
#include "vector3d.hpp"

using namespace xd;

int win_width = 600;
int win_height = 480;
Vector3D pos_mouse(0, 0, 0);
bool is_to_attract = false;

Vector3D center_planet(win_width / 2, win_height / 2, 0);
float radius_planet = 100;

Vector3D pos(-100, -100, 0);
Vector3D vel(0, 0, 0);
Vector3D acc(0, 0, 0);
float radius = 4;
float color[] = {0.9, 0.2, 0.8};

Particle p(pos, vel, acc, radius, color);

void draw_particle(Particle p) {
    noStroke();
    fill(vec4(p.color[0], p.color[1], p.color[2], 1.0));
    Vector3D pos = p.get_pos();
    ellipse(pos.x, pos.y, p.radius * 2, p.radius * 2);
}

void scene() {
    fill(vec4(0.0, 0.0, 0.3, 1.0));
    ellipse(center_planet.x, center_planet.y, radius_planet * 2,
            radius_planet * 2);
}

void apply_forces(Particle& p) { p.update(); }

float calculate_force(Particle p) {
    Vector3D pos = p.get_pos();
    pos.sub(center_planet);
    float g = 10;
    float mass = 5000;
    return (g * mass) / pow(pos.module(), 2);
}

void attract(Particle& p) {
    Vector3D pos = p.get_pos();
    pos.sub(center_planet);
    Vector3D dir = pos.direction();
    dir.mult(-1);
    dir.mult(calculate_force(p));
    p.set_acc(dir);
}

void mouse_moved(float x, float y) {
    Vector3D pos(x, y, 0);
    pos_mouse = pos;
}

void mouse_pressed(int type) {
    if (type == 1) {
        center_planet = pos_mouse;
        return;
    }
    p.set_pos(pos_mouse);
    p.set_vel(Vector3D(0, 0, 0));
    p.set_acc(Vector3D(0, 0, 0));
}

void mouse_released(int type) {
    Vector3D pos = p.get_pos();
    pos.sub(pos_mouse);
    pos.mult(0.1);
    p.set_vel(pos);
    is_to_attract = true;
}

void check_collision(Particle& p) {
    Vector3D pos = p.get_pos();
    float distance = pos.distance(center_planet);

    if (distance <= p.radius + radius_planet) {
        p.set_vel(Vector3D(0, 0, 0));
        p.set_acc(Vector3D(0, 0, 0));
        is_to_attract = false;
    }
}

void setup() {
    size(win_width, win_height);
    mouseMoved(mouse_moved);
    mousePressed(mouse_pressed);
    mouseReleased(mouse_released);
}

void draw() {
    background(vec4(0.3f));
    scene();

    if (is_to_attract) {
        attract(p);
    }

    check_collision(p);
    apply_forces(p);
    draw_particle(p);
}

void destroy() {}
