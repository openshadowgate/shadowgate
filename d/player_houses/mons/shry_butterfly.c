//shry_butterfly.c - Guardians for Shrydelhi's meadow.  Coded by Circe 9/26/03
#include <std.h>
#include "/d/player_houses/shrydelhi/shry.h"
inherit MONSTER;

create(){
   ::create();
   set_name("butterfly");
   set_id(({"butterfly","fly","butter fly","insect","guardian","protector","silver butterfly"}));
   set_short("%^BOLD%^%^CYAN%^A %^WHITE%^s%^CYAN%^i%^WHITE%^l%^CYAN%^v%^WHITE%^e%^CYAN%^r butterfly%^RESET%^");
   set_long(
      "%^BOLD%^%^WHITE%^This large butterfly is graced with delicate silver wings that "+
      "radiate the moon's light.  The wings seem almost transparent until the light hits, "+
      "then they gleam with a platinum brilliance.  They flit about in the meadow, dancing "+
      "over the water and touching briefly on the silvery leaves of the oak tree before "+
      "taking to the air again."
   );
   set_race("insect");
   set_gender("neuter");
   set_hd(20,3);
   set_body_type("insectoid");
   set_emotes(1,({
      "The butterfly flits about among the %^BOLD%^silver %^RESET%^leaves of the oak tree.",
      "The butterflies take to the air in a breath-taking dance under the %^BOLD%^%^CYAN%^moon%^RESET%^."
   }),0);
   set_max_hp(200+random(75));
   set_hp(query_max_hp());
   set_hd(20);
   set_class("fighter");
   set_mlevel("fighter",20);
   set_overall_ac(-5);
   set_size(1);
   set_stats("strength",12);
   set_stats("intelligence",7);
   set_stats("dexterity",18);
   set_stats("charisma",10);
   set_stats("constitution",11);
   set_stats("wisdom",8);
   set_exp(1000);
   set("aggressive",0);
   set_wielding_limbs( ({"left hand", "right hand"}) );
   set_funcs(({"dust"}));
   set_func_chance(75);
   set_property("swarm",1);
}

void init(){
        string mname=TP->query_name();
   ::init();
   if(avatarp(TP) || TP->query_invis() || !interactive(TP)) return;

        if(mname == "shrydelhi"){
                force_me("emote swirls about the head of "+TPQCN+" in a delightful dance.");
                return;
        }
        if(TP->query_unconscious())return;      
        if(TP->query_bound())return;
        if(ALIGN->is_evil(TP)) {
           if(present("shrydelhi pendant",TP)){
              force_me("emote flits about uneasily on the wind.");
              return;
           }
           else{
                force_me("emote glows with an angry silver light as it takes to the air!");
                force_me("emote shakes its wings and an iridescent dust fills the air.");
                TO->kill_ob(TP);
                return;
           }
       }
       else return;
}

void dust(object targ){
   tell_object(targ,"%^BOLD%^The butterfly flits angrily over your head "+
      "and sprinkles an "+
      "%^BOLD%^%^CYAN%^ir%^BLUE%^id%^WHITE%^es%^BLUE%^ce%^CYAN%^nt%^BOLD%^ "+
      "dust that burns your skin!");
   tell_room(ETO,"The butterfly flits angrily in the air and sprinkles an "+
      "%^BOLD%^%^CYAN%^ir%^BLUE%^id%^WHITE%^es%^BLUE%^ce%^CYAN%^nt%^BOLD%^ "+
      "dust over "+targ->query_cap_name()+"'s head.",targ);
    targ->do_damage("torso",roll_dice(4,6));
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(query_night() != 1){
  tell_room(ETO,"%^MAGENTA%^The butterfly settles on a bush and disapears from sight.%^RESET%^");
  TO->move("/d/shadowgate/void.c");
  TO->remove();
  }
}
