#include <rpg-engine/Entity.hpp>

#include <rpg-engine/TurnGameBased.hpp>

#include <rpg-engine/random.hpp>
#include <rpg-engine/colors.hpp>

namespace rpg
{
    
    Entity::Entity() : currentBattlefield(nullptr)
    {
    }

    std::ostream& operator<<(std::ostream& output,const Entity& self)
    {
        self.print(output);
        return output;
    }

    void Entity::moveOf(int x,int y)
    {
        position.x+=x;
        position.y+=y;
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


    void Entity::slotBeginTurn(EntityTurn& myturn)
    {
        RPG_H1("Debut du tour de "<<*this);
        ///\todo loop on effect triggers
        //reset mvt, esquive
        turn_def = tmp_stats.getDiceDef().roll();
        turn_mdef = tmp_stats.getDiceMdef().roll();
        turn_esq = tmp_stats.getNbEsq();
        turn_atq = tmp_stats.getNbAtq();
        turn_mvt = tmp_stats.getMvt();

        this->onBeginTurn();
    }

    void Entity::slotEndTurn(EntityTurn& myturn) 
    {
        RPG_H1("Fin du tour de "<<*this);

        this->onEndTurn();
    }

}
