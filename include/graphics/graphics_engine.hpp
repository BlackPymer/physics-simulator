#include <SFML/Graphics.hpp>
#include <vector>
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
     * @brief Starts window rendering
     */
    void run();

    /**
     * @brief Updates frame
     * @param balls balls on the scene
     */
    void update(const std::vector<Ball> &balls);

    /**
     * @brief Converts std::array to sf::Vector2f
     */
    static sf::Vector2f fromArrayToVector2F(const std::array<double, 2> &array);

private:
    sf::RenderWindow &window_;
};