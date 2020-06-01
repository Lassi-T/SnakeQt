#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
    int x;
    int y;

    Vec2& operator+=(const Vec2 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vec2& operator-=(const Vec2 &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }


    friend Vec2 operator+(Vec2 lhs, const Vec2 &rhs)
    {
        lhs += rhs;
        return lhs;
    }

    friend Vec2 operator-(Vec2 lhs, const Vec2 &rhs)
    {
        lhs -= rhs;
        return lhs;
    }

    friend bool operator==(const Vec2 &lhs, const Vec2 &rhs)
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};



#endif // VEC2_H
