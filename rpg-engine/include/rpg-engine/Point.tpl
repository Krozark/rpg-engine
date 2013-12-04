
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


        template <typename T>
        T Point<T>::z()const
        {
            //x+y+z=0;
            return -(x+y);
        }

        template <typename T>
        T Point<T>::getHexDistance(const Point<T>& a,const Point<T>& b)
        {
            return max(max(abs(a.x-b.x),abs(a.y-b.y)),abs(a.z()-b.z()));
        }       

    }
}
