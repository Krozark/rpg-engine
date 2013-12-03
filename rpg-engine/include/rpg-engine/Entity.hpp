#ifndef RPG_ENTITY_HPP
#define RPG_ENTITY_HPP

#include <string>
#include <iostream>

#include <rpg-engine/Point.hpp>

namespace rpg
{
    class EntityTurn;
    class TurnPhaseMouvement;
    class TurnPhaseMagical;
    class TurnPhasePhysical;

    class TurnGameBased;
    class EntityControler;

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

            void move(int x,int y);

        protected:
            friend class EntityTurn;
            friend class TurnPhaseMouvement;
            friend class TurnPhaseMagical;
            friend class TurnPhasePhysical;

            void onStartTurn();///<\todo as virtual
            void onEndTurn();///<\todo as virtual

            EntityControler& getControler();///<\todo as virtual

        private:
            int mouvement;
            std::string name;
            int hp;
            TurnGameBased* currentBattlefield;

            math::Point<int> position;


            EntityControler* controler;///<\todo remove it and replace as globale for each clase heritate
    };
}
#endif
