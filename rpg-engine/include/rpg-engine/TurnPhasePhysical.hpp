#ifndef RPG_TURNPHASEPHYSICAL_HPP
#define RPG_TURNPHASEPHYSICAL_HPP


#include <rpg-engine/TurnPhase.hpp>

namespace rpg
{
    /**
     * \brief Class to manage Physical phase
     */
    class TurnPhasePhysical : public TurnPhase
    {
        public:
            TurnPhasePhysical();
            TurnPhasePhysical(const TurnPhasePhysical&) = delete;
            TurnPhasePhysical& operator=(const TurnPhasePhysical&) = delete;

        protected:
            virtual bool canExec(const Entity& entity);
            virtual void exec(Entity& entity);

        private:
    };
}
#endif
