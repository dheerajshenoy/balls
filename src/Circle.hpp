#pragma once

#include "Vec2.hpp"
#include <cstdint>
#include <tuple>
#include "Utils.hpp"

class Circle {

public:
    Circle(const uint32_t id, const Vec2<double>& position,
           const Vec2<double>& velocity,
           const double& mass,
           const double& radius,
           const std::tuple<int, int, int>&
           color = std::tuple<int, int, int>(255, 255, 255));

    inline uint32_t id() const noexcept
    { return m_id; }

    inline Vec2<double> position() const noexcept
    { return m_pos; }

    inline Vec2<double> velocity() const noexcept
    { return m_vel; }

    inline double mass() const noexcept
    { return m_mass; }

    inline double radius() const noexcept
    { return m_radius; }

    inline std::tuple<int, int, int> color() const noexcept
    { return m_color; }

    inline void setMass(const double& mass) noexcept
    { m_mass = mass; }

    inline void setVelocity(const Vec2<double>& velocity) noexcept
    { m_vel = velocity; }

    inline void setPosition(Vec2<double>& position) noexcept
    { m_pos = position; }

    inline void setColor(const std::tuple<int, int, int>& color) noexcept
    { m_color = color; }

    inline const bool operator!=(const Circle& other) const noexcept
    {
        return this->m_id != other.m_id;
    }

    bool overlaps(const Circle& other) const noexcept;

private:
    uint32_t m_id;
    Vec2<double> m_pos, m_vel;
    double m_radius, m_mass;
    std::tuple<int, int, int> m_color;
};
