#include "paddle.hpp"

Paddle::Paddle(float x, float y) {
    shape.setSize({100.f, 15.f});
    shape.setFillColor(sf::Color::Blue);
    shape.setOrigin(shape.getSize() / 2.f); // центр платформы
    shape.setPosition(x, y);
}

void Paddle::moveLeft() {
    shape.move(-speed, 0.f);
    if (shape.getPosition().x - shape.getSize().x / 2.f < 0)
        shape.setPosition(shape.getSize().x / 2.f, shape.getPosition().y);
}

void Paddle::moveRight() {
    if (shape.getPosition().x + shape.getSize().x / 2.f < windowWidth)
        shape.move(speed, 0.f);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
