//typos fixed by Circe 12/1/07
#include <std.h>
inherit WEAPON;

void create(){
   ::create();
   set_name("Rhythmic Jingle");
   set_id(({ "tambourine", "rhythmic jinglet", "weapon", "rhythmic", "jingle" }));
   set_short("%^BOLD%^%^MAGENTA%^Rh%^BOLD%^%^CYAN%^yt%^BOLD%^"+
      "%^MAGENTA%^hm%^RESET%^i%^BOLD%^%^MAGENTA%^c J%^RESET%^"+
      "%^CYAN%^i%^BOLD%^%^MAGENTA%^ngle%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^ornate tambourine%^RESET%^");
   set_long("%^RESET%^%^CYAN%^At first glance, this just appears "+
      "to be just a fancy tambourine.  The outer circle of the "+
      "tambourine is crafted from %^BOLD%^%^WHITE%^mithril "+
      "%^RESET%^%^CYAN%^and it is decorated with extravagant "+
      "jingles.  The zils are made from thin pieces of %^BOLD%^"+
      "%^GREEN%^j%^RESET%^GREEN%^a%^BOLD%^GREEN%^de%^RESET%^"+
      "%^CYAN%^, and there are fifteen of them traveling along "+
      "the circle, each of them symmetrically placed. The skin "+
      "of the drum is pulled taut, by strong %^RESET%^"+
      "%^MAGENTA%^purple silk bands%^RESET%^%^CYAN%^.  While "+
      "observing the elegance of the instrument, you notice "+
      "the %^BOLD%^%^GREEN%^zils%^RESET%^%^CYAN%^ are quite "+
      "sharp around the edges.%^RESET%^");
   set_weight(5);
   set_type("slashing");
   set_prof_type("instrument");
   set_size(1);
   set_wc(1,6);
   set_large_wc(1,6);
   set_value(7000);
   set_lore("This tambourine was made for the widely famous "+
      "Bryanna Caelderyn.  At that point, it was nothing more "+
      "than a highly decorated musical instrument.  However, "+
      "one day, Bryanna found herself in a bind.  She had been "+
      "captured by the infamous gold elf , Daelmas Luriel.  "+
      "The wicked elf relieved her of her weapons and gagged "+
      "her, neutralizing her magic.  Bryanna was left with "+
      "her ' harmless ' instrument and used it to cut her ropes.  "+
      "With hands now free, she was able to ungag herself and "+
      "escape with her spells.  A few days later, she invested "+
      "a great deal of time into what she called ' hiding "+
      "weapons in plain sight. '");
   set_property("enchantment",3);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
   if((!ETO->is_class("bard"))){
      tell_object(ETO,"%^RESET%^%^CYAN%^You heft the tambourine, "+
         "and it jingles wildy!");
      tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" clumsily hefts "+
         "up the tambourine, and it jingles wildly!",ETO);
      return 1;
   }else{
      tell_object(ETO,"%^RESET%^%^CYAN%^With natural ease, you "+
         "control the tambourine and keep it silent as you "+
         "heft it up.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" hefts up the "+
         "tambourine with natural ease.%^RESET%^",ETO);
      ETO->add_attack_bonus(2);
      return 1;
   }
}

int unwield_func(){
   if((!ETO->is_class("bard"))) {
      tell_object(ETO,"%^RESET%^%^MAGENTA%^You clumsily lower "+
         "the tambourine, making a lot of noise.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETOQCN+" clumsily "+
         "unhands the tambourine, and it jingles wildly!%^RESET%^",ETO);
      return 1;
   }else{
      tell_object(ETO,"%^RESET%^%^MAGENTA%^You lower the tambourine "+
         "silently.%^RESET%^");
      tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETOQCN+" lowers "+
         "the tambourine silently.%^RESET%^",ETO);
      ETO->add_attack_bonus(-2);
      return 1;
   }
}

int hit_func(object targ){
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   if(random(1000) < 300){
      switch(random(3)){
         if((!ETO->is_class("bard"))) {
            tell_room(EETO,"The tambourine just jingles.",({ETO,targ}));
            tell_object(ETO,"The tambourine just jingles.");
            tell_object(targ,"The tambourine just jingles.");
         }else{
            case 0:        
               tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" shakes "+
                  "the tambourine to the rhythm of combat, helping "+
                  "to land a solid blow!%^RESET%^",({ETO,targ}));
               tell_object(ETO,"%^RESET%^%^CYAN%^You shake your "+
                  "tambourine to the rhythm of combat, helping you "+
                  "land a perfectly-timed blow!%^RESET%^");
               tell_object(targ,"%^RESET%^%^CYAN%^"+ETOQCN+" shakes "+
                  "the tambourine to the rhythym of combat, helping "+
                  ""+ETO->QO+" strike you!%^RESET%^");
               targ->do_damage("torso",roll_dice(3,6));
               break;
            case 1:
               tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+"'s zils "+
                  "cuts "+targ->QCN+" deeply!%^RESET%^",({ETO,targ}));
               tell_object(ETO,"%^BOLD%^%^GREEN%^The zils on your "+
                  "tambourine cut "+targ->QCN+" deeply!%^RESET%^");
               tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+" cuts "+
                  "you deeply with the zils of the tambourine!%^RESET%^");
               targ->do_damage("torso",roll_dice(3,6));
               break;
            case 2:
               set_property("magic",1);
               tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETOQCN+"'s "+
                  "tambourine begins to jingle with its own rhythm, "+
                  "climbing climatically before striking the "+
                  "target!%^RESET%^",({ETO,targ}));
               tell_object(ETO,"%^RESET%^%^MAGENTA%^The tambourine "+
                  "begins to jingle with its own rhythm, climbing "+
                  "climatically until it collides with the "+targ->QCN+"%^RESET%^!");
               tell_object(targ,"%^RESET%^%^MAGENTA%^"+ETOQCN+"'s "+
                  "tambourine begins to jingle with its own rhythm, "+
                  "climbing climatically until it collides with you!%^RESET%^");
               targ->do_damage("torso",roll_dice(3,6));
               remove_property("magic");
               break;
         }
      }
   }
}

int is_instrument(){return 1;}
