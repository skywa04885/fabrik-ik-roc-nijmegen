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
    Vec3 (double i, double j, double k) noexcept;

    Vec3 (const Vec3 &copy) noexcept;

    double Magnitude (void) const noexcept;

    Vec3 Normalize (void) const noexcept;

    Vec3 operator - (const Vec3 &other) const noexcept;

    Vec3 operator + (const Vec3 &other) const noexcept;

    Vec3 operator * (const Vec3 &other) const noexcept;

    Vec3 operator * (double other) const noexcept;

    Vec3 operator / (double other) const noexcept;

    double Dot (const Vec3 &other) const noexcept;

    double Angle (const Vec3 &other) const noexcept;

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
