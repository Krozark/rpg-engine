#include <rpg-engine/EntityTurn.hpp>

#include <rpg-engine/TurnPhaseMouvement.hpp>
#include <rpg-engine/TurnPhasePhysical.hpp>
#include <rpg-engine/TurnPhaseMagical.hpp>

namespace rpg
{
    
    EntityTurn::EntityTurn(Entity& related_entity) : entity(related_entity), skipped(false)
    {
    }

    void EntityTurn::skip()
    {
        skipped=true;
    }

    void EntityTurn::initBasic()
    {
        stack.push(new TurnPhaseMouvement());
        stack.push(new TurnPhasePhysical());
        stack.push(new TurnPhaseMouvement());
        stack.push(new TurnPhaseMagical());
        stack.push(new TurnPhaseMouvement());
    }

    void EntityTurn::start()
    {
        entity.onStartTurn();

        if (not skipped)
        {
            initBasic();
            while(stack.size()>0)
            {
                TurnPhase* phase = stack.top();
                stack.pop();
                if (phase->canExec(entity))
                {
                    phase->exec(entity);
                }
                delete phase;
            }
        }
        else
        {
            ///\todo entity.onSkip()
        }

        entity.onEndTurn();
    }
}
