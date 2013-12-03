
#include <rpg-engine/EventTarget.hpp>
#include <rpg-engine/random.hpp>

int main(int argc,char* argv[])
{
    rand_init();

    rpg::EventTarget A("A",70),
    B("B",50);

    A.max_evasion_nb = 1;
    B.max_evasion_nb = 10;

    A.attack(B);
    return 0;
}
