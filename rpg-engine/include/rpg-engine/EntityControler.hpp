#ifndef RPG_ENTITYCONTROLER_HPP
#define RPG_ENTITYCONTROLER_HPP

#include <string>

namespace rpg
{
    class Entity;

    /**
     * \brief Base Class to control a entity.
     * \todo Heritage : Socket, AI, Console, mouse + keyboard
     */
    class EntityControler
    {
        public:
            EntityControler(const Entity& entity);
            EntityControler(const EntityControler&) = delete;
            EntityControler& operator=(const EntityControler&) = delete;

            ///\todo void getChoice(const std::string& title,const std::string& msg,???);
            virtual void getChoiceForMove() = 0;
            virtual void getChoiceForMagical() = 0;
            virtual void getChoiceForPhysical() = 0;

        private:
            const Entity& related_entity;
    };
}
#endif
