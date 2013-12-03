#ifndef RPG_TURN_HPP
#define RPG_TURN_HPP

#include <rpg-engine/Action.hpp>
#include <rpg-engine/EntityTurn.hpp>

#include <list>

namespace rpg
{
    class Entity;
    class TurnGameBased;

    /**
     * \brief Class to manage a turn of multiple entity
     */
    class Turn
    {
        public:
            Turn(const Turn&) = delete;
            Turn& operator=(const Turn&) = delete;

            Turn(const std::list<Entity*>& entitys);

            EntityTurn& getCurrentTurn()const;

        private:
            friend class TurnGameBased;

            void start();

            std::list<EntityTurn> turns;
            std::list<Action> actions;

            std::list<EntityTurn>::iterator current;

    };
}
#endif
