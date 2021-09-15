#include "luke-fabrik/Joint.hpp"

Joint::Joint (double length, const Vec3 &a, const Vec3 &b) noexcept:
    m_Length (length),
    m_A (a),
    m_B (b)
{}

FRJoint::FRJoint (double length, const Vec3 &a, const Vec3 &b) noexcept:
    Joint (length, a, b)
{}

CLJoint::CLJoint (double length, const Vec3 &a, const Vec3 &b, double maxAngle) noexcept:
    Joint (length, a, b),
    m_MaxAngle (maxAngle)
{}
