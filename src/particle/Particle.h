#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include "grid/GridManager.h"

class Particle {
private:
    sf::Vector2i gridPosition;  // Grid position (row, column)
    sf::RectangleShape shape;   // Visual representation
    float size;                 // Size of the particle
    GridManager& gridManager;   // Refernence to the simulations grid manager

public:
    Particle(int gridX, int gridY, float cellSize, GridManager& manager);
    void updatePosition();
    void draw(sf::RenderWindow& window) const;

    sf::Vector2i getGridPosition() const;
    void setGridPosition(int x, int y);
};

#endif // PARTICLE_H
