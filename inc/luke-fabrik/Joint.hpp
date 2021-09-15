#pragma once

#include "luke-fabrik/Vec3.hpp"

/// The base joint class.
class Joint
{
protected:
    double      m_Length;

    Vec3        m_A,
                m_B;
protected:
    Joint (double length, const Vec3 &a, const Vec3 &b) noexcept;
    
    ~Joint (void) noexcept = default;
public:
    /// The FABRIK update method, will perform a single joint step in the forward phase.
    virtual inline void FABRIK_ForwardUpdate (const Vec3 &from) = 0;

    /// Forward phase operator overload.
    inline void operator >> (const Vec3 &from) noexcept
    {
        FABRIK_ForwardUpdate (from);
    }

    /// Backward phase operator overload.
    inline void operator << (const Vec3 &from) noexcept
    {
        FABRIK_BackwardUpdate (from);
    }

    /// The FABRIK update method, will perform a single joint step in the backward phase.
    virtual inline void FABRIK_BackwardUpdate (const Vec3 &from) = 0;
public:
    inline const Vec3 &GetA (void) const noexcept
    {
        return m_A;
    }

    inline const Vec3 &GetB (void) const noexcept
    {
        return m_B;
    }
};

/// This joint will be free, it can take any rotation.
class FRJoint : public Joint
{
protected:
public:
    FRJoint (double length, const Vec3 &a, const Vec3 &b) noexcept;

    ~FRJoint (void) noexcept = default;
public:
    /// The FABRIK update method, will perform a single joint step in the forward phase.
    virtual inline void FABRIK_ForwardUpdate (const Vec3 &from)
    {
        // Calculates te direction vector for te line.
        const Vec3 DIRECTION_VECTOR = (m_B - from).Normalize ();

        // Sets thew new point B to the vector on the given line
        //  and A to the point we're calculating from.
        m_B = (DIRECTION_VECTOR * m_Length) + from;
        m_A = from;
    }

    /// The FABRIK update method, will perform a single joint step in the backward phase.
    virtual inline void FABRIK_BackwardUpdate (const Vec3 &from)
    {
        // Calculates the direction vector for the line.
        const Vec3 DIRECTION_VECTOR = (m_A - from).Normalize ();

        // Sets the new A to a vector on the given line, and B
        //  to the point we're calculating from.
        m_A = (DIRECTION_VECTOR * m_Length) + from;
        m_B = from;
    }
};

/// This joint has rotational limits given by a cone of the max angle.
class CLJoint : public Joint
{
protected:
    double m_MaxAngle;
public:
    CLJoint (double length, const Vec3 &a, const Vec3 &b, double maxAngle) noexcept;

    ~CLJoint (void) noexcept = default;
public:
    /// Calculates the length of the cone.
    inline double ConeLength (void) const noexcept
    {
        return std::cos (m_MaxAngle) * m_Length;
    }
    
    /// The FABRIK update method, will perform a single joint step in the forward phase.
    virtual inline void FABRIK_ForwardUpdate (const Vec3 &from)
    {
        // Calculates the normal of the from.
        const Vec3 FROM_DIRECTION = from.Normalize ();

        // Calculates te direction vector for te line.
        Vec3 directionVector = (m_B - from).Normalize ();

        // Limits the direction vector to an cone.
        const double ANGLE = directionVector.Angle (FROM_DIRECTION);
        if (ANGLE > m_MaxAngle)
        {
            const double ANGLE_DIFFERENCE = m_MaxAngle / ANGLE;
            const Vec3 CONE_DIRECTION = FROM_DIRECTION * m_Length;
            directionVector = Vec3::SLERP (CONE_DIRECTION, directionVector, ANGLE_DIFFERENCE);
        }

        // Sets thew new point B to the vector on the given line
        //  and A to the point we're calculating from.
        m_B = (directionVector * m_Length) + from;
        m_A = from;
    }

    /// The FABRIK update method, will perform a single joint step in the backward phase.
    virtual inline void FABRIK_BackwardUpdate (const Vec3 &from)
    {
        // Calculates the direction vector for the line.
        const Vec3 DIRECTION_VECTOR = (m_A - from).Normalize ();

        // Sets the new A to a vector on the given line, and B
        //  to the point we're calculating from.
        m_A = (DIRECTION_VECTOR * m_Length) + from;
        m_B = from;
    }
};
