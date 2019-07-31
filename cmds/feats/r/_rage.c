#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int duration, basemax, newmax, deltahp, feattracker, cooldown, myFlag, BonusFlag;

void rage_me();
void check();

void create() {
   ::create();
   feat_type("instant");
   feat_category("Rampage");
   feat_prereq("Barbarian");
   feat_syntax("rage");
   feat_desc("This feat allows the barbarian to enter a fit of furious rage, boosting their strength, constitution, and will. The ability will last longer, and grow stronger, as the barbarian gains levels. Rage can be turned off by typing rage again. 

%^BOLD%^N.B.%^RESET%^ Being enraged means that you are maddened uncontrollably. This is *not* a state in which you can calmly participate in a normal conversation, undertake delicate tasks, cast offensive spells, solve problems, or pretty much do anything other than shout obscenities andkill things. This power won't work in conjunction with wimilar magical effects, such as rally, transformation, rage, berserker and fell flight.

%^BOLD%^N.B.%^RESET%^ Rage status can be set using prompt. Please see help prompt for more information.

%^BOLD%^See also:%^RESET%^ rage *spells");
   feat_name("rage");
   set_required_for(({"greater rage","mighty rage"}));
   set_target_required(0);
   allow_blind(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
   if(!objectp(ob)) { return 0; }
   if(!ob->is_class("barbarian")) {
      dest_effect();
      return 0;
   }
    return ::prerequisites(ob);
}

int cmd_rage(string str) {
   object feat;
   if(!objectp(TP)) { return 0; }
   if(str) str = lower_case(str);
   if(str != "on" && str != "off")
   {
      tell_object(TP,"Use rage on or rage off.");
      return 1;
   }
   feat = new(base_name(TO));
   feat->setup_feat(TP,str);
   return 1;
}

void execute_feat() {
   object *featobs;
   int i;
   if(!objectp(caster)) 
   {
      dest_effect();
      return;
   }
   /*if(!FEATS_D->is_active(caster,"rage"))
   {
      if((int)caster->query_property("using rage") > time())
      {
         tell_object(caster,"%^BOLD%^You can't try to rage again so soon.%^RESET%^");
      }
   dest_effect();
   return;
   }*/
   if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
   {
      caster->send_paralyzed_message("info",caster);
      dest_effect();
      return;
    }
   ::execute_feat();
   switch(arg)
   {
      case "off":
         if(!caster->query_property("raged"))
         {
            tell_object(caster,"%^RED%^You are not currently raged.%^RESET%^");
            dest_effect();
            break;
         }
         tell_object(caster,"%^RED%^You struggle to catch your breath as you try to yank yourself away from your murderous reverie.%^RESET%^");
         dest_effect();
         break;
      case "on":
         if(caster->query_property("raged"))
         {
            tell_object(caster,"%^RED%^You are already raging.%^RESET%^");
            dest_effect();
            break;
         }
         if((int)caster->query_property("using instant feat"))
         {
            tell_object(caster,"%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
            dest_effect();
            break;
         }
         if(caster->query_casting())
         {
            tell_object(caster,"%^BOLD%^You can't rage while you're casting a spell.%^RESET%^");
            dest_effect();
            break;
         }
         /*if((int)caster->query_property("using rage") > time() && !FEATS_D->usable_feat(caster,"persistent rage"))
         {*/
         if((int)caster->query_property("using rage") > time()){
            tell_object(caster,"%^BOLD%^You can't try to rage again so soon.%^RESET%^");
            dest_effect();
            break;
         }
         else{
            tell_object(caster,"%^RED%^The world takes on a tinge of red as you are overcome by an insatiable desire to see your enemies rendered into a bloody pulp.%^RESET%^");
            tell_room(place,"%^RED%^"+caster->QCN+" growls fiercely as "+caster->QS+" transforms into a homicidal maniac.%^RESET%^",caster);
            caster->set_property("using instant feat",1);
            call_out("rage_me",ROUND_LENGTH);
            return;
         }
   }      
}

void rage_me()
{
   string *mytempfeats=({});
   if(!objectp(caster)) 
   {
        dest_effect();
        return;
   }
   caster->remove_property("using instant feat");
   ::execute_attack();
   duration = 250 + ((int)caster->query_guild_level("barbarian")*20);
   basemax = caster->query_max_hp();
   myFlag = sizeof(caster->query_classes());
   if(FEATS_D->usable_feat(caster,"mighty rage"))
   {    
        if(myFlag == 1)
        { 
            caster->set_property("rage bonus", 1);
            caster->add_stat_bonus("strength",10);
            caster->add_stat_bonus("constitution",10);
            caster->add_saving_bonus("will",4);
            caster->add_ac_bonus(-2);
        }
        else 
        {
            caster->set_property("rage bonus", 2);
            caster->add_stat_bonus("strength",5);
            caster->add_stat_bonus("constitution",5);
            caster->add_saving_bonus("will",3);
            caster->add_ac_bonus(-4);
        }      
        caster->use_stamina(roll_dice(1,6));
      if(pointerp(caster->query_temporary_feats()))
      {
        if(member_array("regeneration",(string*)caster->query_temporary_feats()) == -1)
        {
            caster->add_temporary_feat("regeneration");
            caster->set_property("rage feat tracker", 1);
        }
      }
   }
   else if(FEATS_D->usable_feat(caster,"greater rage"))
   {
       if(myFlag == 1)
       {
            caster->set_property("rage bonus", 3);
            caster->add_stat_bonus("strength",6);
            caster->add_stat_bonus("constitution",6);
            caster->add_saving_bonus("will",3);
            caster->add_ac_bonus(-2);
            //caster->add_attack_bonus(8);
            //caster->add_damage_bonus(8);
            caster->use_stamina(roll_dice(1,6));
        }
        else
        {
            caster->set_property("rage bonus", 4);
            caster->add_stat_bonus("strength",3);
            caster->add_stat_bonus("constitution",3);
            caster->add_saving_bonus("will",2);
            caster->add_ac_bonus(-4);
        }
   }
   else
   {
        if(myFlag == 1)
        {
            caster->set_property("rage bonus", 5);
            caster->add_stat_bonus("strength",4);
            caster->add_stat_bonus("constitution",4);
            caster->add_saving_bonus("will",2);
            caster->add_ac_bonus(-2);
            //caster->add_attack_bonus(4);
            //caster->add_damage_bonus(4);
            caster->use_stamina(roll_dice(1,6));
        }
        else
        {
            caster->set_property("rage bonus", 6);
            caster->add_stat_bonus("strength",2);
            caster->add_stat_bonus("constitution",2);
            caster->add_saving_bonus("will",1);
            caster->add_ac_bonus(-4);
        }
   }
   
   cooldown = duration/2;

   if(FEATS_D->usable_feat(caster,"spirit warrior"))
   {
       cooldown/=3;
       if(myFlag == 1)
       {
           caster->set_missChance(caster->query_missChance()+ 33);
       }
       else 
       {
           caster->set_missChance(caster->query_missChance()-33);
       }      
   }
   if(caster->query_property("using rage"))
   {
      caster->remove_property("using rage");
   }
   caster->set_property("using rage",(time() + cooldown));
   caster->set_property("raged",1);
   caster->set_property("added short",({" %^RED%^(enraged)%^RESET%^"}));
   newmax = caster->query_max_hp();
   deltahp = newmax - basemax;
   if(deltahp < 0) deltahp = 0;
   caster->add_extra_hp(deltahp);
   call_out("check",ROUND_LENGTH);
   call_out("dest_effect",duration);
   caster->set_property("active_feats", ({TO}));
   //Need to test whether or not the following works correctly - Octothorpe 1/31/16
   /*if(!FEATS_D->usable_feat(caster,"persistent rage"))
   {
      call_out("dest_effect",duration);
   }*/
   return;
}

void check()
{
   if(!objectp(caster))
   {
      dest_effect();
      return;
   }
   /*"Inspired" by the rage cleric spell =P - Octothorpe 1/27/16*/
   if(!random(10))
   {
       tell_object(caster,"%^RED%^Bloodlust fills your mind.%^RESET%^");
   }
   if(caster->is_in_combat() && (!random(4)))
   {
      switch(random(100))
      {
         case 0..95:
            break;
         case 96:
            tell_object(caster,"%^RED%^Your insatiable bloodlust quickens your reflexes offering you the opportunity to make another attack!");
            tell_room(place,"%^RED%^"+caster->QCN+"'s attacks become a frenzied blur.",caster);
            caster->execute_attack();
            if(!random(5))
            {
               if(!random(4) || myFlag == 1) caster->execute_attack();
            }
            if(FEATS_D->usable_feat(caster,"greater rage"))
            {
               caster->execute_attack();
               if(!random(2) && myFlag == 1)
               {
                  caster->execute_attack();
               }
            }
            break;
         case 97:
            break;
         case 98:
            break;
         case 99:
            break;
            
      }
   }
   call_out("check",ROUND_LENGTH);
}

void dest_effect()
{
    remove_call_out("check");
    if(!objectp(caster)) 
    {
        ::dest_effect();
        remove_feat(TO);
        return;
    }
    if(caster->query_property("raged"))
    {
        newmax = caster->query_max_hp();
        BonusFlag = (int)caster->query_property("rage bonus");
        feattracker = (int)caster->query_property("rage feat tracker");
        caster->remove_property("rage bonus");
        caster->remove_property("rage feat tracker");
        switch(BonusFlag)
        {
            case 1:
                caster->add_stat_bonus("strength",-10);
                caster->add_stat_bonus("constitution",-10);
                caster->add_saving_bonus("will",-4);
                //caster->add_attack_bonus(-12);
                //caster->add_damage_bonus(-12);
                caster->add_ac_bonus(2);
                break;
            case 2:
                caster->add_stat_bonus("strength",-5);
                caster->add_stat_bonus("constitution",-5);
                caster->add_saving_bonus("will",-3);
                caster->add_ac_bonus(4);
                break;
            case 3:
                caster->add_stat_bonus("strength",-6);
                caster->add_stat_bonus("constitution",-6);
                caster->add_saving_bonus("will",-3);
                //caster->add_attack_bonus(-8);
                //caster->add_damage_bonus(-8);
                caster->add_ac_bonus(2);
                caster->use_stamina(50);
                break;
            case 4:
                caster->add_stat_bonus("strength",-3);
                caster->add_stat_bonus("constitution",-3);
                caster->add_saving_bonus("will",-2);
                caster->add_ac_bonus(4);
                caster->use_stamina(50);
                break;
            case 5:
                caster->add_stat_bonus("strength",-4);
                caster->add_stat_bonus("constitution",-4);
                caster->add_saving_bonus("will",-2);
                //caster->add_attack_bonus(-4);
                //caster->add_damage_bonus(-4);
                caster->add_ac_bonus(2);
                caster->use_stamina(35);
                break;
            case 6:            
                caster->add_stat_bonus("strength",-2);
                caster->add_stat_bonus("constitution",-2);
                caster->add_saving_bonus("will",-1);
                caster->add_ac_bonus(4);
                caster->use_stamina(35);
                break;                        
        }

        if(FEATS_D->usable_feat(caster,"spirit warrior"))
        {
            caster->set_missChance(caster->query_missChance()-33);
        }

        basemax = caster->query_max_hp();
        deltahp = newmax - basemax;
        caster->add_extra_hp(-1*deltahp);
        if((int)caster->query_extra_hp() < 0)
        {
            caster->add_extra_hp(-1*(int)caster->query_extra_hp());
        }
        if(feattracker == 1)
        {
            caster->remove_temporary_feat("regeneration");
            feattracker = 0;
        }  
        caster->remove_property("raged");
        caster->remove_property_value("added short",({" %^RED%^(enraged)%^RESET%^"}));
        tell_object(caster,"%^RED%^The overwhelming feeling of rage slips away and you are left feeling utterly exhausted.%^RESET%^");
        tell_room(place,"%^RED%^"+caster->QCN+" shudders violently for a moment and then starts panting and sweating profusely.%^RESET%^",caster);
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}

