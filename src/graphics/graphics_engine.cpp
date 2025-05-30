#include "../../include/graphics/graphics_engine.hpp"
#include <SFML/Graphics.hpp>
#include "../../include/graphics/colors.hpp"
#include "../../include/graphics/window_params.hpp"
#include <optional>
#include <vector>
#include <array>
#include "../../include/physics/ball.hpp"

GraphicsEngine::GraphicsEngine(sf::RenderWindow &window)
{
    window.setFramerateLimit(SimulatorTheme::WindowParams::windowFrameRate);
    window.setSize(sf::Vector2u(SimulatorTheme::WindowParams::windowWidth, SimulatorTheme::WindowParams::windowHeight));
}
sf::Vector2f GraphicsEngine::fromArrayToVector2F(const std::array<double, 2> &array)
{
    return sf::Vector2f(array[0], array[1]);
}
void GraphicsEngine::update(sf::RenderWindow &window, const std::vector<Ball> &balls)
{
    // Check events
    sf::Event event;
    std::optional<sf::Event> optEvent;

    if (window.pollEvent(event))
    {
        optEvent = event;

        if (optEvent->type == sf::Event::Closed)
        {
            window.close();
        }
    }

    // get maxDensity
    double maxDensity = 0;
    for (Ball ball : balls)
        maxDensity = std::max(maxDensity, ball.getDensity());

    // Update objects position
    window.clear(SimulatorTheme::Colors::backgroundColor);

    for (Ball ball : balls)
    {
        sf::CircleShape circle(ball.getRadius());
        circle.setPosition(GraphicsEngine::fromArrayToVector2F(ball.getPosition()));
        circle.setRadius(ball.getRadius());

        sf::Color ballColor = SimulatorTheme::Colors::ballColor;
        // ballColor.a = ball.getDensity() / maxDensity * 255;
        circle.setFillColor(ballColor);

        window.draw(circle);
    }
    window.display();
}