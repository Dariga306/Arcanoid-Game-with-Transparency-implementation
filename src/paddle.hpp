#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
private:
    sf::RectangleShape shape;
    float speed = 8.f;
    const float windowWidth = 800.f;

public:
    Paddle(float x, float y);
    void moveLeft();
    void moveRight();
    void draw(sf::RenderWindow& window);

    float getX() const { return shape.getPosition().x; }
    float getY() const { return shape.getPosition().y; }
    float getWidth() const { return shape.getSize().x; }
    float getHeight() const { return shape.getSize().y; }
};
