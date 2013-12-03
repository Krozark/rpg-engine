#ifndef RPG_TURNGAMEBASED_HPP
#define RPG_TURNGAMEBASED_HPP

#include <rpg-engine/Action.hpp>
#include <rpg-engine/Turn.hpp>

#include <list>

namespace rpg
{
    /**
     * \brief Class to manage a Turn Base moment with multiple entity
     */
    class TurnGameBased
    {
        public:
            TurnGameBased();
            TurnGameBased(const TurnGameBased&) = delete;
            TurnGameBased& operator=(const TurnGameBased&) = delete;

            Turn& getCurrentTurn()const;
            EntityTurn& getCurrentEntityTurn()const;

            void start();
            void quit(const Entity& entity);

        private:
            std::list<Turn> turns;
            std::list<Action> actions;

            std::list<Turn>::iterator current;

            void newTurn();
            std::list<Entity*> entitys;

            friend void Entity::setBattle(TurnGameBased&); 
            void add(Entity& entity);
    };
}
#endif
