#include <array>
#include <cmath>
#include "../../include/physics/ball.hpp"

Ball::Ball(double radius = 0, double mass = 0, std::array<double, 3> position = std::array<double, 3>{0, 0, 0},
           std::array<double, 3> startSpeed = std::array<double, 3>{0, 0, 0}, double bounciness = 1)
{
    /** *
     *Initialises a new ball
     *@tparam radius Radius of the ball
     *@tparam mass Mass of the ball
     *@tparam positiion Position of the ball in 3 dimensions. (If 2-d is required use 0 instead of z-dimension)
     *@tparam speed Start speed of the ball in 3 dimensions
     *@tparam bounciness Bounciness of the ball in touches with other balls, where 1 is not losing speed and 0 stops the ball at all
     **/
    radius_ = radius;
    mass_ = mass;
    density_ = mass_ / (M_PI * std::pow(radius, 2));
    bounciness_ = bounciness;

    position_ = position;
    speed_ = startSpeed;
}