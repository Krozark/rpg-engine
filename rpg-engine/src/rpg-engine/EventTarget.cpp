#include <rpg-engine/EventTarget.hpp>

#include <rpg-engine/random.hpp>

#include <iostream>

namespace rpg
{
    
    EventTarget::EventTarget(const std::string& n,int d) : name(n), dodge(d), max_evasion_nb(0)
    {
    }

    int EventTarget::getEvasion()
    {
        return dodge;
    }

    int EventTarget::getDommage()
    {
        return 10;
    }

    bool EventTarget::attack(EventTarget& other)
    {
        std::cout<<name<<" attack "<<other.name<<std::endl;

        bool res = false;
        if(other.recvTarget(*this))
        {
            res = true;
            other.recvDommage(*this,getDommage());
        }
        return res;
    }

    bool EventTarget::recvDommage(EventTarget& src,int dmg)
    {
        //\todo call onRecvDommage on all passif spells
        std::cout<<name<<" take "<<dmg<<" dommages from "<<src.name<<std::endl;
    }

    bool EventTarget::recvTarget(EventTarget& src)
    {
        std::cout<<name<<" have been targeted by "<<src.name<<std::endl;

        bool res = true;
        //\todo call onRecvTarget on all passif spells
        max_evasion_nb--;
        if(max_evasion_nb >=0 and random(1,100) <= getEvasion())
        {
            std::cout<<name<<" escape the attack of "<<src.name<<std::endl;
            res = false;
            sendCounterAttack(src);
        }
        max_evasion_nb++;
        return res;
    }

    bool EventTarget::sendCounterAttack(EventTarget& dest)
    {
        //\todo call onSendCounterAttack on all passif spells
        std::cout<<name<<" send a counter attack to "<<dest.name<<std::endl;

        bool res = false;
        if(dest.recvTarget(*this))
        {
            res = true;
            dest.recvDommage(*this,getDommage());
        }
        return res;
    }
}
