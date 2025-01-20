#include "StaticParticle.h"


// This is a static particle class, thes particles dont move and only serve as collision for moving particles. 

StaticParticle::StaticParticle(int gridX, int gridY, float cellSize, GridManager& manager) 
: gridPosition(gridX, gridY), size(cellSize), gridManager(manager) {
    shape.setSize(sf::Vector2f(cellSize, cellSize));
    shape.setFillColor(sf::Color::Blue); 
    shape.setPosition(gridX * cellSize, gridY * cellSize);
    gridManager.addStaticParticle(*this, gridPosition.x, gridPosition.y); 
}

void StaticParticle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2i StaticParticle::getGridPosition() const {
    return gridPosition;
}
