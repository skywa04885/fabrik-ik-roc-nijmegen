#pragma once

#include "luke-fabrik/Vec3.hpp"

class Quaternion
{
protected:
    double      m_Scalar;
    Vec3        m_Imaginary;
public:
    Quaternion (double scalar, const Vec3 &imaginary) noexcept;

    Quaternion (double a, double b, double c, double d) noexcept;

    ~Quaternion (void) noexcept = default;
public:
    inline double SquareSum (void) const noexcept
    {
        return std::pow (GetA (), 2) + std::pow (GetB (), 2) + std::pow (GetC (), 2) + std::pow (GetD (), 2);
    }

    inline double Magnitude (void) const noexcept
    {
        return std::sqrt (SquareSum ());
    }

    inline Quaternion Conjugate (void) const noexcept
    {
        return Quaternion
        (
              GetA (),
            - GetB (),
            - GetC (),
            - GetD ()
        );
    }

    Quaternion Inverse (void) const noexcept;

    Quaternion operator * (const Quaternion &other) const noexcept;

    Quaternion operator ^ (int i) const;

    Quaternion operator + (const Quaternion &quaterion) const noexcept;

    static Quaternion RotationQuaternion (double angle, const Vec3 &axis);
public:
    inline double GetScalar (void) const noexcept
    {
        return m_Scalar;
    }

    inline const Vec3 &GetImaginary (void) const noexcept
    {
        return m_Imaginary;
    }

    inline double GetA (void) const noexcept
    {
        return m_Scalar;
    }

    inline double GetB (void) const noexcept
    {
        return m_Imaginary.GetI ();
    }

    inline double GetC (void) const noexcept
    {
        return m_Imaginary.GetJ ();
    }

    inline double GetD (void) const noexcept
    {
        return m_Imaginary.GetK ();
    }
};

std::ostream &operator << (std::ostream &stream, const Quaternion &quaternion);
