#include "luke-fabrik/SimpleSkeleton.hpp"

SimpleSkeleton::SimpleSkeleton (const Vec3 &origin) noexcept:
    m_Origin (origin)
{}

void SimpleSkeleton::PushCLJoint (double length, double maxAngle)
{
    Vec3 a, b;

    a = m_Joints.empty () ? m_Origin : m_Joints.back ()->GetB ();
    b = m_Origin + Vec3 (length, 0., 0.);

    m_Joints.push_back (std::make_shared <CLJoint> (length, a, b, maxAngle));
}
