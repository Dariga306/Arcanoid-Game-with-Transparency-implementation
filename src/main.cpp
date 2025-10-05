#include <SFML/Graphics.hpp>
#include "paddle.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid — только платформа");
    window.setFramerateLimit(60);

    Paddle paddle(400.f, 550.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Управление стрелками
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            paddle.moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            paddle.moveRight();

        window.clear(sf::Color::Black);
        paddle.draw(window);
        window.display();
    }

    return 0;
}
