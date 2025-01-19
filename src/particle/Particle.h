#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle {
private:
    sf::RectangleShape shape;  // The graphical representation of the particle
    sf::Vector2f velocity;  // Velocity of the particle

public:
    Particle(float x, float y, float vx, float vy, float size); // Constructor
    void update(float dt);                          // Update position
    void draw(sf::RenderWindow& window) const;      // Draw the particle
};

#endif // PARTICLE_H