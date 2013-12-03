#ifndef RPG_ENTITYCONTROLERCONSOL_HPP
#define RPG_ENTITYCONTROLERCONSOL_HPP

#include <rpg-engine/EntityControler.hpp>

namespace rpg
{
    /**
     * \brief class that use console as main controler
     */
    class EntityControlerConsol : public EntityControler
    {
        public:
            EntityControlerConsol(const Entity& entity);
            EntityControlerConsol(const EntityControlerConsol&) = delete;
            EntityControlerConsol& operator=(const EntityControlerConsol&) = delete;

            virtual void getChoiceForMove();
            virtual void getChoiceForMagical();
            virtual void getChoiceForPhysical();

        protected:

        private:
    };
}
#endif
