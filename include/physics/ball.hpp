#include <array>
class Ball
{
public:
    Ball(double radius = 0, double mass = 0, std::array<double, 3> position = std::array<double, 3>{0, 0, 0},
         std::array<double, 3> speed = std::array<double, 3>{0, 0, 0}, double bounciness = 1);

    double getRadius() const;
    void setRadius(double newRadius);

    double getMass() const;
    void setMass(double newMass);

    double getDensity() const;

    double getBounciness() const;
    void setBounciness(double newBounciness);

    double getVolume() const;

    std::array<double, 3> getPosition() const;
    void setPosition(std::array<double, 3> newPosition);

    std::array<double, 3> getSpeed() const;
    void setSpeed(std::array<double, 3> newSpeed);

    void move();

private:
    double radius_;
    double mass_;
    double density_;
    double bounciness_;
    double volume_;
    std::array<double, 3> position_;
    std::array<double, 3> speed_;

    void calculateVolumeAndDensity();
};