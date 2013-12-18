#ifndef RPG_STACKTURN_HPP
#define RPG_STACKTURN_HPP

#include <list>

namespace rpg
{
    class Token{};//< \todo TODO
    class Entity;

    class StackTurn
    {
        public:
            StackTurn();
            StackTurn(const StackTurn&) = delete;
            StackTurn& operator=(const StackTurn&) = delete;


            void push(Token&&);
            void pop();
            Token& top();
            void clear();

            unsigned int clearAllOf(Entity& owner);

            inline unsigned int size()const{return _size;}

        protected:
        private:
            unsigned int _size;
            std::list<Token> stack;
    };
}
#endif
