#pragma once

#include "Vec2.hpp"
#include "Ball.hpp"

class Rectangle
{

public:
    Rectangle(Vec2<double>& position, double width, double height) noexcept
        : m_position(position), m_width(width), m_height(height)
    {}

    Rectangle() = default;

    Rectangle(Vec2<double>&& position, double width, double height) noexcept
        : m_position(std::move(position)), m_width(width), m_height(height)
    {}

    bool containsPoint(const Ball& ball) noexcept
    {
        auto position = ball.position();
        return (this->m_position.x() <=  position.x() <= this->m_position.x() + this->m_width &&
                this->m_position.y() <= position.y() <= this->m_position.y() + this->m_height);
    }

    bool overlaps(Rectangle* rect) noexcept
    {
        auto position = rect->m_position;

        return !(position.x() - rect->width() > this->x() + this->width() ||
                 position.x() + rect->width() < this->x() - this->width() ||
                 position.y() - rect->height() > this->y() + this->height() ||
                 position.y() + rect->height() > this->y() - this->height());
    }

    inline double x() { return m_position.x(); }
    inline double y() { return m_position.y(); }
    inline double width() { return m_width; }
    inline double height() { return m_height; }

private:
    Vec2<double> m_position;
    double m_width, m_height;
};
