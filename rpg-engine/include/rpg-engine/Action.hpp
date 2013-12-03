#ifndef RPG_ACTION_HPP
#define RPG_ACTION_HPP

namespace rpg
{
    /**
     * \brief Class that have to encapsulate all passible action, with there reverse.
     * Usefull for loging, and play with time spells, or chec if some actions have be made
     */
    class Action
    {
        public:
            Action();
            Action(const Action&) = delete;
            Action& operator=(const Action&) = delete;

        protected:

        private:
    };
}
#endif
