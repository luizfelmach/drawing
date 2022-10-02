#include <vector>
#include <xd/xd.hpp>

#include "particle.hpp"
#include "vector3d.hpp"

using namespace xd;

int win_width = 600;
int win_height = 480;

Vector3D pos(win_width / 2, win_height / 2, 0);
Vector3D vel(0, -1, 0);
Vector3D acc(0, 0, 0);
float radius = 1;
float color[] = {0.5, 0.1, 0};

Particle p(pos, vel, acc, radius, color);

void draw_particle(Particle p) {
    noStroke();
    fill(vec4(p.color[0], p.color[1], p.color[2], 1.0));
    Vector3D pos = p.get_pos();
    ellipse(pos.x, pos.y, p.radius * 2, p.radius * 2);
}

void random_vel(Particle& p) {
    Vector3D vel = p.get_vel();
    vel.rotateZ(random(-1, 1));
    p.set_vel(vel);
}

void apply_forces(Particle& p) { p.update(); }

void setup() {
    size(win_width, win_height);
    background(vec4(0.3f));
}

void draw() {
    draw_particle(p);
    random_vel(p);
    apply_forces(p);
}

void destroy() {}