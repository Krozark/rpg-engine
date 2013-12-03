#include <rpg-engine/Turn.hpp>

#include <rpg-engine/TurnPhaseMouvement.hpp>
#include <rpg-engine/TurnPhasePhysical.hpp>
#include <rpg-engine/TurnPhaseMagical.hpp>

namespace rpg
{
    
    Turn::Turn(Entity& related_entity) : entity(related_entity)
    {
    }

    void Turn::initBasic()
    {
        stack.push(new TurnPhaseMouvement());
        stack.push(new TurnPhasePhysical());
        stack.push(new TurnPhaseMouvement());
        stack.push(new TurnPhaseMagical());
        stack.push(new TurnPhaseMouvement());
    }

    void Turn::start()
    {
        entity.onStartTurn();

        while(stack.size()>0)
        {
            TurnPhase* phase = stack.top();
            stack.pop();
            if (phase->canExec(entity))
            {
                phase->exec(entity,*this);
            }
            delete phase;
        }

        entity.onEndTurn();
    }
}
