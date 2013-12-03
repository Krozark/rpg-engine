#include <rpg-engine/Entity.hpp>

#include <rpg-engine/TurnGameBased.hpp>
#include <rpg-engine/EntityControlerConsol.hpp>

#include <rpg-engine/random.hpp>
#include <rpg-engine/colors.hpp>

namespace rpg
{
    
    Entity::Entity(const std::string& n,int h) : mouvement(3), name(n), hp(h),currentBattlefield(nullptr), controler(new EntityControlerConsol(*this))
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

    void Entity::move(int x,int y)
    {
        position.x+=x;
        position.y+=y;
    }

    void Entity::onStartTurn()
    {
        RPG_H1("Debut du tour de "<<name);
        ///\todo loop on effect triggers
        
    }

    void Entity::onEndTurn() 
    {
    }

    EntityControler& Entity::getControler()
    {
        return *controler;
    }
}
