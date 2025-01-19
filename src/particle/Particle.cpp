#include "Particle.h"

Particle::Particle(int gridX, int gridY, float cellSize, GridManager& manager)
    : gridPosition(gridX, gridY), size(cellSize), gridManager(manager) {
    shape.setSize(sf::Vector2f(cellSize, cellSize));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(gridX * cellSize, gridY * cellSize);
}


void Particle::updatePosition() {
    // This is a simple physics sim so well start trying to fall straight down
    if (gridManager.tryUpdateParticlePosition(*this, getGridPosition().x, getGridPosition().y+1)) {
        setGridPosition(getGridPosition().x, getGridPosition().y+1);
    }
    // Next try to fall to the right
    else if (gridManager.tryUpdateParticlePosition(*this, getGridPosition().x+1, getGridPosition().y+1)) {
        setGridPosition(getGridPosition().x+1, getGridPosition().y+1);
    }
    // Last try to fall to the left
    else if (gridManager.tryUpdateParticlePosition(*this, getGridPosition().x-1, getGridPosition().y+1)) {
        setGridPosition(getGridPosition().x-1, getGridPosition().y+1);
    }

    // If none of those work, we stay in the same plaec
    
}

void Particle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2i Particle::getGridPosition() const {
    return gridPosition;
}

void Particle::setGridPosition(int x, int y) {
    gridPosition = sf::Vector2i(x, y);
    shape.setPosition(x * size, y * size);
}

