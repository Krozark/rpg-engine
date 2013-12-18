#include <rpg-engine/Element.hpp>

namespace rpg
{
namespace element
{
    void init()
    {
        for (int i=0;i<Elements::Size;++i)
            for(int j=0;j<Elements::Size;++j)
            {
                if(i==j)//diagonal
                    Oppose[i][j] = 0.75;
                else
                    Oppose[i][j] = 1;
            }

        //Neutral
        Oppose[Elements::Neutre][Elements::Neutre] = 1;
        //Watter
        Oppose[Elements::Eau][Elements::Feu] = 2;
        Oppose[Elements::Eau][Elements::Aire] = 0.5;
        //Fire
        Oppose[Elements::Feu][Elements::Terre] = 2;
        Oppose[Elements::Feu][Elements::Eau] = 0.5;
        //Earth
        Oppose[Elements::Terre][Elements::Aire] = 2;
        Oppose[Elements::Terre][Elements::Feu] = 0,5;
        //Aire
        Oppose[Elements::Aire][Elements::Eau] = 2;
        Oppose[Elements::Aire][Elements::Terre] = 0.5;
        
        //Lumiere
        Oppose[Elements::Lumiere][Elements::Ombre] = 2;
        //Ombre
        Oppose[Elements::Ombre][Elements::Lumiere] = 2;

        //Oppose[Elements::][Elements::] = ;

    };

    float get(Elements _1, Elements _2)
    {
        if(_1 <0 or _1>=Elements::Size or _2 <0 or _2 >= Elements::Size)
            return 1;
        return Oppose[_1][_2];
    }
}
    
}
