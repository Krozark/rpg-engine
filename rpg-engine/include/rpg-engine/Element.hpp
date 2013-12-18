#ifndef RPG_ELEMENT_HPP
#define RPG_ELEMENT_HPP


#include <string>
#include <vector>

namespace rpg
{
    enum Elements{Eau=0,
        Feu,
        Terre,
        Aire,
        Neutre,
        Lumiere,
        Ombre,
        Size};

    namespace element
    {
        static float Oppose[Elements::Size][Elements::Size];
        void init();
        float get(Elements _1,Elements _2);
    }
}
#endif
