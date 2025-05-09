#include <iostream>
#include "../include/physics/ball.hpp"
int main()
{
    Ball ball(15, 17);
    Ball ball2(15, 17);
    ball.checkCollision(ball2);
    return 0;
}