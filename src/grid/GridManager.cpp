#include "GridManager.h"
#include "particle/Particle.h"



GridManager::GridManager(int rows, int cols, float cellSize) : rows(rows), cols(cols), cellSize(cellSize) {
    grid.resize(rows, std::vector<bool>(cols, false));   // Initialize the grid to be empty
}

// Simple function to check if a particle is present in a specified cell
bool GridManager::checkCell(int x, int y) {
    // Check the state of the specified cell
    if (x >= 0 && x < cols && y >= 0 && y < rows) {  // Check if specified cell is valid
        return grid[y][x];  // return the boolean value of the specified cell
    }
    // Not the best solution! But if cell is not valid we return true so particle wont move to it
    return true;
}

// Function that checks if a particle can move to a cell and moves it if possible
bool GridManager::tryUpdateParticlePosition(Particle& particle, int newX, int newY) {
    if (!checkCell(newX, newY)) {
        removeParticle(particle);
        addParticle(particle, newX, newY);
        return true;
    }
    return false; 
}

void GridManager::addParticle(Particle& particle, int x, int y) {
    // Add particle to the new position in the grid
    grid[y][x] = true;  // Set the cell as occupied
}

void GridManager::removeParticle(Particle& particle) {
    grid[particle.getGridPosition().y][particle.getGridPosition().x] = false;
}

bool GridManager::isCellEmpty(int x, int y) {
    return !grid[y][x]; // Return the opposite boolean value
}