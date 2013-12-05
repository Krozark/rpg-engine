#ifndef RPG_COLORS_HPP
#define RPG_COLORS_HPP

/************************ COLORS *****************************/
#define RPG_COLOR_RED  	"\033[31m" ///< couleur rouge pour le terminal
#define RPG_COLOR_GREEN   	"\033[32m" ///< couleur vert pour le terminal
#define RPG_COLOR_YELLOW  	"\033[33m" ///< couleur jaune
#define RPG_COLOR_BLUE  	"\033[34m" ///< couleur bleu
#define RPG_COLOR_MAGENTA "\033[35m" ///< couleur magenta
#define RPG_COLOR_LMAGENTA "\033[01;35m" ///<couleur magenta claire
#define RPG_COLOR_BLUE2 "\033[36m" ///< couleur bleu
#define RPG_COLOR_GREY "\033[31m" ///< couleur pour les commentaires
#define RPG_COLOR_DEFAULT 	"\033[00m" ///< couleur par défaut du terminal


#define RPG_COLOR_QUESTION RPG_COLOR_BLUE
#define RPG_COLOR_ERROR RPG_COLOR_RED
#define RPG_COLOR_WARNING RPG_COLOR_GREY
#define RPG_COLOR_TITLE RPG_COLOR_YELLOW

#define RPG_H1(txt) std::cout<<RPG_COLOR_TITLE<<"=======\t "<<txt<<" \t======="<<RPG_COLOR_DEFAULT<<std::endl
#define RPG_H2(txt) std::cout<<RPG_COLOR_TITLE<<"+++ "<<txt<<" +++"<<RPG_COLOR_DEFAULT<<std::endl
#define RPG_H3(txt) std::cout<<RPG_COLOR_TITLE<<"--- "<<txt<<" ---"<<RPG_COLOR_DEFAULT<<std::endl
#define RPG_QUESTION(txt) std::cout<<RPG_COLOR_QUESTION<<txt<<RPG_COLOR_DEFAULT<<"\n>"
#define RPG_WARNING(txt) std::cout<<"/?\\ " RPG_COLOR_WARNING<<txt<<" /?\\" RPG_COLOR_DEFAULT<<std::endl;
#define RPG_ERROR(txt) std::cout<<"/!\\ " RPG_COLOR_ERROR<<txt<<" /!\\" RPG_COLOR_DEFAULT<<std::endl;


#endif
