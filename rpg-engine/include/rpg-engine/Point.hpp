#ifndef RPG_MATH_POINT_HPP
#define RPG_MATH_POINT_HPP

#include <list>

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

                Point(Point<T>&&) = default;
                Point<T>& operator=(Point<T>&&) = default;

                Point(T x=0,T y=0);

                T x;
                T y;

                T z()const;

                Point<T> operator+(const Point& other);
                Point<T> operator-(const Point& other);

                template <typename U> Point<T>& operator+(U nb);
                template <typename U> Point<T>& operator-(U nb);
                template <typename U> Point<T>& operator*(U nb);
                template <typename U> Point<T>& operator/(U nb);

                static T getHexDistance(const Point<T>& a,const Point<T>& b);
                static void getHexPath(const Point<T>& a,const Point<T>& b/**\todo ,std::funtion(Point<T>&) function*/);
                static std::list<Point<T>> getHexRange(const Point<T>& a,int range);

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
