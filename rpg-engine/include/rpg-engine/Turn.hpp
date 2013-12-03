#ifndef RPG_TURN_HPP
#define RPG_TURN_HPP

#include <rpg-engine/TurnPhase.hpp>
#include <stack>
#include <rpg-engine/Entity.hpp>

namespace rpg
{
    class Turn
    {
        public:
            Turn(Entity& related_entity);
            Turn(const Turn&) = delete;
            Turn& operator=(const Turn&) = delete;
            Turn(Turn&&) = default;
            Turn& operator*(Turn&&) = default;

        //protected:
            void initBasic();
            void start();

        private:
            std::stack<TurnPhase*> stack;
            Entity& entity;
    };
}
#endif
