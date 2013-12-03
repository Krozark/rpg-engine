#ifndef RPG_ENTITYTURN_HPP
#define RPG_ENTITYTURN_HPP

#include <rpg-engine/TurnPhase.hpp>
#include <rpg-engine/Entity.hpp>
#include <rpg-engine/Action.hpp>

#include <stack>
#include <list>

namespace rpg
{
    class Turn;

    class EntityTurn
    {
        public:
            EntityTurn(const EntityTurn&) = delete;
            EntityTurn& operator=(const EntityTurn&) = delete;
            EntityTurn(EntityTurn&&) = default;
            EntityTurn& operator=(EntityTurn&&) = default;

            EntityTurn(Entity& related_entity);


        private:
            friend class Turn;
            
            void initBasic();
            void start();

            std::stack<TurnPhase*> stack;
            Entity& entity;
            std::list<Action> actions;
    };
}
#endif
