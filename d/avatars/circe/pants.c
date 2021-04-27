//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("breeches");
   set_id(({"breeches","pants","leather breeches","leather pants"}));
   set_short("%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple "+
      "leather breeches%^RESET%^");
   set_long("This pair of breeches is made from tight-fitting "+
      "supple %^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple "+
      "leather%^RESET%^.  The leather is thin "+
      "and form-fitting, accentuating every aspect of the wearer's "+
      "legs - good or bad.  Only the most self-assured would "+
      "probably wear such pants - though they would likely look "+
      "quite nice in them.  Something about these pants makes you feel "+
      "like you want to %^BOLD%^%^MAGENTA%^<%^RESET%^%^MAGENTA%^wiggle%^BOLD%^> "+
      "%^RESET%^in them.");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_property("enchantment",2);
   set_weight(2);
   set_size(2);
   set_value(250);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

void init(){
   ::init();
   add_action("wiggle","wiggle");
}

int wearme(){
   if((string)ETO->query_gender() != "female"){
      tell_object(ETO,"Try as you might, you just can't fit "+
         "into the pants!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^MAGENTA%^You slip into the tight "+
      "leather pants and notice how nice your legs look.");
   tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" slips into the "+
      "tight leather pants, drawing your eyes briefly to her shapely "+
      "legs.",ETO);
   ETO->add_stat_bonus("charisma",1);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^MAGENTA%^You remove the pants, missing them "+
      "already.");
   tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" removes the pants "+
      "with a soft sigh.",ETO);
   ETO->add_stat_bonus("charisma",-1);
   return 1;
}

int wiggle(string str){
   if(!str){
      tell_object(ETO,"%^MAGENTA%^You wiggle your bottom, giggling as "+
         "you show off your shapely legs.");
      tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" wiggles her hips, laughing "+
         "seductively as she shows off her shapely legs.",ETO);
      return 1;
   }
}