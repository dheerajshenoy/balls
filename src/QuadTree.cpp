#include "QuadTree.hpp"


QuadTree::QuadTree(Rectangle* boundary) noexcept
    : m_boundary(boundary)
{
    m_balls.reserve(m_node_capacity);
}

void QuadTree::insert(const Ball& ball) noexcept
{
    // If the location is outside the current range, do not add it
    if (!m_boundary->containsPoint(ball))
        return;

    if (m_balls.size() < m_node_capacity)
    {
        m_balls.push_back(ball);
    }
    else
    {
        if (!m_divided)
        {
            subdivide();
        }

        m_northEast->insert(ball);
        m_northWest->insert(ball);
        m_southEast->insert(ball);
        m_southWest->insert(ball);
    }
}

void QuadTree::subdivide() noexcept
{
    auto boundary = this->m_boundary;
    Rectangle* ne = new Rectangle(Vec2<double>(boundary->x() + boundary->width() / 2.0f, boundary->y() - boundary->height() / 2.0f),
                            boundary->width() / 2.0f,
                            boundary->height() / 2.0f
                            );

    m_northEast = new QuadTree(ne);

    Rectangle* se = new Rectangle(Vec2<double>(boundary->x() + boundary->width() / 2.0f, boundary->y() + boundary->height() / 2.0f),
                            boundary->width() / 2.0f,
                            boundary->height() / 2.0f
                            );
    m_southEast = new QuadTree(se);

    Rectangle* sw = new Rectangle(Vec2<double>(boundary->x() - boundary->width() / 2.0f, boundary->y() + boundary->height() / 2.0f),
                            boundary->width() / 2.0f,
                            boundary->height() / 2.0f
                            );
    m_southWest = new QuadTree(sw);

    Rectangle* nw = new Rectangle(Vec2<double>(boundary->x() - boundary->width() / 2.0f, boundary->y() - boundary->height() / 2.0f),
                            boundary->width() / 2.0f,
                            boundary->height() / 2.0f
                            );
    m_northWest = new QuadTree(nw);
    m_divided = true;
}

void QuadTree::queryRange(Rectangle* rect, std::vector<Ball>& foundBalls) noexcept
{
    if (!m_boundary->overlaps(rect))
        return;

    std::cout << "D";

    for(const auto& ball : m_balls)
    {
        if (rect->containsPoint(ball))
            foundBalls.push_back(ball);
    }

    if (m_divided)
    {
        m_northEast->queryRange(rect, foundBalls);
        m_northWest->queryRange(rect, foundBalls);
        m_southEast->queryRange(rect, foundBalls);
        m_southWest->queryRange(rect, foundBalls);
    }

}
