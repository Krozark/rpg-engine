#include <rpg-engine/TurnGameBased.hpp>

namespace rpg
{
    
    TurnGameBased::TurnGameBased() /*: current(turns.end())*/
    {
    }

    void TurnGameBased::add(Entity& entity)
    {
        for(Entity* e : entitys)
            if(e==&entity)
                return;
        entitys.emplace_back(&entity);
        //\todo sort order
    }

    void TurnGameBased::start()
    {
        newTurn();
        auto current = turns.begin();

        while(entitys.size()>0)
        {
            if(current == turns.end())
            {
                newTurn();
            }
            current->start();
            ++current;
        }
    }

    void TurnGameBased::quit(const Entity& entity)
    {
        entitys.remove_if([&entity](Entity* e){return e == &entity;});
    }

    void TurnGameBased::newTurn()
    {
        turns.emplace_back(entitys);
    }
}
