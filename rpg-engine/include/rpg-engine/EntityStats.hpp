#ifndef RPG_ENTITYSTATS_HPP
#define RPG_ENTITYSTATS_HPP

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
