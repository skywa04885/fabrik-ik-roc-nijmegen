#include "luke-fabrik/Vec3.hpp"

const Vec3 Vec3::X (1., 0., 0.);
const Vec3 Vec3::Y (0., 1., 0.);
const Vec3 Vec3::Z (0., 0., 1.);

Vec3::Vec3 (double i, double j, double k) noexcept:
    m_I (i),
    m_J (j),
    m_K (k)
{}

Vec3::Vec3 (const Vec3 &copy) noexcept:
    m_I (copy.m_I),
    m_J (copy.m_J),
    m_K (copy.m_K)
{}

double Vec3::DistanceTo (const Vec3 &other) const noexcept {
    return std::sqrt (
        std::pow (GetI () - other.GetI (), 2) + 
        std::pow (GetJ () - other.GetJ (), 2) +
        std::pow (GetK () - other.GetK (), 2)  
    );
}

Vec3 Vec3::Normalize (void) const noexcept
{
    const double MAG = Magnitude ();
    return Vec3
    (
        m_I / MAG,
        m_J / MAG,
        m_K / MAG  
    );
}

Vec3 Vec3::operator - (const Vec3 &other) const noexcept
{
    return Vec3
    (
        m_I - other.m_I,
        m_J - other.m_J,
        m_K - other.m_K  
    );
}

Vec3 Vec3::operator + (const Vec3 &other) const noexcept
{
    return Vec3
    (
        m_I + other.m_I,
        m_J + other.m_J,
        m_K + other.m_K  
    );
}

Vec3 Vec3::operator * (const Vec3 &other) const noexcept
{
    return Vec3
    (
        m_J * other.m_K - m_K * other.m_J,
        m_K * other.m_I - m_I * other.m_K,
        m_I * other.m_J - m_J * other.m_I  
    );
}

Vec3 Vec3::operator * (double other) const noexcept
{
    return Vec3
    (
        m_I * other,
        m_J * other,
        m_K * other  
    );
}

Vec3 Vec3::operator / (double other) const noexcept
{
    return Vec3
    (
        m_I / other,
        m_J / other,
        m_K / other
    );
}

double Vec3::Dot (const Vec3 &other) const noexcept
{
    return m_I * other.m_I + m_J * other.m_J + m_K * other.m_K;
}

double Vec3::Angle (const Vec3 &other) const noexcept
{
    return std::acos (this->Dot (other) / (Magnitude () * other.Magnitude ()));
}

Vec3 Vec3::LERP (const Vec3 &a, const Vec3 &b, double t) noexcept
{
    return a + ((b - a) * t);
}

Vec3 Vec3::SLERP (const Vec3 &a, const Vec3 &b, double t) noexcept
{
    const double ANGLE = a.Angle (b);
    return  (a * (std::sin (1. - t) * ANGLE) / std::sin (ANGLE)) +
            (b * (std::sin (t * ANGLE) / std::sin (ANGLE)) * b);
}

std::ostream &operator << (std::ostream &stream, const Vec3 &vec)
{
    stream << vec.GetI () << "i + " << vec.GetJ () << "j + " << vec.GetK () << 'k';
    return stream;
}
