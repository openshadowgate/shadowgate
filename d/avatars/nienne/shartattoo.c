#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("%^BOLD%^%^BLACK%^tattoo%^RESET%^");
   set_id(({"tattoo","dark tattoo","shimmering tattoo","dark shimmering tattoo"}));
   set_short("%^BOLD%^%^BLACK%^a d%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^rk sh%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^mme%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^ing t%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ttoo%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This dark tattoo covers the upper torso of the "
"half-elf. At first it looks as though the ink used was completely black, but "
"it is actually a %^RESET%^%^MAGENTA%^very d%^BOLD%^e%^RESET%^%^MAGENTA%^ep "
"vi%^BOLD%^o%^RESET%^%^MAGENTA%^let %^BOLD%^%^BLACK%^that "
"sh%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^mmers "
"d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rkly in any light. The tattoo looks "
"completely smooth and silky, almost as if it were liquid that had just been "
"dripped into place upon his skin. The tattoo consists of a series of thick "
"lines that look as though liquid was poured onto his shoulders and they "
"followed grooves down his torso, hitting sharp corners here and there in the "
"beginning and then coiling into sharp points at their ends. The inscription "
"looks almost %^RESET%^%^CYAN%^arc%^BOLD%^a%^RESET%^%^CYAN%^ne "
"%^BOLD%^%^BLACK%^in nature, similar in make to the patterns used in circles "
"of arcane power.%^RESET%^");
   set_weight(0);
   set_limbs(({"torso"}));
   set_ac(4);
   set_value(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   tracker = 0;
}

int drop(){ return 1; }

void init() {
   ::init();
   add_action("walk_me","shadowwalk");
}

int wear_fun() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the dark, comforting embrace of "
"%^RESET%^%^MAGENTA%^darkness %^BOLD%^%^BLACK%^as the tattoo's patterns "
"r%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^pple out across your chest.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" smiles confidently, as the "
"patterning of a %^RESET%^%^MAGENTA%^dark tattoo "
"%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^pples out across "
+ETO->QP+" chest.%^RESET%^",ETO);
   while ((int)TO->query_property("enchantment") != (-4)) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",(-4));
   }
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel an intense sense of "
"%^RESET%^%^MAGENTA%^loss %^BOLD%^%^BLACK%^as the tattoo across your chest "
"sh%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^mmers and fades.%^RESET%^");
   return 1;
}

int walk_me(string str) {
   if(!TO->query_worn()) {
     notify_fail("You should be wearing the tattoo to activate the spell.\n");
     return 1;
   }
   if(!str) {
     notify_fail("You should specify where you want to shadowwalk to.\n");
     return 1;
   }
   if(tracker > time()) {
     notify_fail("You've already used this spell today.\n");
     return 1;
   }
   tracker = time() + 28800;
   new("/d/avatars/nienne/_shadow_walk")->use_spell(ETO,str,ETO->query_lowest_level());
   return 1;
}

void reset_timer() {
   tracker = time();
}
