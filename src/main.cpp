#include <iostream>
#include "../include/physics/physics_engine.hpp"
int main()
{
    PhysicsEngine physics_engine;
    physics_engine.createBall(1, 1, {0, 0});
    physics_engine.createBall(1, 1, {-3, -3});
    physics_engine.createBall(1, 1, {3, 3});

    unsigned long long frame = 0;
    while (true)
    {
        frame++;
        if (frame % 10000 == 0)
            std::cout << physics_engine.getLogs();
        physics_engine.update();
    }
    return 0;
}