#include "luke-fabrik/Quaternion.hpp"

Quaternion::Quaternion (double scalar, const Vec3 &imaginary) noexcept:
    m_Scalar (scalar),
    m_Imaginary (imaginary)
{}

Quaternion::Quaternion (double a, double b, double c, double d) noexcept:
    m_Scalar (a),
    m_Imaginary (b, c, d)
{}

Quaternion Quaternion::Inverse (void) const noexcept
{
    const double SQUARE_SUM = SquareSum ();
    const Quaternion CONJUGATE = Conjugate ();

    return Quaternion
    (
        CONJUGATE.GetA () / SQUARE_SUM,
        CONJUGATE.GetB () / SQUARE_SUM,
        CONJUGATE.GetC () / SQUARE_SUM,
        CONJUGATE.GetD () / SQUARE_SUM
    );   
}

Quaternion Quaternion::operator * (const Quaternion &other) const noexcept
{
    return Quaternion
    (
        GetA () * other.GetA () - GetB () * other.GetB () - GetC () * other.GetC () - GetD () * other.GetD (),
        GetA () * other.GetB () + GetB () * other.GetA () + GetC () * other.GetD () - GetD () * other.GetC (),
        GetA () * other.GetC () - GetB () * other.GetD () + GetC () * other.GetA () + GetD () * other.GetB (),
        GetA () * other.GetD () + GetB () * other.GetC () - GetC () * other.GetB () + GetD () * other.GetA ()
    );
}

Quaternion Quaternion::operator ^ (int i) const
{
    if (i == -1)
    {
        return Inverse ();
    }

    throw std::runtime_error ("Invalid power for quaterion");
}

Quaternion Quaternion::operator + (const Quaternion &quaterion) const noexcept
{
    return Quaternion
    (
        GetA () + quaterion.GetA (),
        GetB () + quaterion.GetB (),
        GetC () + quaterion.GetC (),
        GetD () + quaterion.GetD ()
    );
}

Quaternion Quaternion::RotationQuaternion (double angle, const Vec3 &axis)
{
    angle /= 2.;

    return Quaternion
    (
        std::cos (angle),
        std::sin (angle) * axis.GetI (),
        std::sin (angle) * axis.GetJ (),
        std::sin (angle) * axis.GetK ()
    );
}

std::ostream &operator << (std::ostream &stream, const Quaternion &quaternion)
{
    stream << quaternion.GetA () << " + "
        << quaternion.GetB () << "i + "
        << quaternion.GetC () << "j + "
        << quaternion.GetD () << "k";
    return stream;
}
