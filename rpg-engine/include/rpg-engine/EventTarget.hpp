#ifndef RPG_EVENTTARGET_HPP
#define RPG_EVENTTARGET_HPP

#include <string>

namespace rpg
{
    class EventTarget
    {
        public:
            explicit EventTarget(const std::string& name,int dodge);

            EventTarget(const EventTarget&) = delete;
            EventTarget& operator=(const EventTarget&) = delete;

            virtual int getEvasion();

            virtual int getDommage();

            /**
             * \result false if the counter attack is  evaded, true is attack send
             */
            bool attack(EventTarget& other);
            
            int max_evasion_nb;///< number of possible evasion


        protected:

            bool recvDommage(EventTarget& src,int dmg);

            /**
             * \result true if can take dommage (not escaped)
             */
            bool recvTarget(EventTarget& src);

            /**
             * \result false if the counter attack is  evaded, true is attack send
             */
            bool sendCounterAttack(EventTarget& dest);


        private:

            std::string name;
            int dodge;
    };
}
#endif
