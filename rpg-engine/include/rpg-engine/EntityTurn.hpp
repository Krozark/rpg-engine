#ifndef RPG_ENTITYTURN_HPP
#define RPG_ENTITYTURN_HPP

#include <rpg-engine/TurnPhase.hpp>
#include <stack>
#include <rpg-engine/Entity.hpp>

namespace rpg
{
    class EntityTurn
    {
        public:
            EntityTurn(Entity& related_entity);
            EntityTurn(const EntityTurn&) = delete;
            EntityTurn& operator=(const EntityTurn&) = delete;
            EntityTurn(EntityTurn&&) = default;
            EntityTurn& operator=(EntityTurn&&) = default;

        //protected:
            void initBasic();
            void start();

        private:
            std::stack<TurnPhase*> stack;
            Entity& entity;
            //list of actions makes
    };
}
#endif
