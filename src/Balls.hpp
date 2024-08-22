#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <vector>

#include "Vec2.hpp"
#include "Circle.hpp"
#include "Utils.hpp"

class Balls {

public:
    Balls(const int& nballs) noexcept;
    void startSimulation() noexcept;


private:
    void initCircles() noexcept;
    void initSDL() noexcept;
    void drawCircle(Circle& circle) noexcept;
    void boundaryCollision(Circle& ball) noexcept;
    void checkBallCollision(Circle& ball1,
                            Circle& ball2) noexcept;

private:
    int m_nballs;
    SDL_Window *m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    bool m_running = true;

    std::vector<Circle> m_balls;

    double m_time = 0, m_dt = 1;

    int    m_window__width = 1200,
                m_window__height = 1200;

    std::vector<Vec2<double>> m_positions;
};
