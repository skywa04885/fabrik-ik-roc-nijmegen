#pragma once

#include <cmath>

class Radians
{
public:
    static inline double ToDegrees (double radians) noexcept
    {
        return (radians / M_PI) * 180.;
    }

    static inline double FromDegrees (double degrees) noexcept
    {
        return (degrees / 180.) * M_PI;
    }
};
