#include <rpg-engine/EntityControlerConsol.hpp>

#include <rpg-engine/Entity.hpp>
#include <rpg-engine/colors.hpp>

#include <iostream>



namespace rpg
{
    EntityControlerConsol::EntityControlerConsol(Entity& entity) : EntityControler(entity)
    {
    }

    void EntityControlerConsol::getChoiceForMove()
    {
        RPG_H2("Mouvement : Que voulez vous faire");
        char c = 0;
        while(c==0 /** \todo and as mouvement */)
        {
            RPG_QUESTION(
                " 1_ \n"
                "6/ \\2\n"
                "5\\_/3\n"
                " 4  \n" 
                "1-6) Bouger dans cette direction\n"
                "S) Lancer un sort\n"
                "Q) Quitter");

            std::cin>>c;

            switch(c)
            {
                /* move */
                case '1' :
                    related_entity.move(0,-1);
                    c=0;
                    break;
                case '2' :
                    related_entity.move(1,-1);
                    c=0;
                    break;
                case '3':
                    related_entity.move(1,0);
                    c=0;
                    break;
                case '4':
                    related_entity.move(0,1);
                    c=0;
                    break;
                case '5':
                    related_entity.move(-1,1);
                    c=0;
                    break;
                case '6':
                    related_entity.move(-1,0);
                    c=0;
                    break;
                /* spells */
                case 's':
                case 'S':
                    std::cout<<RPG_COLOR_WARNING<<"/!\\ Pas implémanté. /!\\"<<RPG_COLOR_DEFAULT<<std::endl;
                    c=0;
                    break;
                /* Quit */
                case 'q':
                case 'Q':
                    break;
                default:
                    std::cout<<RPG_COLOR_ERROR<<"/!\\ Erreur de saisie. /!\\"<<RPG_COLOR_DEFAULT<<std::endl;
                    c = 0;
                    break;
            }
        }

    }

    void EntityControlerConsol::getChoiceForMagical()
    {
    }

    void EntityControlerConsol::getChoiceForPhysical()
    {
    }
}
