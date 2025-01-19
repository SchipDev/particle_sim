#include <SFML/Graphics.hpp>
#include <vector>
#include "particle/Particle.h"

int main() {
    const int windowWidth = 1000;
    const int windowHeight = 800;
    const int cellSize = 20;  // Size of each grid cell
    const int rows = windowHeight / cellSize;
    const int cols = windowWidth / cellSize;

    // Set up Grid Manager
    GridManager gridManager = GridManager(rows, cols, cellSize);

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Particle Grid Simulation");
    sf::Clock clock;

    std::vector<Particle> particles;

    // Initialize particles at random grid positions
    for (int i = 0; i < 15; ++i) {
        int gridX = rand() % cols;
        int gridY = rand() % rows;
        particles.emplace_back(gridX, gridY, cellSize, gridManager);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        // Update particles
        for (auto& particle : particles) {
            particle.updatePosition();
        }

        // Render particles
        window.clear();
        for (const auto& particle : particles) {
            particle.draw(window);
        }
        window.display();

        // Controlling particle speed through simulation time because of movement style
        sf::sleep(sf::milliseconds(50));
    }

    return 0;
}


