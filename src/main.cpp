#include <SFML/Graphics.hpp>
#include <vector>
#include "particle/Particle.h"

int main() {
    const int windowWidth = 1000;
    const int windowHeight = 800;
    const int cellSize = 1;  // Size of each grid cell
    const int rows = windowHeight / cellSize;
    const int cols = windowWidth / cellSize;
    const int simulation_delay = 10;

    bool isMousePressed = false; 
    sf::Vector2i mousePressedPos;

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

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isMousePressed = true;
                    mousePressedPos = sf::Mouse::getPosition(window);  // Store the position of the click
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    isMousePressed = false;  // Mouse button is released
                }
            }
        }


        // Spawn particles at mouse position if it is held down. 
        if (isMousePressed) {
            sf::Vector2i currentMousePos = sf::Mouse::getPosition(window);

            // Calculate mouse grid position
            int mouseGridX = currentMousePos.x / cellSize;
            int mouseGridY = currentMousePos.y / cellSize;
            // Ensure the mouse is in a valid cell
            if (mouseGridX >= 0 && mouseGridX < cols && mouseGridY >= 0 && mouseGridY < rows) {
                // Only spawn a particle if the cell is empty
                if (gridManager.isCellEmpty(mouseGridX, mouseGridY)) {
                    particles.emplace_back(mouseGridX, mouseGridY, cellSize, gridManager);
                }
            }
            // particles.emplace_back(mouseGridX, mouseGridY, cellSize, gridManager);
        }



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
        sf::sleep(sf::milliseconds(simulation_delay));
    }

    return 0;
}


