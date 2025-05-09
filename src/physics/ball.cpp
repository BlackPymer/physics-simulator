#include <array>
#include <cmath>
#include "../../include/physics/ball.hpp"
#include "../../include/physics/constants.hpp"

Ball::Ball(double radius, double mass, std::array<double, Physics::DIMENSIONS> position = std::array<double, Physics::DIMENSIONS>{0, 0, 0},
           std::array<double, Physics::DIMENSIONS> startSpeed = std::array<double, Physics::DIMENSIONS>{0, 0, 0}, double bounciness = 1)
{
    radius_ = radius;
    mass_ = mass;
    this->calculateVolumeAndDensity();

    bounciness_ = bounciness;

    position_ = position;
    speed_ = startSpeed;
}

void Ball::calculateVolumeAndDensity()
{
    volume_ = M_PI * 4 / Physics::DIMENSIONS * std::pow(radius_, Physics::DIMENSIONS);
    density_ = mass_ / volume_;
}

double Ball::getRadius() const
{
    return radius_;
}
void Ball::setRadius(double newRadius)
{
    radius_ = newRadius;
    this->calculateVolumeAndDensity();
}

double Ball::getMass() const
{
    return mass_;
}
void Ball::setMass(double newMass)
{
    mass_ = newMass;
    this->calculateVolumeAndDensity();
}

double Ball::getDensity() const { return density_; }

double Ball::getBounciness() const
{
    return bounciness_;
}
void Ball::setBounciness(double newBounciness)
{
    bounciness_ = newBounciness;
}

double Ball::getVolume() const { return volume_; }

std::array<double, Physics::DIMENSIONS> Ball::getSpeed() const
{
    return speed_;
}
void Ball::setSpeed(std::array<double, Physics::DIMENSIONS> newSpeed)
{
    speed_ = newSpeed;
}

void Ball::move()
{
    for (int dimension = 0; dimension < speed_.size(); dimension++)
    {
        position_[dimension] += speed_[dimension];
    }
}

Ball Ball::operator+(Ball &secondBall) const
{
    double newMass = secondBall.mass_ + mass_;

    std::array<double, Physics::DIMENSIONS> newSpeed;
    std::array<double, Physics::DIMENSIONS> newPosition;
    for (int dimension = 0; dimension < Physics::DIMENSIONS; dimension++)
    {
        // average value
        newPosition[dimension] = (position_[dimension] + secondBall.position_[dimension]) / 2;

        // vectorised sum of speeds based on law of conservatiob of momentum
        newSpeed[dimension] = (speed_[dimension] * mass_ + secondBall.speed_[dimension] * secondBall.mass_) / newMass;
    }

    double newVolume = volume_ + secondBall.volume_;

    // 4*PI*R^3 = Volume for 3-d objects
    double newRadius = std::pow(newVolume / (4 * Physics::PI), 1 / Physics::DIMENSIONS);

    // newBounciness is an average of balls bounciness
    double newBounciness = (bounciness_ + secondBall.bounciness_) / 2;

    return Ball(newRadius, newMass, newPosition, newSpeed, newBounciness);
}

double Ball::distance(std::array<double, Physics::DIMENSIONS> start, std::array<double, Physics::DIMENSIONS> end)
{
    double sum = 0;
    for (int dimension = 0; dimension < Physics::DIMENSIONS; dimension++)
        sum += std::sqrt(std::pow(start[dimension], 2) + std::pow(end[dimension], 2));
    return sum;
}

bool Ball::checkCollision(Ball &secondBall, bool calculateCollision = true)
{
    if (distance(secondBall.position_, position_) <= secondBall.radius_ + radius_)
    {
        if (calculateCollision)
            collide(secondBall);
        return true;
    }
    return false;
}

void Ball::collide(Ball &secondBall)
{
    // calculating normal of the collision
    double normalX = position_[0] - secondBall.position_[0];
    double normalY = position_[1] - secondBall.position_[1];
    double normalLength = distance(position_, secondBall.position_);

    // angles to normal
    double cosNormal = normalX / normalLength;
    double sinNormal = normalY / normalLength;

    // speed at normal
    double speed1Normal = speed_[0] * cosNormal + speed_[1] * sinNormal;
    double speed2Normal = secondBall.speed_[0] * cosNormal + secondBall.speed_[1] * sinNormal;
}