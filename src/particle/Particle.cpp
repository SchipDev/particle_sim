#include "particle/Particle.h"

// Constructor definition
Particle::Particle(float x, float y, float vx, float vy, float size) {
    shape = sf::RectangleShape(sf::Vector2f(size, size));  // Create a circle with a radius of 5
    shape.setPosition(x, y);     // Set initial position
    velocity = sf::Vector2f(vx, vy); // Set initial velocity
}

// Update the particle's position based on its velocity
void Particle::update(float dt) {
    shape.move(velocity * dt);
}

// Draw the particle on the provided window
void Particle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
