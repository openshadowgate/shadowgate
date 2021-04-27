#include <std.h>
inherit "/d/common/obj/weapon/spear_lg";

void create(){
   ::create();
   set_name("spear");
   set_id(({"spear","steel-tip spear","patterned spear","thunderstrike"}));
   set_short("%^YELLOW%^Thu%^BOLD%^%^WHITE%^n%^YELLOW%^derst%^BOLD%^%^WHITE%^r%^YELLOW%^ike%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^pa%^RESET%^t%^BOLD%^%^BLACK%^ter%^YELLOW%^n%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^d steel-tip spear%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This weapon is simple but elegant, a single sharp-tipped "
"shaft for impaling one's foes.  Its body has been cut from a sturdy piece of %^RESET%^"
"black ash%^BOLD%^%^BLACK%^, polished to a glossy shine that gleams in the light.  "
"Patterns have been etched j%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^g%^BOLD%^%^BLACK%^ged"
"%^YELLOW%^l%^BOLD%^%^BLACK%^y down its length, crackling randomly like lightning across "
"its dark surface.  The tip has been forged from %^BOLD%^%^WHITE%^s%^RESET%^te%^BOLD%^"
"%^WHITE%^el%^BOLD%^%^BLACK%^, and sharpened to a razor's edge.  It is a beautiful but "
"deadly weapon.\n%^RESET%^");
   set_lore("Such fine weapons are favored by goodly and wicked souls alike, from the lightning-wielding servants of Anhur to the Stormlords of Talos.  Which among them may have originally forged this piece is lost to history, but it would certainly be prized among them, and many others as well simply for its fine craftsmanship.");
   set_value(175);
   set_property("enchantment",1);
   set_wield((:TO,"wieldme":));
   set_hit((:TO,"hitme":));
}

int wieldme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^The spear's tip %^YELLOW%^crackles%^BOLD%^%^BLACK%^ as you lift the weapon.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The spear's tip %^YELLOW%^crackles%^BOLD%^%^BLACK%^ as "+ETOQCN+" lifts the weapon.%^RESET%^",ETO);
   return 1;
}

int hitme(object targ){
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 1;
   if(!objectp(ETO)) return 1;
   if(!random(7)){
      tell_object(ETO,"%^BOLD%^%^BLACK%^You plunge the speartip into "+targ->QCN+", and "
+targ->QS+" is jolted back by an electric shock!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s speartip plunges into your skin, and "
"a shock of electricity jolts you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s speartip plunges into "+targ->QCN+", "
"and "+targ->QS+" is jolted back by an electric shock!%^RESET%^",({ETO,targ}));
      return roll_dice(1,8);
   }
   if(!random(7)){
      tell_object(ETO,"%^BOLD%^%^WHITE%^An arc of electricity leaps from your spear as it "
"flashes past "+targ->QCN+", leaving "+targ->QS+" off balance long enough for you to "
"strike again!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^An arc of electricity leaps from "+ETOQCN+"'s "
"spear as it flashes past you, and as you're trying to regain your balance "+ETO->QS+
" strikes at you again!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^An arc of electricity leaps from "+ETOQCN+"'s "
"spear as it flashes past "+targ->QCN+", leaving "+targ->QS+" off balance long enough for "
+ETO->QS+" to strike again!%^RESET%^",({ETO,targ}));
      ETO->execute_attack();
   }
}
