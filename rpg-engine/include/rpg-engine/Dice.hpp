#ifndef RPG_DICE_HPP
#define RPG_DICE_HPP

namespace rpg
{
    class Dice
    {
        public:
            Dice(const Dice&) = delete;
            Dice& operator=(const Dice&) = delete;

            Dice(Dice&&) = default;
            Dice& operator=(Dice&&) = default;

            enum Type{Normal=0,Augmente,Libre,Double,Condition};

            Dice(Type type,int nb,int max,int min);

            int roll();


        protected:
            const int min;
            const int max;
            const int nb;
            const Type type;

    };
}
#endif
