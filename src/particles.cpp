#include <vector>
#include <xd/xd.hpp>

#include "particle.hpp"
#include "vector3d.hpp"

using namespace xd;

int win_width = 600;
int win_height = 480;

vector<Particle> particles;
int qtd_particles = 30;

void init_particles() {
    for (int i = 0; i < qtd_particles; i++) {
        Vector3D pos(random(30, win_width - 30), random(30, win_height - 30),
                     0);
        Vector3D vel(random(-3, 3), random(-3, 3), 0);
        Vector3D acc(0, 0, 0);

        int radius = random(2, 8);
        float color[3] = {random(0, 1), random(0, 1), random(0, 1)};

        Particle p(pos, vel, acc, radius, color);
        particles.push_back(p);
    }
}

void draw_particle(Particle p) {
    noStroke();
    fill(vec4(p.color[0], p.color[1], p.color[2], 1.0));
    Vector3D pos = p.get_pos();
    ellipse(pos.x, pos.y, p.radius * 2, p.radius * 2);
}

void apply_forces(Particle& p) { p.update(); }

void draw_lines(Particle p) {
    Vector3D pos1 = p.get_pos();
    for (auto particle : particles) {
        Vector3D pos2 = particle.get_pos();
        float distance = pos1.distance(pos2);

        if (distance <= 100) {
            stroke(vec4(p.color[0], p.color[1], p.color[2], 1));
            line(pos1.x, pos1.y, pos2.x, pos2.y);
        }
    }
}

void check_collision(Particle& p) {
    Vector3D pos = p.get_pos();
    Vector3D vel = p.get_vel();

    if (pos.x >= win_width - p.radius) {
        vel.x *= -1;
    }
    if (pos.x <= p.radius) {
        vel.x *= -1;
    }
    if (pos.y >= win_height - p.radius) {
        vel.y *= -1;
    }
    if (pos.y <= p.radius) {
        vel.y *= -1;
    }

    p.set_vel(vel);
}

void setup() {
    size(win_width, win_height);
    init_particles();
}

void draw() {
    background(vec4(0.3f));
    for (auto& p : particles) {
        draw_particle(p);
        apply_forces(p);
        check_collision(p);
        draw_lines(p);
    }
}

void destroy() {}