
#include <rpg-engine/EventOrigin.hpp>
#include <rpg-engine/random.hpp>

#include <rpg-engine/TurnGameBased.hpp>
#include <rpg-engine/Entity.hpp>
#include <rpg-engine/Point.hpp>

int main(int argc,char* argv[])
{
    rand_init();

    //rpg::EventOrigin A("A",70),
    //B("B",50);

    //A.max_evasion_nb = 1;
    //B.max_evasion_nb = 10;

    //A.attack(rpg::EventOrigin::type_atk::PHYSICAL,B);


    rpg::math::Point<int> a(0,0),
        b(1,1),
        c(2,0),
        d(10,5),
        e(-2,0),
        f(-10,-5);

    std::cout<<rpg::math::Point<int>::getHexDistance(a,a)<<std::endl;
    std::cout<<rpg::math::Point<int>::getHexDistance(a,b)<<std::endl;
    std::cout<<rpg::math::Point<int>::getHexDistance(a,c)<<std::endl;
    std::cout<<rpg::math::Point<int>::getHexDistance(a,d)<<std::endl;
    std::cout<<rpg::math::Point<int>::getHexDistance(a,e)<<std::endl;
    std::cout<<rpg::math::Point<int>::getHexDistance(a,f)<<std::endl;
    std::cout<<rpg::math::Point<int>::getHexDistance(e,e)<<std::endl;

    /*rpg::Entity C("C",40)
        ,D("D",50)
        ,E("E",70);

    rpg::TurnGameBased fight;
    C.setBattle(fight);*/
    //fight.add(D);
    //fight.add(E);

    //fight.start();

    return 0;
}
