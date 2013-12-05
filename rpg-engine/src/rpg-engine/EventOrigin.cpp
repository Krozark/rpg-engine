#include <rpg-engine/EventOrigin.hpp>

#include <rpg-engine/random.hpp>

#include <iostream>

namespace rpg
{
    
    EventOrigin::EventOrigin(const std::string& n,int d) : name(n), dodge(d), max_evasion_nb(0)
    {
    }

    int EventOrigin::getEvasion()const
    {
        return dodge;
    }

    int EventOrigin::getDommage()const
    {
        return 10;
    }

    bool EventOrigin::attack(char type,EventOrigin& other)
    {
        std::cout<<name<<" attack "<<other.name<<std::endl;

        bool res = false;
        if(other.recvTarget(type,*this))
        {
            res = true;
            other.recvDommage(type,*this,getDommage());
        }
        return res;
    }

    bool EventOrigin::recvDommage(char type,EventOrigin& src,int dmg)
    {
        //\todo call onRecvDommage on all passif spells
        std::cout<<name<<" take "<<dmg<<" dommages from "<<src.name<<std::endl;
    }

    bool EventOrigin::recvTarget(char type,EventOrigin& src)
    {
        std::cout<<name<<" have been targeted by "<<src.name<<std::endl;

        bool res = true;
        //\todo call onRecvOrigin on all passif spells
        max_evasion_nb--;
        if(max_evasion_nb >=0 and random(1,100) <= getEvasion())
        {
            std::cout<<name<<" escape the attack of "<<src.name<<std::endl;
            res = false;
            sendCounterAttack(type,src);
        }
        max_evasion_nb++;
        return res;
    }

    bool EventOrigin::sendCounterAttack(char type,EventOrigin& dest)
    {
        //\todo call onSendCounterAttack on all passif spells
        std::cout<<name<<" send a counter attack to "<<dest.name<<std::endl;

        bool res = false;
        if(dest.recvTarget(type,*this))
        {
            res = true;
            dest.recvDommage(type,*this,getDommage());
        }
        return res;
    }
}
