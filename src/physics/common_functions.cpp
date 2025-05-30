#include <string>
#include <array>
#include "../../include/physics/constants.hpp"
namespace Utils
{
    inline std::string convertArrayToString(std::array<double, Physics::DIMENSIONS> array)
    {
        std::string result = "{ ";
        for (double value : array)
            result += std::to_string(value) + ", ";
        result.pop_back();
        result.pop_back();
        result += " }";
        return result;
    }
}