#ifndef RPG_TURNGAMEBASED_HPP
#define RPG_TURNGAMEBASED_HPP

#include <rpg-engine/Action.hpp>
#include <rpg-engine/Turn.hpp>

#include <list>

namespace rpg
{
    class TurnGameBased
    {
        public:
            TurnGameBased();
            TurnGameBased(const TurnGameBased&) = delete;
            TurnGameBased& operator=(const TurnGameBased&) = delete;

            Turn& getCurrent()const;

            void start();
            void quit(const Entity& entity);

        private:
            std::list<Turn> turns;
            std::list<Action> actions;

            //std::list<Turn>::interator current;

            void newTurn();
            std::list<Entity*> entitys;

            friend void Entity::setBattle(TurnGameBased&); 
            void add(Entity& entity);
    };
}
#endif
