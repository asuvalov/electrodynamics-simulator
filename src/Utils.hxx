#pragma once

#include <cairomm-1.0/cairomm/context.h>

namespace maxwell
{

struct Coordinates
{
    Coordinates(double x_, double y_) : x(x_), y(y_) {}
    Coordinates(const Coordinates& other) : x(other.x), y(other.y) {}
    Coordinates& operator+=(const Coordinates& coord)
    {
        x += coord.x;
        y += coord.y;
        return *this;
    }
    Coordinates& operator-=(const Coordinates& coord)
    {
        x -= coord.x;
        y -= coord.y;
        return *this;
    }
    double x;
    double y;
};

struct ArrowSize
{
    double a;
    double b;
    double c;
    double d;
};

static const ArrowSize DefaultArrowSize = {20.0, 28.0, 10.0, 20.0};

void draw_arrow(const Cairo::RefPtr<Cairo::Context>& cr,
                Coordinates coord, const ArrowSize& size = DefaultArrowSize);

} // namespace maxwell
