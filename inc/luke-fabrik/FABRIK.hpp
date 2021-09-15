#pragma once

#include <tuple>
#include <vector>
#include <memory>
#include <chrono>

#include "luke-fabrik/Joint.hpp"

struct FABRIK_Config
{
    double          tolerance;
    unsigned int    iterations;
    bool            verbose;
};

typedef std::tuple<double, unsigned int> FABRIK_RetType;

double FABRIK_Forward (std::vector <std::shared_ptr<Joint>>::iterator start, std::vector <std::shared_ptr<Joint>>::iterator end, const Vec3 &target);

void FABRIK_Backward (std::vector <std::shared_ptr<Joint>>::iterator start, std::vector <std::shared_ptr<Joint>>::iterator end, const Vec3 &target);

FABRIK_RetType FABRIK (std::vector <std::shared_ptr<Joint>>::iterator start, std::vector <std::shared_ptr<Joint>>::iterator end, const Vec3 &target, const FABRIK_Config &config);
