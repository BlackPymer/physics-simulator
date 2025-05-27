#include <iostream>
#include "../include/physics/physics_engine.hpp"
#include "../include/graphics/graphics_engine.hpp"
#include <SFML/Window.hpp>
void oneBigAndOneSmall()
{
    PhysicsEngine physicsEngine;
    physicsEngine.createBall(1e6, 1e24, {0, 0});            // Central heavy mass
    physicsEngine.createBall(1e5, 1e3, {0, 1e8}, {1e3, 0}); // Orbiting satellite

    unsigned long long frame = 0;
    while (true)
    {
        frame++;
        if (frame % 100000 == 0)
            std::cout << physicsEngine.getLogs();
        physicsEngine.update();
    }
}

void threeSmall()
{
    PhysicsEngine physicsEngine;
    physicsEngine.createBall(1e2, 1e3, {0, 1e4});
    physicsEngine.createBall(1e2, 1e3, {1e1, -1e4});
    physicsEngine.createBall(1e2, 1e3, {-1e2, -1e3});

    unsigned long long frame = 0;
    while (true)
    {
        frame++;
        if (frame % 10000 == 0)
            std::cout << physicsEngine.getLogs();
        physicsEngine.update();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Physics simulator");
    GraphicsEngine graphicsEngine(window);

    PhysicsEngine physicsEngine;
    physicsEngine.createBall(1e2, 1e3, {0, 0});
    physicsEngine.createBall(1e2, 1e2, {400, 400});

    while (window.isOpen())
    {
        physicsEngine.update();
        graphicsEngine.update(window, physicsEngine.getSceneObjects());
    }
    return 0;
}