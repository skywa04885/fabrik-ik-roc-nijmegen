#include <iostream>
#include <iomanip>

#include "luke-fabrik/Vec3.hpp"
#include "luke-fabrik/Radians.hpp"
#include "luke-fabrik/Quaternion.hpp"
#include "luke-fabrik/FABRIK.hpp"
#include "luke-fabrik/SimpleSkeleton.hpp"

int main (int argc, char **argv)
{
    const FABRIK_Config config = {
        .tolerance = .00000000000000001,
        .iterations = 100,
        .verbose = true
    };

    std::cout << std::fixed << std::setprecision (20) << std::endl;
    std::cout << "FABRIK By Luke Rieff" << std::endl;

    {
        SimpleSkeleton skeleton (Vec3 (0., 0., 0.));
        skeleton.PushCLJoint (10., 45.);
        skeleton.PushCLJoint (10., 45.);
        skeleton.PushCLJoint (10., 45.);
        skeleton.PushCLJoint (10., 45.);
        skeleton.PushCLJoint (10., 45.);
        skeleton.PushCLJoint (10., 45.);
        skeleton.PushCLJoint (10., 45.);

        FABRIK (skeleton.GetJoints ().begin (), skeleton.GetJoints ().end (), Vec3 (10, 10, 10), config);
    }

    return EXIT_SUCCESS;
};