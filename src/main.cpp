#include <iostream>
#include "../include/physics/physics_engine.hpp"
#include "../include/graphics/graphics_engine.hpp"
#include <SFML/Window.hpp>
PhysicsEngine oneBigAndOneSmall()
{
    PhysicsEngine physicsEngine;
    physicsEngine.createBall(1e4, 1e24, {500, 500});      // Central heavy mass
    physicsEngine.createBall(1e3, 1e3, {0, 0}, {1e3, 0}); // Orbiting satellite

    return physicsEngine;
}

PhysicsEngine threeSmall()
{
    PhysicsEngine physicsEngine;
    physicsEngine.createBall(1e2, 1e3, {0, 1e4});
    physicsEngine.createBall(1e2, 1e3, {1e1, -1e4});
    physicsEngine.createBall(1e2, 1e3, {-1e2, -1e3});

    return physicsEngine;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Physics simulator");
    GraphicsEngine graphicsEngine(window);

    PhysicsEngine physicsEngine(oneBigAndOneSmall());

    while (window.isOpen())
    {
        physicsEngine.update();
        graphicsEngine.update(window, physicsEngine.getSceneObjects());
    }
    return 0;
}