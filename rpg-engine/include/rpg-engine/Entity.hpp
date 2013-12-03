#ifndef RPG_ENTITY_HPP
#define RPG_ENTITY_HPP

namespace rpg
{
    class EntityTurn;

    class Entity
    {
        public:
            Entity();
            Entity(const Entity&) = delete;
            Entity& operator=(const Entity&) = delete;


            inline int getMouvement()const{return mouvement;};

        protected:
            friend class EntityTurn;
            void onStartTurn(){};
            void onEndTurn(){};

        private:
            int mouvement;
    };
}
#endif
