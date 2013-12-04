
namespace rpg
{
    namespace math
    {
        
        template <typename T>
        Point<T>::Point(T X,T Y) : x(X), y(Y)
        {
        }

        template <typename T>
        Point<T> Point<T>::operator+(const Point& other)
        {
            return Point<T>(x+other.x,y+other.y);
        }

        template <typename T>
        Point<T> Point<T>::operator-(const Point& other)
        {
            return Point<T>(x-other.x,y-other.y);
        }

        template <typename T>
        template <typename U>
        Point<T>& Point<T>::operator+(U nb)
        {
            x+=nb;
            y+=nb;
            return *this;
        }

        template <typename T>
        template <typename U>
        Point<T>& Point<T>::operator-(U nb)
        {
            x-=nb;
            y-=nb;
            return *this;
        }

        template <typename T>
        template <typename U>
        Point<T>& Point<T>::operator*(U nb)
        {
            x*=nb;
            y*=nb;
            return *this;
        }

        template <typename T>
        template <typename U>
        Point<T>& Point<T>::operator/(U nb)
        {
            x/=nb;
            y/=nb;
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
        
        template <typename T>
        void Point<T>::getHexPath(const Point<T>& a,const Point<T>& b)
        {
            int N = getHexDistance(a,b);
            Point<T> tmp = b-a;
            float delta = 1.0/N;
            float accumulator = 0;

            for (int i=0;i<N;++i)
            {
                 //A * (1 - i/N) + B * i/N
                 //=> A + (B - A) * i/N
                 a +tmp*accumulator;
                 accumulator+=delta;
            }
        }

        
        template <typename T>
        std::list<Point<T>> Point<T>::getHexRange(const Point<T>& a,int range)
        {
            /*for each -N ≤ Δx ≤ N:
                for each max(-N, -Δx-N) ≤ Δy ≤ min(N, -Δx+N):
                    Δz = -Δx-Δy
                    results.append(H.add(Cube(Δx, Δy, Δz)))*/
            std::list<Point<T>> res;

            const T xmin = a.x - range;
            const T xmax = a.x + range;

            const T ymin = a.y - range;
            const T ymax = a.y + range;

            const T _z = a.z();
            const T zmin = _z - range;
            const T zmax = _z + range;

            for(int x=xmin;x<=xmax;++x)
            {
                int _max = max(-ymin,-x-zmax);
                int _min = min(ymax,-x-zmin);

                for(int y=_max;y<=_min;++y)
                {
                    int z = -x-y;
                    ///\todo res.emplace_back(toHex(x,y,z)); //reset the bigger
                }
            }
            return res;
        }

    }
}
