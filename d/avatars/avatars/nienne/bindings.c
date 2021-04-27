#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("leather bindings");
   set_short("%^RESET%^%^ORANGE%^Br%^WHITE%^a%^ORANGE%^wler's Gr%^WHITE%^i%^ORANGE%^p%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^leather bindings%^RESET%^");
   set_id(({"bindings","leather bindings","leather straps","straps","grip","brawler's grip"}));
   set_long("%^GREEN%^These look like little more than lengths of cloth, though they are actually made from "
"very carefully %^ORANGE%^tanned leather%^GREEN%^, formed into light but sturdy straps.  They're a little "
"too thick to suffice as bandages, but would probably provide very good support to whatever they were "
"wrapped around.%^RESET%^\n");
   set_weight(2);
   set_value(250);
   set_type("clothing");
   set_ac(0);
   set_size(2);
   set_lore("%^WHITE%^%^BOLD%^Bindings such as these are commonly used by rogues that tend to get into more "
"trouble than simply picking pockets.  When bound properly about the hands and wrists by someone with enough "
"knowledge, they offer strong support to steady the hands in combat, and protection from light attacks."
"%^RESET%^\n");
   set_property("lore difficulty",13);
   set_property("enchantment",1);
   set_item_bonus("magic resistance",1);
   set_limbs(({"left arm","right arm"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if(!ETO->is_class("monk") && !ETO->is_class("thief")) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't really understand what to do with the bindings.%^RESET%^");
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" doesn't really seem to know what to do with the "
"bindings%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^ORANGE%^You wrap the bindings carefully around your wrists and hands.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" wraps some leather bindings carefully around "+ETO->QP+" wrists and "
"hands.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You slowly unbind your wrists.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" slowly unbinds "+ETO->QP+" wrists.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(5)){
     tell_room(EETO,"%^ORANGE%^"+ETOQCN+" brings up "+ETO->QP+" leather-bound hands toward "+who->QCN+
"'s wrist, deftly turning "+who->QP+" attack aside with a subtle twist!",({ETO,who}));
     tell_object(ETO,"%^ORANGE%^You bring up your carefully bound hands, deftly turning aside "+who->QCN+
"'s attack with a subtle twist!");
     tell_object(who,"%^ORANGE%^"+ETOQCN+" brings up "+ETO->QP+" leather-bound hands toward your wrist, and "
"somehow manages to turn your attack aside with a subtle twist!");
     return (-1)*damage;
   }
}
