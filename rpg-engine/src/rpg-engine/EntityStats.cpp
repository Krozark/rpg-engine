#include <rpg-engine/EntityStats.hpp>

namespace rpg
{
    
    EntityStats::EntityStats() :
        pv(0),pi(0),fat(0),
        frc(0),intel(0),def(0),mdef(0),esq(0),dex(0),vatq(0),chc(0),chrm(0),
        mvt(0)
    {
    }
    
    EntityStats::EntityStats(int PV,int PI,int FAT,int FRC,int INTEL,int DEF,int MDEF,int ESQ, int DEX,int VATQ,int CHC,int CHRM, int MVT) :
        pv(PV),pi(PI),fat(FAT),
        frc(FRC),intel(INTEL),def(DEF),mdef(MDEF),esq(ESQ),dex(DEX),vatq(VATQ),chc(CHC),chrm(CHRM),
        mvt(MVT)
    {
    }

    EntityStats EntityStats::operator+(const EntityStats& other)const
    {
        return EntityStats(pv + other.pv,
                           pi + other.pi,
                           fat + other.fat,
                           frc + other.frc,
                           intel + other.intel,
                           def + other.def,
                           mdef + other.mdef,
                           esq + other.esq,
                           dex + other.dex,
                           vatq + other.vatq,
                           chc + other.chc,
                           chrm + other.chrm,
                           mvt + other.mvt
                           );
    }

    EntityStats EntityStats::operator-(const EntityStats& other)const
    {
        return EntityStats(pv - other.pv,
                           pi - other.pi,
                           fat - other.fat,
                           frc - other.frc,
                           intel - other.intel,
                           def - other.def,
                           mdef - other.mdef,
                           esq - other.esq,
                           dex - other.dex,
                           vatq - other.vatq,
                           chc - other.chc,
                           chrm - other.chrm,
                           mvt - other.mvt
                           );
    }

    EntityStats EntityStats::operator+(int val)const
    {
        return EntityStats(pv,
                           pi,
                           fat,
                           frc + val,
                           intel + val,
                           def + val,
                           mdef + val,
                           esq + val,
                           dex + val,
                           vatq + val,
                           chc + val,
                           chrm + val,
                           mvt
                           );
    }

    EntityStats EntityStats::operator-(int val)const
    {
        return EntityStats(pv,
                           pi,
                           fat,
                           frc - val,
                           intel - val,
                           def - val,
                           mdef - val,
                           esq - val,
                           dex - val,
                           vatq - val,
                           chc - val,
                           chrm - val,
                           mvt
                           );
    }

    Dice EntityStats::getDiceRef(int value)
    {
        int nb;
        int min;
        int max;
        if(value <= 0)
        {
            nb=0;
            min=0;
            max=0;
        }
        else if (value <= 3)
        {
            nb=1;
            min=1;
            max=3;
        }
        else if(value <=6)
        {
            nb=1;
            min=1;
            max=4;
        }
        else if(value <=10)
        {
            nb=1;
            min=1;
            max=6;
        }
        else if(value <=18)
        {
            nb=1;
            min=1;
            max=8;
        }
        else if(value <=23)
        {
            nb=1;
            min=1;
            max=10;
        }
        else if(value <=29)
        {
            nb=1;
            min=1;
            max=12;
        }
        else if(value <=36)
        {
            nb=1;
            min=1;
            max=20;
        }
        else if(value <=44)
        {
            nb=1;
            min=1;
            max=40;
        }
        else if(value <=55)
        {
            nb=1;
            min=1;
            max=60;
        }
        else if(value <=70)
        {
            nb=1;
            min=1;
            max=80;
        }
        else
        {
            nb=value/20 - 2;
            min=1;
            max=100;
        }

        return Dice(Dice::Type::Augmente,nb,max,min);
    }

    Dice EntityStats::getDiceRefLibre(int value)
    {
        int nb = 1;
        int min;
        int max;

        if(value <=0)
        {
            int tmp = 16 - value;
            min = tmp<80?tmp:80;
            max = 100;
        }
        else if (value <= 7)
        {
            min = 13;
            max = 100;
        }
        else if(value <12)
        {
            min = 11;
            max = 99;
        }
        else if(value <16)
        {
            min = 9;
            max = 98;
        }
        else if(value <20)
        {
            min = 7;
            max = 97;
        }
        else if(value <27)
        {
            min = 5;
            max = 96;
        }
        else if(value <30)
        {
            min = 5;
            max = 92;
        }
        else if(value <34)
        {
            min = 4;
            max = 90;
        }
        else if(value <38)
        {
            min = 3;
            max = 86;
        }
        else
        {
            min = 5-value/20;
            if(min <1)
                min = 1;
            max = 79-value;
            if(max<2)
                max = 2;
        }
        return Dice(Dice::Type::Libre,nb,max,min);

    }

