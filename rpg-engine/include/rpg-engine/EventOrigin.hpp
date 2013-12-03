#ifndef RPG_EVENTORIGIN_HPP
#define RPG_EVENTORIGIN_HPP

#include <string>

namespace rpg
{
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
            
            int max_evasion_nb;///< number of possible evasion


        protected:

            bool recvDommage(EventOrigin& src,int dmg);

            /**
             * \result true if can take dommage (not escaped)
             */
            bool recvOrigin(EventOrigin& src);

            /**
             * \result false if the counter attack is  evaded, true is attack send
             */
            bool sendCounterAttack(EventOrigin& dest);


        private:

            std::string name;
            int dodge;
    };
}
#endif
