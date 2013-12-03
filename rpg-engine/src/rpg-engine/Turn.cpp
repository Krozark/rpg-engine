#include <rpg-engine/Turn.hpp>

#include <rpg-engine/Entity.hpp>

namespace rpg
{
    
    Turn::Turn(const std::list<Entity*>& entitys): current(turns.end())
    {
        for(Entity* e : entitys)
        {
            turns.emplace_back(*e);
        }
    }

    EntityTurn& Turn::getCurrentTurn()const
    {
        return *current;
    }

    void Turn::start()
    {
        current = turns.begin();
        while(current!=turns.end())
        {
            current->start();
            ++current;
        }
    }
}