    Dice EntityStats::getDiceFrc(int value)
    {
        return getDiceRef(value);
    }

    Dice EntityStats::getDiceInt(int value)
    {
        if (value > 20)
            return Dice(Dice::Type::Normal,0,0,0);

        int nb = 2;
        int min = 1;
        int max;

        if(value <= 0)
            max = 3;
        else if( value <= 10)
            max = 6;
        else// if(value <= 20)
            max = 10;

        return Dice(Dice::Type::Double,nb,max,min);
    }

    Dice EntityStats::getDiceDef(int value)
    {
        int nb;
        int min;
        int max;

        if(value <= 0)
        {
            nb=0;
            min=0;
            max=0;
        }
        else if (value <= 3)
        {
            nb=1;
            min=1;
            max=3;
        }
        else if (value <= 7)
        {
            nb=1;
            min=1;
            max=4;
        }
        else if (value <= 13)
        {
            nb=1;
            min=1;
            max=6;
        }
        else if (value <= 20)
        {
            nb=1;
            min=1;
            max=8;
        }
        else if (value <= 28)
        {
            nb=1;
            min=1;
            max=10;
        }
        else if (value <= 35)
        {
            nb=1;
            min=1;
            max=12;
        }
        else if (value <= 40)
        {
            nb=1;
            min=1;
            max=20;
        }
        else if (value <= 50)
        {
            nb=1;
            min=1;
            max=40;
        }
        else if (value <= 60)
        {
            nb=1;
            min=1;
            max=60;
        }
        else if (value <= 70)
        {
            nb=1;
            min=1;
            max=80;
        }
        else
        {
            nb=value/30 - 1;
            min=1;
            max=100;
        }
        return Dice(Dice::Type::Augmente,nb,max,min);
    }

    Dice EntityStats::getDiceMdef(int value)
    {
        return getDiceDef(value);
    }

    Dice EntityStats::getDiceEsq(int value)
    {
        int nb;
        int min;
        int max;

        if(value<=15)
        {
            nb=0;
            min=0;
            max=0;
        }
        else if (value <=17)
        {
            nb=1;
            min=20;
            max=20;
        }
        else if (value <=19)
        {
            nb=1;
            min=19;
            max=20;
        }
        else if (value <=28)
        {
            nb=1;
            min=32 - value/1.4;
            max=20;
        }
        else if (value <=30)
        {
            nb=1;
            min=9;
            max=20;
        }
        else if (value <=35)
        {
            nb=1;
            min=8;
            max=20;
        }
        else if (value <=39)
        {
            nb=1;
            min=7;
            max=20;
        }
        else
        {
            nb=1;
            int tmp = 10 - value/10;
            min=tmp>4?tmp:4;
            max=20;
        }

        return Dice(Dice::Type::Condition,nb,max,min);
    }

    Dice EntityStats::getDiceDex(int value)
    {
        return getDiceRef(value);
    }

    Dice EntityStats::getDiceChc(int value)
    {
        return getDiceRefLibre(value);
    }

    Dice EntityStats::getDiceChrm(int value)
    {
        if(value<0)
            value = -value;
        return getDiceRef(value);
    }

    int EntityStats::getNbEsq(int value)
    {
        int res;
        if (value <=0)
            res = 0;
        else if (value <= 37)
            res = 1;
        else if (value <= 39)
            res = 2;
        else
            res = value / 16;

        return res;
    }

    int EntityStats::getNbAtq(int value)
    {
        return (value==0)?0:(value-1)/8+1;
    }

    Dice EntityStats::getDiceFrc()const
    {
        return getDiceFrc(frc);
    }

    Dice EntityStats::getDiceInt()const
    {
        return getDiceInt(intel);
    }

    Dice EntityStats::getDiceDef()const
    {
        return getDiceDef(def);
    }

    Dice EntityStats::getDiceMdef()const
    {
        return getDiceMdef(mdef);
    }

    Dice EntityStats::getDiceEsq()const
    {
        return getDiceEsq(esq);
    }

    Dice EntityStats::getDiceDex()const
    {
        return getDiceDex(dex);
    }
    
    Dice EntityStats::getDiceChc()const
    {
        return getDiceChc(chc);
    }
    
    Dice EntityStats::getDiceChrm()const
    {
        return getDiceChrm(chrm);
    }


    int EntityStats::getNbEsq()const
    {
        return getNbEsq(esq);
    }

    int EntityStats::getNbAtq()const
    {
        return getNbAtq(vatq);
    }
}
