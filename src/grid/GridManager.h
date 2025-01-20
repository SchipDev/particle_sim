#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include <SFML/Graphics.hpp>

class Particle;
class StaticParticle;

class GridManager {

private:
    int rows; 
    int cols;
    float cellSize;
    std::vector<std::vector<bool>> grid;    // Boolean vector for storing particle positions
    void addParticle(Particle& particle, int x, int y);
    void removeParticle(Particle& particle);

public:
    GridManager(int rows, int cols, float cellSize);
    bool checkCell(int x, int y);
    void addStaticParticle(StaticParticle& particle, int x, int y);
    bool tryUpdateParticlePosition(Particle& particle, int newX, int newY);
    bool isCellEmpty(int x, int y);
    void printGrid() const;


};

#endif // GRIDMANAGER_H