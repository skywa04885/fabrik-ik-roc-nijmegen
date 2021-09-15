#include <iostream>

#include "luke-fabrik/Vec3.hpp"
#include "luke-fabrik/Radians.hpp"

int main (int argc, char **argv)
{
    Vec3 a (0., 1., 0);
    Vec3 b (0., 1., 0.);

    std::cout << Radians::ToDegrees (b.Angle (a)) << std::endl;

    return EXIT_SUCCESS;
};