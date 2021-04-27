//Original by Tsera, ported to high vendor by Octothorpe 4/29/10
// Modified to be balanced on the new item system, returned to the high vendor. N, 11/12.
//Reskinned by Circe for Aashaenael 7/28/19 - replacing old plot reward
#include <std.h>
#include <daemons.h>
#include <move.h>

inherit ARMOUR;

int trackera, trackerb, fireflag;
//fire shield, rebirth

void create(){
   ::create();
   set_name("phoenix aura");
   set_id(({"phoenix aura","Phoenix Aura","aura of phoenix flames","aura","Aura"}));
   set_short("%^BOLD%^%^BOLD%^%^RED%^Aura of %^RESET%^%^RED%^P%^BOLD%^h"
      "%^YELLOW%^o%^CYAN%^e%^YELLOW%^n%^RED%^i%^RESET%^%^RED%^x %^BOLD%^F"
      "%^RESET%^%^RED%^l%^BOLD%^a%^YELLOW%^m%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^");
   set_long("%^BOLD%^%^RED%^Flickering and flaring, these motes and curls of flame "
      "swirl about like living things. A halo of fire and light, it moves mercurially "
      "giving off a %^RESET%^%^RED%^r%^BOLD%^a%^YELLOW%^d%^CYAN%^i%^YELLOW%^a%^RED%^n"
      "%^RESET%^%^RED%^t %^BOLD%^warmth as wisps of flame lance and curl outward like "
      "flares from a %^YELLOW%^sun%^RED%^. If observed the flames occasionally seem "
      "to take forms, %^RESET%^%^RED%^f%^BOLD%^ir%^RESET%^%^RED%^e-fe%^BOLD%^at"
      "%^YELLOW%^h%^RED%^er%^RESET%^RED%^ed %^BOLD%^birds that circle and swoop, "
      "climb and dive, their eyes flashing with %^RESET%^%^ORANGE%^g%^BOLD%^o%^RESET%^"
      "%^ORANGE%^l%^BOLD%^d%^RESET%^%^ORANGE%^e%^BOLD%^n %^RED%^light before vanishing "
      "once more amongst the other flames.%^RESET%^");
   set_lore("%^RESET%^%^RED%^Staring into the swirling flames before you, you come "
      "to the startling realization that you are looking upon a fragment of the "
      "Seldarine. Despite the fact that in the wake of tumultuous times all the known "
      "Gods of this realm were dead or vanished, all evidence of them slowly being "
      "eroded and lost, it seems some small mote of what they were remains. This echo "
      "of their essence is said to transform its bearer into a creature of "
      "%^BOLD%^fire%^RESET%^%^RED%^ and %^BOLD%^%^YELLOW%^light%^RESET%^%^RED%^ who "
      "can %^BOLD%^rise %^RESET%^%^RED%^up from the ashes of defeat.%^RESET%^");
   set_property("lore difficulty",30);
   set_weight(1);
   set_size(-1);
   set_type("clothing");
   set_limbs(({"head"}));
   set_property("good item",1);
   while ((int)TO->query_property("enchantment") != 6) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",6);
   }
   set_value(0);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"unwear_it":));
   set_struck((:TO,"struck":));
   set_heart_beat(1);
   set_overallStatus(220);
   fireflag = 0;
}

void init(){
   ::init();
   add_action("fire","fire",); //for the Fire Shield spell
   add_action("light","light"); //for the Nimbus of Light spell
   add_action("rise","rise"); //for the Rebirth Spell
   add_action("pray","pray"); //for the praying echo
   if(!interactive(ETO)) return;
   ETO->force_me("wear aura");
}

int wear_it(string str){
   tell_object(ETO,"%^BOLD%^%^RED%^Motes of flame swirl around you, encircling "
      "your head like a fiery halo.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^red%^Motes of flame swirl around "+ETOQCN+", "
      "encircling their head like a fiery halo.%^RESET%^",ETO);
   set_item_bonus("sight bonus",3);
   return 1;
}

int unwear_it(string str){
   tell_object(query_worn(),"%^BOLD%^%^RED%^The aura is part of you, "+
      "it will not be discarded so easily!%^RESET%^");
   return 0;
}


void drop(){
   tell_object(query_worn(),"%^BOLD%^%^RED%^The aura will not part "+
      "from you so easily!%^RESET%^");
   return 1;
}

