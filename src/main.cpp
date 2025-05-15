#include <iostream>
#include "../include/physics/physics_engine.hpp"

void oneBigAndOneSmall()
{
    PhysicsEngine physics_engine;
    physics_engine.createBall(1e6, 1e24, {0, 0});            // Central heavy mass
    physics_engine.createBall(1e5, 1e3, {0, 1e8}, {1e3, 0}); // Orbiting satellite

    unsigned long long frame = 0;
    while (true)
    {
        frame++;
        if (frame % 100000 == 0)
            std::cout << physics_engine.getLogs();
        physics_engine.update();
    }
}

void threeSmall()
{
    PhysicsEngine physics_engine;
    physics_engine.createBall(1e2, 1e3, {0, 1e4});
    physics_engine.createBall(1e2, 1e3, {1e1, -1e4});
    physics_engine.createBall(1e2, 1e3, {-1e2, -1e3});

    unsigned long long frame = 0;
    while (true)
    {
        frame++;
        if (frame % 10000 == 0)
            std::cout << physics_engine.getLogs();
        physics_engine.update();
    }
}

int main()
{
    threeSmall();
    return 0;
}