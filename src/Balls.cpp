#include "Balls.hpp"

Balls::Balls(const int& nballs) noexcept
    : m_nballs(nballs)
{
    m_balls.reserve(nballs);
    initCircles();
    initSDL();
    startSimulation();
}

void Balls::initCircles() noexcept
{
    m_balls.reserve(m_nballs);

    for(uint32_t i=0; i < m_nballs; i++)
    {
        auto velocity = Utils::randomVec2(0, 1);
        double radius = Utils::randomDouble(20, 40);
        auto position = Utils::randomVec2(radius, m_window__width - radius);
        auto mass = Utils::randomDouble(1, 10);

        Circle c(i, position, velocity, mass, radius, Utils::randomColor());

        for(const auto& ball: m_balls)
        {
            if (ball != c)
                while (ball.overlaps(c))
                {
                    auto position = Utils::randomVec2(radius, 10 - radius);
                    c.setPosition(position);
                    if (!ball.overlaps(c))
                        break;
                }
        }

        m_balls.push_back(c);

    }
}

void Balls::initSDL() noexcept
{
    SDL_Init(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow("SDL2 Circle",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                m_window__width,
                                m_window__height,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN);

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

void Balls::startSimulation() noexcept
{
    SDL_Event event;
    while (m_running)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {

                case SDL_QUIT:
                    m_running = false;
                break;

                case SDL_WINDOWEVENT:

                    switch(event.window.event)
                    {

                        case SDL_WINDOWEVENT_RESIZED:
                            m_window__width = event.window.data1;
                            m_window__height = event.window.data2;
                            SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
                            SDL_RenderClear(m_renderer);
                            SDL_RenderPresent(m_renderer);
                        break;
                    }
                break;

            }
        }

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);

        // Draw a circle in the center of the screen

        m_time += m_dt;

        for(Circle& ball1: m_balls)
        {
            boundaryCollision(ball1);
            for(Circle& ball2: m_balls)
            {
                if (ball1 != ball2)
                {
                    checkBallCollision(ball1, ball2);
                }
            }
            drawCircle(ball1);
        }

        SDL_RenderPresent(m_renderer);
    }
}

void
Balls::drawCircle(Circle& circle) noexcept
{
    auto v = circle.velocity();
    auto p = circle.position();
    auto r = circle.radius();
    auto color = circle.color();

    p += v;

    circle.setPosition(p);

    // color
    SDL_SetRenderDrawColor(m_renderer, std::get<0>(color),
                           std::get<1>(color), std::get<2>(color), 255);

    Utils::renderFillCircle(m_renderer,
                            p.x(),
                            p.y(),
                            r);
}

void
Balls::boundaryCollision(Circle& ball) noexcept
{
    auto p = ball.position();
    auto r = ball.radius();

    auto v = ball.velocity();

    if (p.x() + r >= m_window__width || p.x() - r <= 0)
        ball.setVelocity(Vec2<double>(-v.x(), v.y()));

    if (p.y() + r >= m_window__height || p.y() - r <= 0)
        ball.setVelocity(Vec2<double>(v.x(), v.y() * -1));

}

void
Balls::checkBallCollision(Circle& ball1, Circle& ball2) noexcept
{
    if (!ball1.overlaps(ball2))
        return;
    auto m1 = ball1.mass(), m2 = ball2.mass();
    auto x1 = ball1.position(), x2 = ball2.position();

    auto M = m1 + m2;
    auto k1 = (m1 - m2)/M;
    auto v1 = ball1.velocity();
    auto v2 = ball2.velocity();
    auto v3 = v1 - v2;
    auto x3 = x1 - x2;

    auto N = x3.norm() * x3.norm();

    auto v1f = v1 - 2 * m2 / M * x3 * v3.dot(x3) / N;
    auto v2f = v2 + 2 * m1 / M * x3 * v3.dot(x3) / N;

    ball1.setVelocity(v1f);
    ball2.setVelocity(v2f);
}
