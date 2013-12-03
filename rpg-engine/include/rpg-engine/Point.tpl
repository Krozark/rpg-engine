
namespace rpg
{
    namespace math
    {
        
        template <typename T>
        Point<T>::Point(T X,T Y) : x(X), y(Y)
        {
        }

        template <typename T>
        Point<T>& Point<T>::operator+(const Point& other)
        {
            x+=other.x;
            y+=other.y;
            return *this;
        }

        template <typename T>
        Point<T>& Point<T>::operator-(const Point& other)
        {
            x-=other.x;
            y+=other.y;
            return *this;
        }

        template <typename T>
        Point<T>& Point<T>::operator+(T nb)
        {
            x+=nb;
            y+=nb;
            return *this;
        }

        template <typename T>
        Point<T>& Point<T>::operator-(T nb)
        {
            x-=nb;
            y-=nb;
            return *this;
        }
    }
}
