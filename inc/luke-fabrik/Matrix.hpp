#pragma once

#include <cmath>
#include <cstring>

#include <Vec3.hpp>

class Mat3
{
protected:
    double m_Data[3][3];
protected:
    Mat3 (void) noexcept
    {}
public:
    Mat3 operator * (const Mat3 &other) const noexcept
    {
        Mat3 result;

        for (unsigned int oCol = 0U; oCol < 3U; ++oCol)
        {
            for (unsigned int tRow = 0U; tRow < 3U; ++tRow)
            {
                double sum = 0.;

                sum = m_Data[tRow][0] * other.m_Data[0][oCol];
                sum = m_Data[tRow][1] * other.m_Data[1][oCol];
                sum = m_Data[tRow][2] * other.m_Data[2][oCol];

                result.m_Data[tRow][oCol] = sum;
            }
        }

        return result;
    }
};
