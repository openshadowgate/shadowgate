#include <std.h>
#include "../elf.h"
inherit "/d/common/obj/armour/helm.c";

void create()
{
    ::create();
    set_name("shepard's rest");
    set_short("%^RESET%^%^CYAN%^Shepard's Rest%^RESET%^");
    set_obvious_short("%^RESET%^%^CYAN%^Wool hats%^RESET%^");
    set_id(({"shepard's rest","hat","silvered helm"}));
    set_long(
        "This hat is made from magic wool.  It is thick and "+
        "warm.  It has several elven runes sewn into it that"+
        " shine with a magic aura.  There are two cloth "+
        "animal ears sewn into it.");
        
    set_value(1000);
    set_size(-1);
    set_property("enchantment",4+random(2));
    set_item_bonus("bonus_spell_slots_4",1);
    set_remove((:TO,"remove_func":));
    set_wear( (:TO,"wear_func":) );
    set_struck((:TO,"strike_func":));
}
int remove_func(){
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s hat shimmers "+
           "as "+ETO->QS+" removes it.",ETO);
    }
    tell_object(ETO,"%^CYAN%^Your hat shimmers as you "+
      "remove it.");
        return 1;
}
int wear_func(){

   if(objectp(ETO) && ETO->query_property("evil item")){    
   tell_object(ETO,"The hat rejects the evil items you are wearing.");
       return 0;
   }
 
   
  tell_object(ETO,"%^CYAN%^The hat's ears "+
          "%^BOLD%^twitch%^RESET%^%^CYAN%^ as it settles on your head.");
  tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s hat ears %^BOLD%^twitch "+
         "%^RESET%^%^CYAN%^on "+ETO->QP+" head.",ETO);
          return 1;
          
   
}
int strike_func(int damage, object what, object who){
    object sheep;
    if(!present("sheep",EETO)){
        sheep = new(MON"sheep");
        sheep->move(EETO);
        ETO->add_protector(sheep);
        ETO->add_follower(sheep);
        sheep->ownerz(ETO);
        sheep->force_me("hop "+ETO->query_race());
    }


    return damage;
 }
}
