#ifndef RPG_ENTITY_HPP
#define RPG_ENTITY_HPP

#include <iostream>

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
            Entity();
            Entity(const Entity&) = delete;
            Entity& operator=(const Entity&) = delete;


            //inline int getMouvement()const{return mouvement;};
            //int getDommage()const;

            //inline bool isAlive()const {return hp>0;}

            friend std::ostream& operator<<(std::ostream& output,const Entity& self);

            void setBattle(TurnGameBased& battle);
            void exitBattle();

            virtual void moveOf(int x,int y) = 0;

        protected:
            /** Helpers **/
            virtual EntityControler& getControler() = 0;
            virtual void print(std::ostream&)const = 0;

            /** Events **/
            virtual void onBeginTurn() = 0;
            virtual void onEndTurn() = 0;

            /** Attrs */
            TurnGameBased* currentBattlefield;

        private:
            friend class EntityTurn;
            friend class TurnPhaseMouvement;
            friend class TurnPhaseMagical;
            friend class TurnPhasePhysical;

            /** Trigger events **/
            void slotBeginTurn(EntityTurn& myturn);
            void slotEndTurn(EntityTurn& myturn);

    };
}
#endif
