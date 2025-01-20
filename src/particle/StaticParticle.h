#ifndef STATICPARTICLE_H
#define STATICPARTICLE_H

#include <SFML/Graphics.hpp>
#include "grid/GridManager.h"

class StaticParticle {
private:
    sf::Vector2i gridPosition;  // Grid position (row, column)
    sf::RectangleShape shape;   // Visual representation
    float size;                 // Size of the particle
    GridManager& gridManager;   // Refernence to the simulations grid manager

public:
    StaticParticle(int gridX, int gridY, float cellSize, GridManager& manager);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2i getGridPosition() const;
};

#endif // STATICPARTICLE_H