#ifndef RPG_ENTITY_HPP
#define RPG_ENTITY_HPP

#include <string>
#include <iostream>

namespace rpg
{
    class EntityTurn;
    class TurnGameBased;

    /**
     * \brief Base class for entity
     * \todo Heritage
     */
    class Entity
    {
        public:
            Entity(const std::string& name,int hp);
            Entity(const Entity&) = delete;
            Entity& operator=(const Entity&) = delete;


            inline int getMouvement()const{return mouvement;};
            int getDommage()const;

            inline bool isAlive()const {return hp>0;}

            friend std::ostream& operator<<(std::ostream& output,const Entity& self);

            void setBattle(TurnGameBased& battle);
            void exitBattle();

        protected:
            friend class EntityTurn;
            void onStartTurn(){};
            void onEndTurn(){};

        private:
            int mouvement;
            std::string name;
            int hp;
            TurnGameBased* currentBattlefield;
            ///\todo Controleur& getControleur() = 0;

    };
}
#endif
