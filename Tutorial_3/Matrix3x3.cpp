#define _USE_MATH_DEFINES     // must be defined before any #include  
#include "Matrix3x3.h"

#include <cassert>
#include <cmath>
#include <iostream>

Matrix3x3::Matrix3x3() noexcept
{
    fRows[0] = Vector3D(    1.0f, 0   , 0       );
    fRows[1] = Vector3D(    0   , 1.0f, 0       );
    fRows[2] = Vector3D(    0   , 0   , 1.0f    );
}

Matrix3x3::Matrix3x3(const Vector3D &aRow1, const Vector3D &aRow2, const Vector3D &aRow3) noexcept : 
    fRows{aRow1, aRow2, aRow3}
{}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept
{
    return Matrix3x3(fRows[0] * aScalar, fRows[1] * aScalar, fRows[2] * aScalar);
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 &aOther) const noexcept
{
    return Matrix3x3(fRows[0] + aOther.fRows[0], fRows[1] + aOther.fRows[1], fRows[2] + aOther.fRows[2]);
}

Vector3D Matrix3x3::operator*(const Vector3D &aVector) const noexcept
{
    return Vector3D(aVector.x() * fRows[0].x(), aVector.y() * fRows[1].y(), aVector.w() * fRows[2].w());
}

Matrix3x3 Matrix3x3::scale(const float aX, const float aY)
{   
    // @todo: revisit for correct syntax, check correctness of idea
    return Matrix3x3(
            Vector3D(   1.0f * aX, 0        , 0    ), 
            Vector3D(   0        , 1.0f * aY, 0    ),
            Vector3D(   0        , 0        , 1.0f )
        );
}

Matrix3x3 Matrix3x3::translate(const float aX, const float aY)
{
    return Matrix3x3(
            Vector3D(   1.0f, 0   , aX     ), 
            Vector3D(   0   , 1.0f, aY     ),
            Vector3D(   0   , 0   , 1.0f   )
        );
}

Matrix3x3 Matrix3x3::rotate(const float aAngleInDegree)
{
    return Matrix3x3(
            Vector3D(   cos(aAngleInDegree), -sin(aAngleInDegree), 0    ), 
            Vector3D(   sin(aAngleInDegree), cos(aAngleInDegree) , 0    ),
            Vector3D(   0                  , 0                   , 1.0f )
        );
}

const Vector3D Matrix3x3::row(size_t aRowIndex) const
{
    assert (aRowIndex < 3);
    return fRows[aRowIndex];
}

const Vector3D Matrix3x3::column(size_t aColumnIndex) const
{
    assert (aColumnIndex < 3);
    switch (aColumnIndex)
    {
    case 0:
        return Vector3D(fRows[0].x(), fRows[1].x(), fRows[2].x());
        break;
    
    case 1:
        return Vector3D(fRows[0].y(), fRows[1].y(), fRows[2].y());
        break;
    
    case 2:
        return Vector3D(fRows[0].w(), fRows[1].w(), fRows[2].w());
        break;

    default:
        return Vector3D();
        break;
    }
}
