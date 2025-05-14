#include <iostream>
#include "../include/physics/physics_engine.hpp"
int main()
{
    PhysicsEngine physics_engine;
    physics_engine.createBall(1e6, 1e24, {0, 0});            // Central heavy mass
    physics_engine.createBall(1e5, 1e3, {0, 1e8}, {1e3, 0}); // Orbiting satellite

    unsigned long long frame = 0;
    while (true)
    {
        frame++;
        if (frame % 1000000 == 0)
            std::cout << physics_engine.getLogs();
        physics_engine.update();
    }
    return 0;
}