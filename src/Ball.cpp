#include "Ball.hpp"


template <typename T>
static double distance(Vec2<T>& v1, Vec2<T>& v2) noexcept
{
    auto x1= v1.x(), x2 = v2.x(), y1 = v1.y(), y2 = v2.y();
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

Ball::Ball(const uint32_t id, const Vec2<double>& position,
               const Vec2<double>& velocity,
               const double& mass,
               const double& radius,
               const std::tuple<int, int, int>& color)
    : m_id(id), Circle(position, radius), m_vel(velocity), m_mass(mass), m_color(color)
{}

