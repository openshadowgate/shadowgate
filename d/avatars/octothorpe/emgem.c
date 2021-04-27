//Octothorpe (12/23/08)
//Underdark Mining Caverns, Dragon Scale Cloak Gem Mob
//Based on Faithful Phantom Guardians mobs
///d/magic/mon/pbat.c

#include <std.h>
#include <daemons.h>
inherit "/d/magic/mon/pbat";

void create(){
   ::create();
   set_name("emerald gem");
   set_short("%^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l"+
      "%^RESET%^%^GREEN%^d g%^BOLD%^e%^RESET%^%^GREEN%^m%^RESET%^");
   set_id(({"emgem"}));
   set_long("%^BOLD%^%^GREEN%^This construct is a faceted, man-sized "+
      "%^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l"+
      "%^RESET%^%^GREEN%^d%^BOLD%^, that is floating a few inches "+
      "off of the ground.%^RESET%^");
   set_race("emerald");
   set_gender("neuter");
   set_attacks_num(0);
   set_body_type("junk");
}

//Borrowing wail from Geonslu
///d/islands/tonerra/mon/edragon.c
void die(object ob){
   int i,j;
   object *inven;

   inven = all_living(ETO)
   inven = filter_array(vars, "is_non_immortal_player",FILTERS_D);

   j = sizeof(inven);

   if(!objectp(targ)){
      tell_room(EETO,""%^RESET%^%^GREEN%^em%^BOLD%^er"+
         "%^RESET%^a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d%^BOLD%^"+
         "%^BOLD%^%^GREEN%^shield flickers and fades away.%^RESET%^",ETO);
      TO->move("/d/shadowgate/void");
      TO->remove();
   }
   for(i=o;i<j;i++){
      if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      tell_room(ETO,"%^BOLD%^The %^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^"+
         "a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d %^RESET%^%^BOLD%^shatters "+
         "and lets out a loud, keening wail.%^RESET%^");
      if(inven[i]->!query_property("wail immune")){
         set_property("magic",1);
         tell_object(inven[i],"%^BOLD%^The keening wail strikes you down, "+
            "shaking your soul.%^RESET%^\n");
         if("/daemon/saving_throw_d"->reflex_save(inven[i],-35))
            inven[i]->do_damage("torso",roll_dice(24,4)/2+6);
         else {
            inven[i]->do_damage("torso",roll_dice(24,4)+12);
         if(!"/daemon/saving_throw_d"->fort_save(inven[i],-14)){
            inven[i]->set_paralyzed(( roll_dice(1,12))*8,"%^BOLD%^The "+
               "ringing in your head won't stop!%^RESET%^");

         } else
            inven[i]->add_attack_bonus(-1);
      }
      remove_property("magic");
      if(inven[i]->query_property("wail immune")){
         remove_property("wail immune");
      }
   }
   ::die();
}