#include <SFML/Graphics.hpp>

/**
 * @brief Controls graphics of the app
 */
class GraphicsEngine
{
public:
    /**
     * @brief Creates (Recreates if exists) new window
     */
    void createWindow();

private:
    sf::RenderWindow window_;
};