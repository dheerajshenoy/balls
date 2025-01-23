#pragma once

#include "Vec2.hpp"
#include "Circle.hpp"
#include <cstdint>
#include <tuple>
#include "Utils.hpp"

class Ball : public Circle
{

public:
    Ball(const uint32_t id, const Vec2<double>& position,
           const Vec2<double>& velocity,
           const double& mass,
           const double& radius,
           const std::tuple<int, int, int>&
           color = std::tuple<int, int, int>(255, 255, 255));

    inline uint32_t id() const noexcept
    { return m_id; }

    inline Vec2<double> velocity() const noexcept
    { return m_vel; }

    inline double mass() const noexcept
    { return m_mass; }

    inline std::tuple<int, int, int> color() const noexcept
    { return m_color; }

    inline void setMass(const double& mass) noexcept
    { m_mass = mass; }

    inline void setVelocity(const Vec2<double>& velocity) noexcept
    { m_vel = velocity; }

    inline void setColor(const std::tuple<int, int, int>& color) noexcept
    { m_color = color; }

    inline const bool operator!=(const Ball& other) const noexcept
    {
        return this->m_id != other.m_id;
    }

private:
    uint32_t m_id;
    Vec2<double> m_vel;
    double m_mass;
    std::tuple<int, int, int> m_color;
};
