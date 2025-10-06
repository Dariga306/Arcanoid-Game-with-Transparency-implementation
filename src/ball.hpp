#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Ball {
public:
    Ball(float startX, float startY, float startRadius);

    void update(float deltaTime, float windowWidth, float windowHeight,
                float paddleX, float paddleY, float paddleWidth);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    sf::Color color;
    sf::Vector2f velocity;
    std::vector<sf::Vector2f> trail;  
};
