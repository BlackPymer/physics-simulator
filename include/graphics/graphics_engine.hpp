#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../physics/ball.hpp"
/**
 * @brief Controls graphics of the app
 */
class GraphicsEngine
{
public:
    /**
     * @brief Initialises Engine with an existing window. Changes window params as required
     */
    GraphicsEngine(sf::RenderWindow &window);

    /**
     * @brief Updates frame of the window: position of the balls, events.
     * @param balls objects on the scene
     */
    void update(sf::RenderWindow &window, const std::vector<Ball> &balls);

    /**
     * @brief Converts std::array to sf::Vector2f
     */
    static sf::Vector2f fromArrayToVector2F(const std::array<double, 2> &array);
};