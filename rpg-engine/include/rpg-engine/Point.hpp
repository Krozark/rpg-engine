#ifndef RPG_MATH_POINT_HPP
#define RPG_MATH_POINT_HPP

namespace rpg
{
    namespace math
    {
        template <typename T>
        class Point
        {
            public:
                Point(const Point&) = delete;
                Point& operator=(const Point&) = delete;

                Point(T x=0,T y=0);

                T x;
                T y;

                Point<T>& operator+(const Point& other);
                Point<T>& operator-(const Point& other);

                Point<T>& operator+(T nb);
                Point<T>& operator-(T nb);

        };
    }
}
#include <rpg-engine/Point.tpl>
#endif
