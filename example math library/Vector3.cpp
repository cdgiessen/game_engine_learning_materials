#include "Vector3.h"

namespace math
{

Vector3::Vector3() : x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

/* OPERATOR OVERLOADING */

Vector3 Vector3::operator-() { return Vector3(-x, -y, -z); }

Vector3 Vector3::operator+(Vector3 const &right) { return Vector3(right.x + x, right.y + y, right.z + z); }
Vector3 &Vector3::operator+=(Vector3 const &right)
{
    x += right.x;
    y += right.y;
    z += right.z;
    return *this; //returns a reference, *this returns the reference to itself
}

Vector3 Vector3::operator-(Vector3 const &right) { return Vector3(right.x - x, right.y - y, right.z - z); }
Vector3 &Vector3::operator-=(Vector3 const &right)
{
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;
}

Vector3 Vector3::operator*(Vector3 const &right) { return Vector3(right.x * x, right.y * y, right.z * z); }
Vector3 &Vector3::operator*=(Vector3 const &right)
{
    x *= right.x;
    y *= right.y;
    z *= right.z;
    return *this;
}

Vector3 Vector3::operator/(Vector3 const &right) { return Vector3(right.x / x, right.y / y, right.z / z); }
Vector3 &Vector3::operator/=(Vector3 const &right)
{
    x /= right.x;
    y /= right.y;
    z /= right.z;
    return *this;
}

/* EQUALITY COMPARISON */

bool Vector3::operator==(Vector3 const &right)
{
    return x == right.x && y == right.y && z == right.z;
}
bool Vector3::operator!=(Vector3 const &right)
{
    return !(*this == right); // no need to rewrite
}

/* COMMON OPERATIONS */

//functions that
float Vector3::Magnitude() const
{
    return -1;
}

//mutates the class
void Vector3::Normalize() {}

//returns a Vector3 that is the normal, but doesn't change the original one
Vector3 Vector3::Normal() const { 
    /* TODO */
    return Vector3{}; }

// member functions
float Vector3::Dot(Vector3 const &right) { /* TODO */return -1; }

Vector3 Vector3::Cross(Vector3 const &right) { /* TODO */ return Vector3{}; }

Vector3 Vector3::Lerp(Vector3 &left, float val) { /* TODO */ return Vector3{}; }

Vector3 Vector3::Projection(Vector3 &left, Vector3 &right) { /* TODO */ return Vector3{}; }

Vector3 Vector3::Perpendicular(Vector3 &left, Vector3 &right) { /* TODO */ return Vector3{}; }

/* UTILITY FUNCTIONS */

//return address of first element. useful for uploading to GPU
float *Vector3::data_ptr() { return &x; }

} // namespace math