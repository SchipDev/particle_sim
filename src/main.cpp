#include <SFML/Graphics.hpp>
#include <vector>
#include "particle/Particle.h" // Include the header file for the Particle class

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particle Simulator");
    std::vector<Particle> particles;

    // Add some particles
    particles.emplace_back(100.f, 100.f, 50.f, 50.f, 10.f);
    particles.emplace_back(200.f, 150.f, -30.f, 40.f, 5.f);
    particles.emplace_back(200.f, 10.f, 30.f, -40.f, 30.f);
    particles.emplace_back(200.f, 300.f, -30.f, 40.f, 3.f);
    particles.emplace_back(200.f, 25.f, 30.f,-40.f, 15.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        for (auto& particle : particles) {
            particle.update(dt); // Update each particle
        }

        window.clear();
        for (const auto& particle : particles) {
            particle.draw(window); // Draw each particle
        }
        window.display();
    }

    return 0;
}

