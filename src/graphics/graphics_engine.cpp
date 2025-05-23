#include "../../include/graphics/graphics_engine.hpp"
#include <SFML/Graphics.hpp>
#include "../../include/graphics/colors.hpp"
#include "../../include/graphics/window_params.hpp"
#include <optional>

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