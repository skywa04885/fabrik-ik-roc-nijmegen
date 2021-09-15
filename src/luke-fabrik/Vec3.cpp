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

double Vec3::Magnitude (void) const noexcept
{
    double squareSum = 0.;
    
    squareSum += m_I * m_I;
    squareSum += m_J * m_J;
    squareSum += m_K * m_K;
    
    return std::sqrt (squareSum);
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

std::ostream &operator << (std::ostream &stream, const Vec3 &vec)
{
    stream << vec.GetI () << "i + " << vec.GetJ () << "j + " << vec.GetK () << 'k';
    return stream;
}
