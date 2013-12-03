#ifndef RPG_TURNPHASEMAGICAL_HPP
#define RPG_TURNPHASEMAGICAL_HPP

#include <rpg-engine/TurnPhase.hpp>

namespace rpg
{
    class TurnPhaseMagical : public TurnPhase
    {
        public:
            TurnPhaseMagical();
            TurnPhaseMagical(const TurnPhaseMagical&) = delete;
            TurnPhaseMagical& operator=(const TurnPhaseMagical&) = delete;

        protected:
            virtual bool canExec(const Entity& entity);
            virtual void exec(Entity& entity);

        private:
    };
}
#endif
