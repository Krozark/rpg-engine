#include <rpg-engine/Dice.hpp>
#include <rpg-engine/random.hpp>

namespace rpg
{
    Dice::Dice(Type t,int n,int ma,int mi) : type(t), nb(n), max(ma), min(mi)
    {
    }

    int Dice::roll()
    {
        int res = 0;
        int lance = 0;
        switch(type)
        {
            case Type::Normal:
            {
                while(lance++<nb)
                    res += random(min,max);
            }break;
            case Type::Augmente :
            {
                const int m = max/2;
                while(lance++<nb)
                {
                    int tmp = random(1,max);
                    res += tmp>m?tmp:m;
                }
            }break;
            case Libre:
            {
                int mod = 0;//-1 => echec, 0 = statr, 1 => réusite, 2.. => stop
                while(mod <2)
                {
                    int tmp = random(1,100);
                    if (mod == -1)
                    {
                        res -= 101-tmp;
                        if(tmp>min)
                            mod = 2;
                    }
                    else if(mod == 0)
                    {
                        if(tmp<=min)
                        {
                            mod = -1;
                            res -= 101-tmp;
                        }
                        else if(tmp>= max)
                        {
                            mod = 1;
                            res += tmp;
                        }
                        else
                        {
                            mod = 2;
                            res += tmp;
                        }
                    }
                    else if (mod == 1)
                    {
                        res += tmp;
                        if(tmp<max)
                            mod=2;
                    }
                }
            }break;
            case Type::Double :
            {
                if(random(min,max) == random(min,max))
                    res = false;
                else
                    res = true;
            }break;
            case Type::Condition :
            {
                while(lance++<nb)
                    res += random(1,max);

                res = res>=min?true:false;
            }break;
            default :
            {
                res=false;
            }
            break;
        }
    }
}
