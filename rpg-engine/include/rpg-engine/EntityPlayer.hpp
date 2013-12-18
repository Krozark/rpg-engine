#ifndef RPG_ENTITYPLAYER_HPP
#define RPG_ENTITYPLAYER_HPP

#include <rpg-engine/Entity.hpp>

#include <string>

namespace rpg
{
    class EntityPlayer : public Entity
    {
        public:
            EntityPlayer();
            EntityPlayer(const EntityPlayer&) = delete;
            EntityPlayer& operator=(const EntityPlayer&) = delete;

        protected:
            /** Helpers **/
            virtual EntityControler& getControler();
            virtual void print(std::ostream& output)const;

            /** Events **/
            virtual void onBeginTurn() = 0;
            virtual void onEndTurn() = 0;

        private:
            EntityControler* controler;///<\todo remove it and replace as globale for each clase heritate

            //id
            std::string name;
            int lvl;
            int exp;

            //user                = models.ForeignKey(User,blank=True,null=True)
            //avatar              = models.ImageField(upload_to="/public/uploads",blank=True,null=True)
            //genre               = models.CharField(_('genre'),max_length=1,default='?',choices=(('?','Inconnu'),('M','Masculin'),('F',u'Féminin')))
            //race                = models.ForeignKey(Race,blank=False,null=False,limit_choices_to ={'niveau_min':1})
            //klass               = models.ForeignKey(Class,verbose_name="classe",blank=False,null=False,limit_choices_to={'parent': None})
            //age                 = models.IntegerField(_('age'),blank=False,null=False,default=0)
            //alignement          = models.ForeignKey(Alignement,blank=True,null=True)
            //partie              = models.ForeignKey(Partie,blank=True,null=True)
            //points_stats        = models.IntegerField(_('Points d\'entrainement'),blank=False,null=False,default=0)
            //points_grimoire     = models.IntegerField(_('Points de sorts'),blank=False,null=False,default=0)
            //piece_argent        = models.FloatField(_(u'Pièces d\'argent'),blank=False,null=False,default=100) #100 PC = 10 PA = 1 PO pièce d'argent
            //poids               = models.FloatField(_('poids'),blank=False,null=False,default=0)
            //stats               = models.ForeignKey(Stats, blank=False,null=False,related_name='statsMaxPerso')
            //stats_temp          = models.ForeignKey(Stats, blank=False,null=False,related_name='statsTempPerso')

            //inventaire          = models.ManyToManyField(ObjetNb,blank=True,null=True)
            //equipement        = models.ManyToManyField(Equipement,blank=True,null=True)

            //grimoire            = models.ManyToManyField(NiveauSort,blank=True,null=True)

            //familier_principale = models.ForeignKey(InstanceFamiler,null=True,blank=True)


    };
}
#endif
