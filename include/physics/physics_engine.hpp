#include "ball.hpp"
#include "constants.hpp"
#include <vector>
#include <array>
#include <string>

class PhysicsEngine
{
public:
    /**
     * @brief Creates new ball and adds it to the scene
     *@param radius         Radius of the ball
     *@param mass           Mass of the ball
     *@param position       Position of the ball in Physics::DIMENSIONS dimensions. (If 2-d is required use 0 instead of z-dimension)
     *@param speed          Start speed of the ball in Physics::DIMENSIONS dimensions
     *@param bounciness     Bounciness of the ball in touches with other balls, where 1 is not losing speed and 0 stops the ball at all
     */
    void createBall(double radius = 0, double mass = 0, std::array<double, Physics::DIMENSIONS> position = {0, 0},
                    std::array<double, Physics::DIMENSIONS> speed = {0, 0}, double bounciness = 1);

    /**
     * @brief Adds ball to the scene
     */
    void createBall(Ball newBall);

    /**
     * @brief Calculates new frame
     */
    void update();

    /**
     * @brief Returns logs about the objects on the scene
     */
    std::string getLogs();

private:
    std::vector<Ball *> objects_;
};