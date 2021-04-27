#include <std.h>
inherit "/d/common/obj/weapon/shortsword";

void create() {
   ::create();
   set_name("sapphire short sword");
   set_obvious_short("%^BOLD%^%^BLUE%^A sapphire-hilted short sword%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^Dreamblade%^RESET%^");
   set_id(({"sword","short sword","sapphire short sword","sapphire-hilted sword","sapphire-hilted short sword","sapphire sword","dreamblade","blade","Dreamblade"}));
   set_long("%^BOLD%^%^BLUE%^The blade of this magnificent short sword"+
   " is made of fine steel with a razor sharp edge. The blade curves"+
   " slightly, allowing for easier removal from an opponent. The hilt"+
   ", however, is what truly draws your eye, for it is"+
   " made of a solid piece of polished blue sapphire. Overall the short"+
   " sword looks like a well balanced weapon of exquisite craftsmanship.");
   set_lore("This unusual sword gets its name from the belief that "+
      "sapphire is the most pure of gemstones.  Modeled after "+
      "what was originally a ceremonial blade, this sword is now meant "+
      "to purify the wickedness of the world.");
   set_value(1000);
   set_property("enchantment",3);
   while(query_property("enchantment") != 3) {
     remove_property("enchantment");
     set_property("enchantment",3);
   }
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
}

int wieldme() {
   if(ETO->is_class("thief")) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^The sapphire handle is cool and smooth in your grasp.");
   }
   return 1;
}

int removeme() {
   tell_object(ETO,"You release the well-balanced short sword.");
   return 1;
}

int hitme(object targ) {
   if(!objectp(targ)) return random(8);
   if(!random(12)) {
      message("my_action","%^BOLD%^Your sword slices through "+targ->query_cap_name()+""+
      " like butter.",ETO);
      message("other_action","%^BOLD%^"+ETO->query_cap_name()+" slices"+
      " "+ETO->query_possessive()+" sword through "+targ->query_cap_name()+""+
      " quite easily.",environment(targ),(({ETO,targ})));
      message("my_action","%^BOLD%^"+ETO->query_cap_name()+"'s sword"+
      " slices easily through your flesh!",targ);
      targ->do_damage("torso",random(10)+5);
      return 1;
   }
   if(!random(20)) {
      message("my_action","%^BOLD%^%^BLUE%^You quickly slip your sword"+
      " up under "+targ->query_cap_name()+"'s guard for a vicious strike.",ETO);
      message("other_action","%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+""+
      " slips "+ETO->query_possessive()+" sword easily under "+targ->query_cap_name()+"'s"+
      " guard for a vicious strike!",environment(targ),(({ETO,targ})));
      message("my_action","%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+""+
      " quickly moves "+ETO->query_possessive()+" sword under your guard,"+
      " landing a vicious blow!",targ);
   targ->do_damage("torso",random(20)+10);
      return 1;
   }
}
