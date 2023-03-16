
#define _USE_MATH_DEFINES     // must be defined before any #include  
#include "Vector3D.h"

#include <cassert>
#include <cmath>
#include <iostream>

Vector3D::Vector3D( float aX, float aY, float aW) noexcept :
    fBaseVector(aX, aY),
    fW(aW)
{}

Vector3D::Vector3D( const Vector2D aVector) noexcept :
    fBaseVector(aVector),
    fW(1.0f)
{}

float Vector3D::operator[]( size_t aIndex ) const
{
    assert( aIndex < 3 );
    return *(reinterpret_cast<const float*>(this) + aIndex);
}

Vector3D Vector3D::operator*( const float aScalar ) const noexcept
{
    return Vector3D( x() * aScalar, y() * aScalar, w() * aScalar);
}

Vector3D Vector3D::operator+( const Vector3D& aOther ) const noexcept
{
    return Vector3D( x() + aOther.x(), y() + aOther.y() );
}

float Vector3D::dot( const Vector3D& aOther ) const noexcept
{
    return x() * aOther.x() + y() * aOther.y();
}

std::ostream& operator<<( std::ostream& aOStream, const Vector3D& aVector )
{
    return aOStream << "[" << round( aVector.x() * 1000.0f ) / 1000.0f << "," << round( aVector.y() * 1000.0f ) / 1000.0f << "]";
}