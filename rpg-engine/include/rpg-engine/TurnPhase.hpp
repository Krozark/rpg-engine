#ifndef RPG_TURNPHASE_HPP
#define RPG_TURNPHASE_HPP

#include <rpg-engine/Entity.hpp>

namespace rpg
{
    class EntityTurn;

    class TurnPhase
    {
        public:
            TurnPhase();
            virtual ~TurnPhase();
            TurnPhase(const TurnPhase&) = delete;
            TurnPhase& operator=(const TurnPhase&) = delete;

        protected:
            friend class EntityTurn;
            virtual bool canExec(const Entity& entity) = 0;
            virtual void exec(Entity& entity,EntityTurn& turn) = 0;

        private:

            
    };
}
#endif
