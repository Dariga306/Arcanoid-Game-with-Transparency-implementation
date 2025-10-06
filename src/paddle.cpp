#include "paddle.hpp"

Paddle::Paddle(float x, float y) {
    shape.setSize({100.f, 15.f});
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(x - shape.getSize().x / 2.f, y);
}

void Paddle::moveLeft() {
    shape.move(-speed, 0.f);
    if (shape.getPosition().x < 0)
        shape.setPosition(0, shape.getPosition().y);
}

void Paddle::moveRight() {
    if (shape.getPosition().x + shape.getSize().x < windowWidth)
        shape.move(speed, 0.f);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
