#ifndef RPG_ENTITY_HPP
#define RPG_ENTITY_HPP

namespace rpg
{
    class Turn;

    class Entity
    {
        public:
            Entity();
            Entity(const Entity&) = delete;
            Entity& operator=(const Entity&) = delete;


            inline int getMouvement()const{return mouvement;};

        protected:
            friend class Turn;
            void onStartTurn(){};
            void onEndTurn(){};

        private:
            int mouvement;
    };
}
#endif
