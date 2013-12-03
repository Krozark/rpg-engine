#ifndef RPG_TURNPHASEMOUVEMENT_HPP
#define RPG_TURNPHASEMOUVEMENT_HPP

#include <rpg-engine/TurnPhase.hpp>

namespace rpg
{
    /**
     * \brief Class to manage mouvement phase
     */
    class TurnPhaseMouvement : public TurnPhase
    {
        public:
            TurnPhaseMouvement();
            TurnPhaseMouvement(const TurnPhaseMouvement&) = delete;
            TurnPhaseMouvement& operator=(const TurnPhaseMouvement&) = delete;

        protected:
            virtual bool canExec(const Entity& entity);
            virtual void exec(Entity& entity);

        private:
    };
}
#endif
