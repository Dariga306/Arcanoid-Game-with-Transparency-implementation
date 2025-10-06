#include <SFML/Graphics.hpp>
#include "paddle.hpp"
#include "ball.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid — мяч и комета");
    window.setFramerateLimit(60);

    Paddle paddle(400.f, 550.f);
    Ball ball(400.f, 300.f, 10.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            paddle.moveLeft();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            paddle.moveRight();

        float deltaTime = clock.restart().asSeconds();

        
        ball.update(deltaTime, window.getSize().x, window.getSize().y,
                    paddle.getX(), paddle.getY(), paddle.getWidth());


        window.clear(sf::Color::Black);
        paddle.draw(window);
        ball.draw(window);
        window.display();
    }

    return 0;
}
