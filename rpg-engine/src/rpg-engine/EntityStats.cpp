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
}
