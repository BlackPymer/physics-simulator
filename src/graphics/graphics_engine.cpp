#include "../../include/graphics/graphics_engine.hpp"
#include <SFML/Graphics.hpp>
#include "../../include/graphics/colors.hpp"
#include "../../include/graphics/window_params.hpp"
#include <optional>
#include <vector>
#include <array>
#include "../../include/physics/ball.hpp"

GraphicsEngine::GraphicsEngine(sf::RenderWindow &window) : window_(window)
{
    window_.setFramerateLimit(SimulatorTheme::WindowParams::windowFrameRate);
    window_.setSize(sf::Vector2u(SimulatorTheme::WindowParams::windowWidth, SimulatorTheme::WindowParams::windowHeight));
}
void GraphicsEngine::run()
{
    while (window_.isOpen())
    {
        sf::Event event;
        std::optional<sf::Event> optEvent;

        if (window_.pollEvent(event))
        {
            optEvent = event;

            if (optEvent->type == sf::Event::Closed)
            {
                window_.close();
            }
        }
        window_.clear(SimulatorTheme::Colors::backgroundColor);
        window_.display();
    }
}
sf::Vector2f GraphicsEngine::fromArrayToVector2F(const std::array<double, 2> &array)
{
    return sf::Vector2f(array[0], array[1]);
}
void GraphicsEngine::update(const std::vector<Ball> &balls)
{
    for (Ball ball : balls)
    {
        sf::CircleShape circle(ball.getRadius());
        circle.setPosition(GraphicsEngine::fromArrayToVector2F(ball.getPosition()));
    }
}