int struck(int damage, object what, object who){
   if(query_worn()){
      if(!random(2)){
         switch(random(3)){
            case 0:
               tell_room(EETO,"%^RED%^A fiery tendril lashes "+
			      "outward from "+ETO->QCN+"'s %^BOLD%^"+
				  "%^RED%^aura %^RESET%^%^RED%^and deflects "+
				  ""+who->QCN+"'s blow harmlessly to "+
				  "the side.%^RESET%^",({who,ETO}));
               tell_object(who,"%^RED%^A fiery tendril lashes "+
			      "outward from "+ETO->QCN+"'s %^BOLD%^"+
				  "%^RED%^aura, %^RESET%^%^RED%^deflecting your "+
				  "blow harmlessly to the side.%^RESET%^");
               tell_object(ETO,"%^RED%^A fiery tendril lashes "+
			      "outward from your %^BOLD%^%^RED%^aura, %^RESET%^"+
				  "%^RED%^deflecting the incoming blow harmlessly to "+
				  "the side.%^RESET%^");
               break;
            case 1:
               tell_room(EETO,"%^BOLD%^%^RED%^Several minute Phoenix "+
			      "form suddenly from "+ETO->QCN+"'s "+
				  "aura, whipping around"+
				  ""+who->QCN+" and causing their strike to miss!%^RESET%^",({who,ETO}));
               tell_object(who,"%^BOLD%^%^RED%^Several minute Phoenix "+
			      "form suddenly from "+ETO->QCN+"'s "+
				  "aura, whipping around you and causing your strike to miss!%^RESET%^");
               tell_object(ETO,"%^BOLD%^%^RED%^Several minute Phoenix "+
			      "form suddenly from your aura, whipping around "+
				  ""+who->QCN+" and causing their strike to miss!%^RESET%^");
              break;
            case 3:
               tell_room(EETO,"%^RED%^"+ETO->QCN+""+
			      "'s aura suddenly %^BOLD%^%^YELLOW%^flares %^RESET%^%^RED%^as "+who->QCN+""+
				  "'s strike comes close, causing them to flinch away "+
				"from the flames, their attack aborted.%^RESET%^",({who,ETO}));
               tell_object(who,"%^BOLD%^%^RED%^"+ETO->QCN+"+
			      ""'s aura suddenly %^BOLD%^%^YELLOW%^flares %^RESET%^%^RED%^as your strike comes close "+
				  "causing you to flinch away from the flames "+
				  "and abort your attack%^RESET%^");
               tell_object(ETO,"%^BOLD%^%^RED%^Your aura suddenly "+
			      "%^BOLD%^%^YELLOW%^flares %^RESET%^%^RED%^as "+who->QCN+"'s strike comes close, "+
				  "causing them to flinch away from the flames and "+
                  "abort their attack.%^RESET%^");
               break;
         }
      }
   return(-1)*(damage);
   }
}

int pray(){
   if(!objectp(ETO)) return 0;
   if(!(query_worn())){
      tell_object(ETO,"%^BOLD%^%^YELLOW%^You need to wear the aura to be able "+
	     "to pray the the Seldarine.%^RESET%^");
      return 1;
   }
   if(ETO->query_property("prayed")){
      tell_object(ETO,"%^BOLD%^%^YELLOW%^You feel the warmth and "+
	     "love of the Seldarine kept alive in your heart.%^RESET%^");
      return 1;
   }
   tell_object(ETO,"%^BOLD%^%^YELLOW%^You settle your spirit and "+
      "bow your head.  The %^RED%^flames "+
	  "%^BOLD%^%^YELLOW%^around you swirl expectantly...%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^YELLOW%^"+ETO->QCN+" closes "+ETO->QP+" eyes "+
      "and bows "+ETO->QP+" head.  The %^RED%^flames "+
	  "%^YELLOW%^around "+ETO->QCN+" begin to "+
	  "swirl...%^RESET%^",ETO);
   tell_object(ETO,"%^RED%^A fiery Phoenix unfurls from the  "+
      "%^BOLD%^%^YELLOW%^flames %^RESET%^%^RED%^and plunges "+
      "deep into your body, its conflagration spreading over you!%^RESET%^");
   tell_room(EETO,"%^RED%^A fiery Phoenix unfurls from the "+
      "%^BOLD%^%^YELLOW%^FLAMES %^RESET%^%^RED%^around "+
	  ""+ETO->QCN+" and plunges deep into "+
	  ""+ETO->QP+" body, a conflagration spreading over them!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^RED%^The Phoenix Aura "+
      "scintilates around you as a chrous of voices conveys with warmth:\n"+
	  "%^RESET%^%^RED%^You bear our spirit and our hope in this land...%^RESET%^");
   ETO->set_paralyzed(random(4)+4,"%^RED%^Your senses are overwhelmed "+
      "as the essence of the Seldarine infuses you!%^RESET%^");
   ETO->add_attack_bonus(3);
   ETO->add_damage_bonus(3);
   ETO->set_property("prayed",1);
}

//Nimbus of Light at will
int light(){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You seem to have lost your aura.");
     return 1;
   }
   new("/cmds/spells/n/_nimbus_of_light")->use_spell(TP,TP,(int)TP->query_highest_level(),100,"cleric");
   return 1;
}

//Fire Shield 3x day
int fire(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You seem to have lost your aura.");
     return 1;
   }
   if(TP->query_property("fire shield")){
      tell_object(TP,"You are already protected by a shield of fire.");
      return 1;
   }
   if(trackera > time()){
      tell_object(TP,"The aura has not recovered enough to grant you that power.");
      return 1;
   }else{
      fireflag++;
      if(fireflag == 3){
         trackera = time() + 86400;
         fireflag = 0;
      }
      new("/cmds/spells/f/_fire_shield")->use_spell(TP,str,(int)TP->query_highest_level(),100,"mage");
      return 1;
   }
   tell_object(TP,"If you reached this point, something must have gone wrong. Please alert a wiz.");
   return 1;
}


//Rebirth 1x day
int rise(){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You seem to have lost your aura.");
     return 1;
   }
   if(trackerb > time()){
      tell_object(TP,"The aura has not recovered enough to grant you that power.");
      return 1;
   }else{
      trackerb = time() + 86400;
      new("/cmds/spells/r/_rebirth")->use_spell(TP,TP,(int)TP->query_highest_level(),100,"cleric");
      return 1;
   }
   tell_object(TP,"If you reached this point, something must have gone wrong. Please alert a wiz.");
   return 1;
}
