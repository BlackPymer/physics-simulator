#include <array>
#include <cmath>
#include "../../include/physics/ball.hpp"

Ball::Ball(double radius = 0, double mass = 0, std::array<double, 3> position = std::array<double, 3>{0, 0, 0},
           std::array<double, 3> startSpeed = std::array<double, 3>{0, 0, 0}, double bounciness = 1)
{
    /**
     *Initialises a new ball
     *@tparam radius Radius of the ball
     *@tparam mass Mass of the ball
     *@tparam positiion Position of the ball in 3 dimensions. (If 2-d is required use 0 instead of z-dimension)
     *@tparam speed Start speed of the ball in 3 dimensions
     *@tparam bounciness Bounciness of the ball in touches with other balls, where 1 is not losing speed and 0 stops the ball at all
     */
    radius_ = radius;
    mass_ = mass;
    this->calculateVolumeAndDensity();

    bounciness_ = bounciness;

    position_ = position;
    speed_ = startSpeed;
}

void Ball::calculateVolumeAndDensity()
{
    /**
     *Calculates the volume and the density of the ball. Volume is calculated as for a sphere (4/3*PI*r^3). Density is calculated as mass/volume
     */
    volume_ = M_PI * 4 / 3 * std::pow(radius_, 3);
    density_ = mass_ / volume_;
}

double Ball::getRadius() const
{
    /**
     * Returns the radius of the ball
     */
    return radius_;
}
void Ball::setRadius(double newRadius)
{
    /**
     *Updates radius of the ball.
     */
    radius_ = newRadius;
    this->calculateVolumeAndDensity();
}

double Ball::getMass() const
{
    /**
     * Returns the mass of the ball
     */
    return mass_;
}
void Ball::setMass(double newMass)
{
    /**
     * Updates mass of the ball
     */
    mass_ = newMass;
    this->calculateVolumeAndDensity();
}
