#include <rpg-engine/EntityPlayer.hpp>

#include <rpg-engine/EntityControlerConsol.hpp>
#include <rpg-engine/colors.hpp>

namespace rpg
{
    
    /** Public **/
    EntityPlayer::EntityPlayer() : Entity()
    {
        controler = new EntityControlerConsol(*this);
    }


    /*** Protected ***/
    void EntityPlayer::print(std::ostream& output)const
    {
        output<<name;
    }

    EntityControler& EntityPlayer::getControler()
    {
        return *controler;
    }

    void EntityPlayer::onBeginTurn()
    {
        RPG_WARNING("EntityPlayer::onBeginTurn()");
    }

    void EntityPlayer::onEndTurn()
    {
        RPG_WARNING("EntityPlayer::onEndTurn()");
    }
}
