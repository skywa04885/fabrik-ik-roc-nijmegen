#include <cmath>
#include <iostream>

#pragma once

class Vec3
{
protected:
    double m_I, m_J, m_K;
public:
    static const Vec3 X;
    static const Vec3 Y;
    static const Vec3 Z;
public:
    inline double SquareSum (void) const noexcept
    {
        return std::pow (GetI (), 2) + std::pow (GetJ (), 2) + std::pow (GetK (), 2);
    }

    inline double Magnitude (void) const noexcept
    {
        return std::sqrt (SquareSum ());
    }
public:
    Vec3 (void) noexcept = default;

    Vec3 (double i, double j, double k) noexcept;

    Vec3 (const Vec3 &copy) noexcept;

    double DistanceTo (const Vec3 &other) const noexcept;

    Vec3 Normalize (void) const noexcept;

    Vec3 operator - (const Vec3 &other) const noexcept;

    Vec3 operator + (const Vec3 &other) const noexcept;

    Vec3 operator * (const Vec3 &other) const noexcept;

    Vec3 operator * (double other) const noexcept;

    Vec3 operator / (double other) const noexcept;

    double Dot (const Vec3 &other) const noexcept;

    double Angle (const Vec3 &other) const noexcept;

    static Vec3 LERP (const Vec3 &a, const Vec3 &b, double t) noexcept;

    static Vec3 SLERP (const Vec3 &a, const Vec3 &b, double t) noexcept;

    ~Vec3 (void) noexcept = default;
public:
    inline double GetI (void) const noexcept
    {
        return m_I;
    }
    
    inline double GetJ (void) const noexcept
    {
        return m_J;
    }

    inline double GetK (void) const noexcept
    {
        return m_K;
    }
};

std::ostream &operator << (std::ostream &stream, const Vec3 &vec);
