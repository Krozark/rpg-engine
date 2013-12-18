#include <rpg-engine/StackTurn.hpp>

namespace rpg
{
    StackTurn::StackTurn() : _size(0)
    {
    }

    void StackTurn::push(Token&& token)
    {
        stack.emplace_back(token);
    }

    void StackTurn::pop()
    {
        stack.pop_front();
    }

    Token& StackTurn::top()
    {
        return stack.back();
    }

    void StackTurn::clear()
    {
        stack.clear();
    }

    unsigned int StackTurn::clearAllOf(Entity& owner)
    {
        unsigned int nb=0;
        ///\todo TODO
        return nb;
    }

}
