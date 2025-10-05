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
};
