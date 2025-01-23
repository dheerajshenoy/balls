#pragma once

#include "Vec2.hpp"
#include "Utils.hpp"
#include <cstdint>

class Circle
{

public:
    Circle(const Vec2<double>& position,
           double radius,
           void* userData = nullptr) noexcept
        : m_position(position), m_userData(userData) 
    {}

    inline void setPosition(Vec2<double>& position) noexcept
    { m_position = position; }

    static double distanceSqr(Vec2<double>& v1, Vec2<double>& v2) noexcept
    {
        auto x1= v1.x(), x2 = v2.x(), y1 = v1.y(), y2 = v2.y();
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }

    inline bool overlaps(Circle& other) noexcept
    {
        auto R = this->m_radius + other.m_radius;
        return (distanceSqr(this->m_position, other.m_position) <= R * R);
    }

    inline double radius() const noexcept
    { return m_radius; }

    inline Vec2<double> position() const noexcept
    { return m_position; }

private:
    double m_radius;
    Vec2<double> m_position;
    void* m_userData;
};
