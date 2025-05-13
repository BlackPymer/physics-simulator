#include "../../include/physics/physics_engine.hpp"
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include "common_functions.cpp"

void PhysicsEngine::createBall(Ball newBall)
{
    Ball *ball = new Ball(newBall);
    objects_.push_back(ball);
}

void PhysicsEngine::createBall(double radius, double mass, std::array<double, Physics::DIMENSIONS> position,
                               std::array<double, Physics::DIMENSIONS> speed, double bounciness)
{
    Ball *ball = new Ball(radius, mass, position, speed, bounciness);
    objects_.push_back(ball);
}

void PhysicsEngine::update()
{
    // calculate force
    for (unsigned long firstBallIndex = 0; firstBallIndex < objects_.size() - 1; firstBallIndex++)
    {
        Ball *firstBall = objects_[firstBallIndex];
        std::array<double, Physics::DIMENSIONS> position1 = firstBall->getPosition();
        double mass1 = firstBall->getMass();

        for (unsigned long secondBallIndex = firstBallIndex + 1; secondBallIndex < objects_.size(); secondBallIndex++)
        {
            Ball *secondBall = objects_[secondBallIndex];
            std::array<double, Physics::DIMENSIONS> position2 = secondBall->getPosition();
            double mass2 = secondBall->getMass();

            double distance = Ball::distance(position1, position2);
            double force = Physics::GRAVITY_CONSTANT * mass1 * mass2 / std::pow(distance, 2) * Physics::SIMULATION_SPEED;

            double xForce = force * std::abs(position1[0] - position2[0]) / distance;
            double yForce = force * std::abs(position1[1] - position2[1]) / distance;

            std::array<double, Physics::DIMENSIONS> newSpeed1 = firstBall->getSpeed();
            newSpeed1[0] += xForce / mass1;
            newSpeed1[1] += yForce / mass1;
            firstBall->setSpeed(newSpeed1);

            std::array<double, Physics::DIMENSIONS> newSpeed2 = secondBall->getSpeed();
            newSpeed2[0] += xForce / mass2;
            newSpeed2[1] += yForce / mass2;
            secondBall->setSpeed(newSpeed2);
        }
        firstBall->move();
    }
    objects_.back()->move();

    // calculate collisions
    for (unsigned long firstBallIndex = 0; firstBallIndex < objects_.size() - 1; firstBallIndex++)
    {
        for (unsigned long secondBallIndex = firstBallIndex + 1; secondBallIndex < objects_.size(); secondBallIndex++)
        {
            objects_[firstBallIndex]->checkCollision(*objects_[secondBallIndex]);
        }
    }
}

std::string PhysicsEngine::getLogs()
{
    std::string logs = "";
    for (unsigned long ballIndex = 0; ballIndex < objects_.size(); ballIndex++)
    {
        logs += "Ball " + std::to_string(ballIndex + 1);
        logs += "\tspeed: " + Utils::convertArrayToString(objects_[ballIndex]->getSpeed());
        logs += "\tposition: " + Utils::convertArrayToString(objects_[ballIndex]->getPosition()) + "\n";
    }
    return logs + '\n';
}