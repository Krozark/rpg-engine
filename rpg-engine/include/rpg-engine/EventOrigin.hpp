#ifndef RPG_EVENTORIGIN_HPP
#define RPG_EVENTORIGIN_HPP

#include <string>

namespace rpg
{
    /**
    * \brief Class of testing
    */
    class EventOrigin
    {
        public:
            explicit EventOrigin(const std::string& name,int dodge);

            EventOrigin(const EventOrigin&) = delete;
            EventOrigin& operator=(const EventOrigin&) = delete;

            int getEvasion()const;

            int getDommage()const;

            /**
             * \result false if the counter attack is  evaded, true is attack send
             */
            bool attack(char type,EventOrigin& other);

            enum type_atk {PHYSICAL=0,
                           MAGICAL=1<<1,
                           HYBRID=1<<2};
            


        protected:

        virtual void onStartTurn(){};
        virtual void onEndTurn(){};

        /**
        * \result the dommage modifier (substract to dommage)
        */
        virtual int onRecvDommage(char type,int dommage,const EventOrigin& src,int rank,int element){};

        virtual void onRecvTarget(char type){};

        virtual void onSendDommage(){};

        virtual void onEvasion(){};

        virtual void onMove(int x,int y){/*t = getTrap(x,y);if(t){t.exec(*this);}*/};


        private:

            bool recvDommage(char type,EventOrigin& src,int dmg);

            /**
             * \result true if can take dommage (not escaped)
             */
            bool recvTarget(char type,EventOrigin& src);

            bool sendCounterAttack(char type,EventOrigin& dest);

            std::string name;
            int dodge;
            int max_evasion_nb;///< number of possible evasion
    };
}
#endif
