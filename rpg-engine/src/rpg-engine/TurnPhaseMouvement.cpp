#include <rpg-engine/TurnPhaseMouvement.hpp>

#include <iostream> 

#include <rpg-engine/EntityControler.hpp>

namespace rpg
{
    
    TurnPhaseMouvement::TurnPhaseMouvement()
    {
    }

    bool TurnPhaseMouvement::canExec(const Entity& entity)
    {
        return true;///\todo entity.getMouvement()>0;
    }

    void TurnPhaseMouvement::exec(Entity& entity)
    {
        std::cout<<entity<<": Mouvement Phase"<<std::endl;
        entity.getControler().getChoiceForMove();
    }
}
