#include <rpg-engine/Turn.hpp>

#include <rpg-engine/Entity.hpp>

namespace rpg
{
    
    Turn::Turn(const std::list<Entity*>& entitys)/*: current(turns.end())*/
    {
        for(Entity* e : entitys)
        {
            turns.emplace_back(*e);
            turns.back().initBasic();
        }
    }

    void Turn::start()
    {
        auto current = turns.begin();
        while(current!=turns.end())
        {
            current->start();
            ++current;
        }
    }
}
