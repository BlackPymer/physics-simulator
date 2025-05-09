#include <array>
#include "constants.hpp"
class Ball
{
    /**
     * @brief Controls and calculates the physical ball state
     */
public:
    /**
     *@brief Initialises a new ball

     *@param radius         Radius of the ball
     *@param mass           Mass of the ball
     *@param position       Position of the ball in Physics::DIMENSIONS dimensions. (If 2-d is required use 0 instead of z-dimension)
     *@param speed          Start speed of the ball in Physics::DIMENSIONS dimensions
     *@param bounciness     Bounciness of the ball in touches with other balls, where 1 is not losing speed and 0 stops the ball at all
     */
    Ball(double radius = 0, double mass = 0, std::array<double, Physics::DIMENSIONS> position,
         std::array<double, Physics::DIMENSIONS> speed, double bounciness = 1);

    /**
     * @brief Returns the radius of the ball
     */
    double getRadius() const;
    /**
     * @brief Updates radius of the ball.
     */
    void setRadius(double newRadius);

    double getMass() const;
    /**
     * @brief Updates mass of the ball
     */
    void setMass(double newMass);

    double getDensity() const;

    double getBounciness() const;
    /**
     * @brief Updates bounciness of the ball
     */
    void setBounciness(double newBounciness);

    double getVolume() const;

    std::array<double, 3> getPosition() const;
    void setPosition(std::array<double, 3> newPosition);

    std::array<double, 3> getSpeed() const;
    /**
     * @brief Updates the speed of the ball
     */
    void setSpeed(std::array<double, 3> newSpeed);

    /**
     * @brief Calculates the distance between two points.
     * @param start Start point
     * @param end End point
     * P.S. There is no difference between start and end. It means that u can call `Ball.distance(a,b)` and `Ball.distance(b,a)` and the output will be the same
     */
    static double distance(std::array<double, Physics::DIMENSIONS> start, std::array<double, Physics::DIMENSIONS> end);

    /**
     * @brief Updates the ball's position based on its current speed.
     */
    void move();

    /**
     * @brief Summarize balls together based on inelastic collision and law of conservation of momentum
     */
    Ball operator+(Ball &secondBall) const;

    /**
     * returns true if collides this ball
     * @param secondBall the ball check collision with
     * @param calcuateCollision calculates elastic collision if the balls are in collision
     */
    bool checkCollision(Ball &secondBall, bool calculateCollision = true);

private:
    double radius_;
    double mass_;
    double density_;
    double bounciness_;
    double volume_;
    std::array<double, 3> position_;
    std::array<double, 3> speed_;

    /**
     * @brief Calculates the volume and the density of the ball. Volume is calculated as for a sphere (4/3*PI*r^3). Density is calculated as mass/volume
     */
    void calculateVolumeAndDensity();

    /**
     * @brief Calculates elastic collision
     */
    void collide(Ball &secondBall);
};