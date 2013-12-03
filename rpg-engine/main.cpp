
#include <rpg-engine/EventOrigin.hpp>
#include <rpg-engine/random.hpp>

#include <rpg-engine/Turn.hpp>
#include <rpg-engine/Entity.hpp>

int main(int argc,char* argv[])
{
    rand_init();

    rpg::EventOrigin A("A",70),
    B("B",50);

    //A.max_evasion_nb = 1;
    //B.max_evasion_nb = 10;

    A.attack(B);

    rpg::Entity C;
    rpg::Turn turn(C);
    turn.initBasic();
    turn.start();
    return 0;
}
