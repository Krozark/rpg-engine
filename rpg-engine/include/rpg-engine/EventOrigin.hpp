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

            virtual int getEvasion();

            virtual int getDommage();

            /**
             * \result false if the counter attack is  evaded, true is attack send
             */
            bool attack(EventOrigin& other);
            


        protected:

        virtual void onStartTurn(){};
        virtual void onEndTurn(){};

        /**
        * \result the dommage modifier (substract to dommage)
        */
        virtual int onRecvDommage(int dommage,const EventOrigin& src,int rank,int element){};
        virtual int onRecvDommageMagic(int dommage,const EventOrigin& src,int rank,int element){};
        virtual int onRecvDommagePhysic(int dommage,const EventOrigin& src,int rank, int element){};
        virtual int onRecvDommageHybrid(int dommage,const EventOrigin& src,int rank,int element){};

        virtual void onRecvTarget(){};
        virtual void onRecvTargetMagic(){};
        virtual void onRecvTargetPhysic(){};
        virtual void onRecvTargetHybrid(){};

        virtual void onSendDommage(){};
        virtual void onSendDommageMagic(){};
        virtual void onSendDommagePhysic(){};
        virtual void onSendDommageHybrid(){};

        virtual void onEvasion(){};

        virtual void onMove(int x,int y){/*t = getTrap(x,y);if(t){t.exec(*this);}*/};


        private:

            bool recvDommage(EventOrigin& src,int dmg);

            /**
             * \result true if can take dommage (not escaped)
             */
            bool recvTarget(EventOrigin& src);

            /**
             * \result false if the counter attack is  evaded, true is attack send
             */
            bool sendCounterAttack(EventOrigin& dest);

            std::string name;
            int dodge;
            int max_evasion_nb;///< number of possible evasion
    };
}
#endif
