#pragma once

#include <cmath>
#include <cwchar>
#include <iostream>
#include <utility>

template <typename T>
class Vec2 {

public:
    Vec2() noexcept = default;
    Vec2(const T& x, const T& y) noexcept;
    Vec2(T&& x, T&& y) noexcept;

    inline void setXY(T&& x, T&& y) noexcept { m_x = x; m_y = y; }
    inline void setXY(const T& x, const T& y) noexcept { m_x = x; m_y = y; }

    T dot(const Vec2& other) const noexcept;
    T norm() noexcept;
    void print() const noexcept;

    inline const T& x() { return m_x; }
    inline const T& y() { return m_y; }

    Vec2<T> operator+(const Vec2<T>& other) noexcept;
    Vec2<T> operator-(const Vec2<T>& other) noexcept;
    Vec2<T> operator/(const T& other) noexcept;
    Vec2<T> operator*(const T& other) noexcept;
    Vec2<T> operator+=(const T& other) noexcept;
    Vec2<T>& operator+=(const Vec2<T>& other) noexcept;
    Vec2<T>& operator*=(const T& scalar) noexcept;
    Vec2<T> operator-() noexcept;

    friend Vec2<T> operator/(const T& scalar, const Vec2<T>& vec) noexcept
    {
        return Vec2<T>(scalar / vec.m_x, scalar / vec.m_y);
    }


    friend Vec2<T> operator*(const T& scalar, const Vec2<T>& vec) noexcept
    {
        return Vec2<T>(scalar * vec.m_x, scalar * vec.m_y);
    }

private:
    T m_x, m_y;
};

template <typename T>
Vec2<T>::Vec2(const T& x, const T& y) noexcept
    : m_x(x), m_y(y)
{}

template <typename T>
Vec2<T>::Vec2(T&& x, T&& y) noexcept
    : m_x(std::move(x)), m_y(std::move(y))
{}

template <typename T>
T Vec2<T>::dot(const Vec2<T>& other) const noexcept
{
    return this->m_x * other.m_x + this->m_y * other.m_y;
}

template <typename T>
void Vec2<T>::print() const noexcept
{
    std::cout << "Vec2(" << this->m_x << ", " << this->m_y << ")\n";
}

template <typename T>
Vec2<T> Vec2<T>::operator+(const Vec2<T>& other) noexcept
{
    return Vec2<T>(this->m_x + other.m_x, this->m_y + other.m_y);
}

template <typename T>
Vec2<T> Vec2<T>::operator-(const Vec2<T>& other) noexcept
{
    return Vec2<T>(this->m_x - other.m_x, this->m_y - other.m_y);
}

template <typename T>
Vec2<T> Vec2<T>::operator/(const T& other) noexcept
{
    return Vec2<T>(this->m_x / other, this->m_y / other);
}

template <typename T>
Vec2<T> Vec2<T>::operator*(const T& other) noexcept
{
    return Vec2<T>(this->m_x * other, this->m_y * other);
}

template <typename T>
T Vec2<T>::norm() noexcept
{
    return sqrt(m_x * m_x + m_y * m_y);
}

template <typename T>
Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& other) noexcept
{
    this->m_x += other.m_x;
    this->m_y += other.m_y;
    return *this;
}

template <typename T>
Vec2<T>& Vec2<T>::operator*=(const T& scalar) noexcept
{
    this->m_x *= scalar;
    this->m_y *= scalar;
    return *this;
}

template <typename T>
Vec2<T> Vec2<T>::operator-() noexcept
{
    return Vec2<T>(this->m_x * -1, this->m_y * -1);
}
