#ifndef RPG_ENTITYSTATS_HPP
#define RPG_ENTITYSTATS_HPP

#include <rpg-engine/Dice.hpp>

namespace rpg
{
    class EntityStats
    {
        public:
            EntityStats(const EntityStats&) = delete;
            EntityStats& operator=(const EntityStats&) = delete;

            EntityStats();
            EntityStats(int pv,int pi,int fat,int frc,int intel,int def,int mdef,int esq, int dex,int vatq,int chc,int chrm,int mvt);
            
            EntityStats(EntityStats&&) = default;
            EntityStats& operator=(EntityStats&&) = default;
            
            inline int getPv()const {return pv;}
            inline int getPi()const {return pi;}
            inline int getFatigue()const {return fat;}

            inline int getFrc()const {return frc;}
            inline int getInt()const {return intel;}
            inline int getDef()const {return def;}
            inline int getMdef()const {return mdef;}
            inline int getEsq()const {return esq;}
            inline int getDex()const {return dex;}
            inline int getVatq()const {return vatq;}
            inline int getChc()const {return chc;}
            inline int getChrm()const {return chrm;}

            inline int getMvt()const {return mvt;}

            EntityStats operator+(const EntityStats& other)const;
            EntityStats operator-(const EntityStats& other)const;

            EntityStats operator+(int val)const;
            EntityStats operator-(int val)const;

            ///\todo Dice getDiceXXX();
            ///\todo static Dice getDiceXXX(int value);
            //turn_esq = tmp_stats.getEsqNb();
            //turn_atq = tmp_stats.getAtqNb();
            
            static Dice getDiceRef(int value);
            static Dice getDiceRefLibre(int value);
            static Dice getDiceFrc(int value); 
            static Dice getDiceInt(int value);
            static Dice getDiceDef(int value);
            static Dice getDiceMdef(int value);
            static Dice getDiceEsq(int value);
            static Dice getDiceDex(int value);
            static Dice getDiceChc(int value);
            static Dice getDiceChrm(int value);

            static int getNbEsq(int value);
            static int getNbAtq(int value);

            Dice getDiceFrc()const; 
            Dice getDiceInt()const;
            Dice getDiceDef()const;
            Dice getDiceMdef()const;
            Dice getDiceEsq()const;
            Dice getDiceDex()const;
            Dice getDiceChc()const;
            Dice getDiceChrm()const;


            int getNbEsq()const;
            int getNbAtq()const;

        protected:

            int pv,
                pi,
                fat,

                frc,
                intel,
                def,
                mdef,
                esq,
                dex,
                vatq,
                chc,
                chrm,

                mvt;

        private:
    };
}
#endif
