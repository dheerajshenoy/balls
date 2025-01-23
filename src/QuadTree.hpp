#pragma once

#include "Rectangle.hpp"
#include "Ball.hpp"
#include "Circle.hpp"
#include <vector>

class QuadTree
{

public:
    QuadTree(const Rectangle& boundary) noexcept;
    QuadTree(Rectangle* boundary) noexcept;

    void insert(const Ball& ball) noexcept;
    void subdivide() noexcept;
    void queryRange(Rectangle* range, std::vector<Ball>& foundBalls) noexcept;
    void queryRange(Circle* range, std::vector<Ball>& foundBalls) noexcept;

private:

    Rectangle* m_boundary = nullptr;

    // Clockwise
    QuadTree    *m_northEast = nullptr,
                *m_southEast = nullptr,
                *m_southWest = nullptr,
                *m_northWest = nullptr;

    static constexpr uint32_t m_node_capacity = 4;
    std::vector<Ball> m_balls;

    bool m_divided = false;
};
