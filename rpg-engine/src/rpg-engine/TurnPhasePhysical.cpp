#include <rpg-engine/TurnPhasePhysical.hpp>

#include <iostream> 

namespace rpg
{
    
    TurnPhasePhysical::TurnPhasePhysical()
    {
    }

    bool TurnPhasePhysical::canExec(const Entity& entity)
    {
        return true;
    }

    void TurnPhasePhysical::exec(Entity& entity,Turn& turn)
    {
        std::cout<<"Physical Phase"<<std::endl;
    }
}
