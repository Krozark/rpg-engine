#include <rpg-engine/TurnPhaseMagical.hpp>

#include <iostream> 

namespace rpg
{
    
    TurnPhaseMagical::TurnPhaseMagical()
    {
    }

    bool TurnPhaseMagical::canExec(const Entity& entity)
    {
        return true;
    }

    void TurnPhaseMagical::exec(Entity& entity,Turn& turn)
    {
        std::cout<<"Magical Phase"<<std::endl;
    }
}
