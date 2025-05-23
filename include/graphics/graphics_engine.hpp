#include <SFML/Graphics.hpp>

/**
 * @brief Controls graphics of the app
 */
class GraphicsEngine
{
public:
    /**
     * @brief Initialises Engine with an existing window
     */
    GraphicsEngine(sf::RenderWindow &window);

    /**
     * @brief starts window rendering
     */
    void run();

private:
    sf::RenderWindow &window_;
};