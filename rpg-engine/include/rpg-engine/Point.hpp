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

                T z()const;

                Point<T>& operator+(const Point& other);
                Point<T>& operator-(const Point& other);

                Point<T>& operator+(T nb);
                Point<T>& operator-(T nb);

                static T getHexDistance(const Point<T>& a,const Point<T>& b);

        };

        template <typename T>
        inline T min(T x,T y){return x<y?x:y;}

        template <typename T>
        inline T max(T x,T y){return x>y?x:y;}

        template <typename T>
        inline T abs(T x){return x>0?x:-x;}
    }
}
#include <rpg-engine/Point.tpl>
#endif
