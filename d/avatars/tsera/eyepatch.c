#include <std.h>

inherit ARMOUR;
int uses;
int uses1;
int uses2;

object place;
void create(){
   ::create();
    set_id(({"eyepatch","eye patch","patch"}));
    set_name("The pirates patch");
    set_short("%^BOLD%^%^GREEN%^A %^RESET%^%^GREEN%^j%^BOLD%^ad%^RESET%^%^GREEN%^e %^RED%^encrusted %^CYAN%^eyepatch%^RESET%^");
    set_obvious_short("%^BOLD%^%^GREEN%^A %^RESET%^%^GREEN%^j%^BOLD%^ad%^RESET%^%^GREEN%^e %^RED%^encrusted %^CYAN%^eyepatch%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This eyepatch is made of a soft leather material and is adorned with jewels."
" The eyepatch is made up of three different kinds of gems: %^WHITE%^diamonds%^BLACK%^, onyx and"
" %^RED%^rubies%^BLACK%^. The design is in the shape of a %^RED%^red rose %^BLACK%^with a %^WHITE%^silver"
" %^CYAN%^whip %^BLACK%^entwined around it. Each gem looks like it could be removed.");
    set_type("leather");
    set_limbs(({"head"}));
    set_ac(0);
    set_property("enchantment",2);
    set_weight(3);
    set_size(2);
    set("value",200);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"unwearme":));
    uses=random(9)+10;
    uses1=random(10)+5;
    uses2=random(10)+10;
}
void init(){
    ::init();
    add_action("use","use");
}
int use(string str){
   if(!str) notify_fail("What are you trying to do.  You mean use a gem?");
   if(str == "ruby"||str=="a ruby"||str=="rubies"){             
      tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETOQCN+" pulls a ruby from the eyepatch and smashes it into the ground in front of "+ETO->query_objective()+"!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^RED%^You pull a ruby from your eyepatch and smash it into the ground in front of you!%^RESET%^");
      new("/cmds/wizard/_wall_of_fire")->use_spell(ETO,"me",10,100);      
      uses--;
      return 1;
   }
   place = environment(ETP);
   if(str == "diamond"||str=="a diamond"||str=="diamonds"){             
      tell_room(environment(ETO),"%^BOLD%^"+ETOQCN+" pulls a diamond from "+ETO->query_possessive()+" eyepatch and tosses it into the air where it shatters into a million sparkling pieces that rain down around you!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^You pull a diamond from your eyepatch and toss it into the air.  It shatters into a million sparkling fragments that rain down around you!%^RESET%^");
      new("/cmds/wizard/_dispel_magic.c")->use_spell(ETO,place,45,100);
      uses1 --;
      return 1;
   }
   if(str == "onyx"||str=="an onyx"||str=="a onyx"){             
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" takes an onyx from "+ETO->query_possessive()+" eyepatch and it turns into a globe of darkness!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^You take an onyx from your eyepatch and it turns into a globe of darkness!%^RESET%^");
      new("/cmds/wizard/_darkness")->use_spell(ETO,ETO,50,100);      
      uses2--;
      return 1;
   }
}

int wearme(){   
   if(ETO->query_lowest_level() < 30){
      tell_object(ETO,"You are not experienced enough to wear this!");
      return 0;
      }
      tell_object(ETO,"%^BOLD%^%^BLACK%^You secure the eyepatch over your left eye and feel your right eye suddenly become more tuned to all that it sees.");
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+TPQCN+" slides the eyepatch over "+ETO->query_possessive()+" left eye.",ETO);
      ETO->add_sight_bonus(3);
      return 1;
}

int unwearme()
{
   tell_object(ETO,"%^BOLD%^%^BLACK%^As you slide the eyepatch off, you realize that not only is your left eye weaker from not being used, but your right eye relaxes as well.");
   ETO->add_sight_bonus(-3);
   return 1;
}

