#ifndef RPG_TURN_HPP
#define RPG_TURN_HPP

#include <rpg-engine/Action.hpp>
#include <rpg-engine/EntityTurn.hpp>

#include <list>

namespace rpg
{
    class Entity;
    class TurnGameBased;

    class Turn
    {
        public:
            Turn(const Turn&) = delete;
            Turn& operator=(const Turn&) = delete;

            Turn(const std::list<Entity*>& entitys);

            //EntityTurn& getCurrent()const;

        private:
            friend class TurnGameBased;

            void start();

            std::list<EntityTurn> turns;
            std::list<Action> actions;

            //std::list<EntityTurn>::interator current;

    };
}
#endif
