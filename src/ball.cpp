#include "ball.hpp"
#include <cmath>
#include <SFML/OpenGL.hpp>

Ball::Ball(float startX, float startY, float startRadius)
{
    color = sf::Color(255, 105, 180); 
    shape.setRadius(startRadius);
    shape.setFillColor(color);
    shape.setOrigin(startRadius, startRadius);
    shape.setPosition(startX, startY);

    velocity = {200.f, 250.f};
}

void Ball::update(float deltaTime, float windowWidth, float windowHeight,
                  float paddleX, float paddleY, float paddleWidth)
{
    sf::Vector2f pos = shape.getPosition();
    pos += velocity * deltaTime;

    if (pos.x - shape.getRadius() < 0 || pos.x + shape.getRadius() > windowWidth)
        velocity.x = -velocity.x;
    if (pos.y - shape.getRadius() < 0)
        velocity.y = -velocity.y;

    if (pos.y + shape.getRadius() >= paddleY &&
        pos.x >= paddleX && pos.x <= paddleX + paddleWidth)
        velocity.y = -fabs(velocity.y);

    if (pos.y + shape.getRadius() > windowHeight)
        pos = {windowWidth / 2.f, windowHeight / 2.f};

    shape.setPosition(pos);

    trail.push_back(pos);
    if (trail.size() > 15)
        trail.erase(trail.begin());
}

void Ball::draw(sf::RenderWindow& window)
{
    if (!trail.empty())
    {
        sf::Color trailColor = sf::Color(186, 85, 211); 
        float alphaStep = 200.0f / trail.size();
        float alpha = 40.0f;

        for (size_t i = 0; i < trail.size(); ++i)
        {
            sf::CircleShape t(shape.getRadius());
            t.setOrigin(shape.getRadius(), shape.getRadius());
            t.setPosition(trail[i]);

            sf::Color faded = trailColor;
            faded.a = static_cast<sf::Uint8>(alpha);
            t.setFillColor(faded);

            window.draw(t);
            alpha += alphaStep;
        }
    }

    shape.setFillColor(color);
    window.draw(shape);
}

