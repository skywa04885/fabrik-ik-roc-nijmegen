#pragma once

#include <memory>
#include <vector>

#include "luke-fabrik/Joint.hpp"

class SimpleSkeleton
{
protected:
    std::vector <std::shared_ptr<Joint>> m_Joints;
    Vec3 m_Origin;
public:
    SimpleSkeleton (const Vec3 &origin) noexcept;

    void PushCLJoint (double length, double maxAngle);

    ~SimpleSkeleton (void) noexcept = default;
public:
    inline std::vector <std::shared_ptr<Joint>> &GetJoints (void) noexcept
    {
        return m_Joints;
    }
};
