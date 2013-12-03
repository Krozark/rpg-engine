#include <rpg-engine/Entity.hpp>

#include <rpg-engine/random.hpp>

#include <rpg-engine/TurnGameBased.hpp>

namespace rpg
{
    
    Entity::Entity(const std::string& n,int h) : mouvement(3), name(n), hp(h),currentBattlefield(nullptr)
    {
    }

    int Entity::getDommage()const
    {
        return 10 + random(5,15);
    }
    
    std::ostream& operator<<(std::ostream& output,const Entity& self)
    {
        return (output<<self.name);
    }

    void Entity::setBattle(TurnGameBased& battle)
    {
        if(currentBattlefield != nullptr)
        {
            exitBattle();
        }
        battle.add(*this);
        currentBattlefield = &battle;
    }

    void Entity::exitBattle()
    {
        currentBattlefield->quit(*this);
        currentBattlefield = nullptr;
    }
}
