#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create() {
   ::create();
   set_name("boots");
   set_id(({"boots","gray boots","shadowy boots","shadowy gray boots","steps of shadow","Steps of Shadow"}));
   set_short("%^BLACK%^%^BOLD%^St%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^ps of Sh%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^dow%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^shadowy gray boots%^RESET%^");
   set_long("%^CYAN%^These fine boots, despite being made of what looks like leather, are particularly "
"soft and malleable, melding to the shape of the foot when worn.  They reach to the ankles, and are held "
"with small, un-reflective %^BLACK%^%^BOLD%^jet-black%^RESET%^%^CYAN%^ buckles that blend in with the "
"%^BLACK%^%^BOLD%^shadowy gray fabric%^RESET%^%^CYAN%^ of the boots themselves.  Upon the underside of "
"each boot is a thicker sole of dark leather, protecting the foot while dulling the sound of any "
"footsteps the wearer makes.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^Only whispers of gossip have ever been heard concerning these boots.  Some "
"claim that they were formed by the power of the %^BLACK%^Shadowlord%^WHITE%^ himself, shaped from the "
"shadows to conceal the footsteps of the wearer.");
   set_property("lore difficulty",10);
   set_limbs(({"right foot","left foot"}));
   set_weight(2);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_property("enchantment",1);
   while(TO->query_property("enchantment")< 1){
      remove_property("enchantment");
      set_property("enchantment",1);
   }
   set_type("clothing");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   if(!interactive(ETO) || avatarp(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED && !avatarp(TP)) {
     owner = TPQN;
     OWNED = 1;
   }
}

int wear_fun() {
   if((string)TPQN == owner || avatarp(TP)) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^The boots seem to come alive with %^BLACK%^shadows%^WHITE%^ as you "
"slide them onto your feet.");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+"'s feet become shrouded by %^BLACK%^shadows%^WHITE%^ as "
+ETO->QS+" slides the boots on.",ETO);
     ETO->set_property("magic resistance",5);
     return 1;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^The boots refuse to fit your feet!");
   return 0;
}

int remove_fun() {
   tell_object(ETO,"%^WHITE%^%^BOLD%^You feel the protection of the %^BLACK%^shadows%^WHITE%^ recede as "
"you remove the boots.");
   ETO->set_property("magic resistance",-5);
   return 1;
}
