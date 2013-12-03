#include <rpg-engine/TurnPhaseMouvement.hpp>

#include <iostream> 

namespace rpg
{
    
    TurnPhaseMouvement::TurnPhaseMouvement()
    {
    }

    bool TurnPhaseMouvement::canExec(const Entity& entity)
    {
        return entity.getMouvement()>0;
    }

    void TurnPhaseMouvement::exec(Entity& entity,EntityTurn& turn)
    {
        std::cout<<"Mouvement Phase"<<std::endl;
    }
}
