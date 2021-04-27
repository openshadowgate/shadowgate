#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create() {
   ::create();
   set_name("shadowy bracers");
   set_short("%^BOLD%^%^BLACK%^Twil%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^ght Cuffs%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y bracers%^RESET%^");
   set_id(({"bracer","bracers","shadowy bracers","cuffs","twilight cuffs"}));
   set_long("%^BLUE%^These matching pair of bracers seem almost surreal, made of nothing but%^BOLD%^%^BLACK%^ "
"whisps of shadow%^RESET%^%^BLUE%^.  You can see right through the %^WHITE%^dusky haze %^BLUE%^of their form, "
"leaving it to the imagination how they were even crafted in the first place.  The only way to tell where the "
"bracers end and the air begins, is a fine shifting line of %^YELLOW%^gold %^RESET%^%^BLUE%^around either "
"edge, that %^WHITE%^gli%^BOLD%^t%^RESET%^%^WHITE%^ters %^BLUE%^and %^BOLD%^%^WHITE%^sparkl%^YELLOW%^e%^WHITE%^"
"s %^RESET%^%^BLUE%^with a life of its own.%^RESET%^\n");
   set_weight(5);
   set_value(1025);
   set_ac(1);
   set_lore("%^BOLD%^%^WHITE%^Such intriguing bracers as these were known only to be crafted once, for a drow "
"named Veszmur'ss.  Little is known about him, but it is said that they were gifted to him upon a favor from a "
"maskarran priest, and are imbued by the magic of the shadows themselves.\n");
   set_property("lore difficulty",19);
   while((int)TO->query_property("enchantment") < 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
}

int check() {
   ::check();
   if((string)TP->query_diety() != "mask") {
     tell_object(ETO,"%^BLUE%^The bracers don't seem to fit you.%^RESET%^");
     tell_room(EETO,"%^BLUE%^The bracers don't seem to fit "+ETO->QCN+".%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BLUE%^You slide the %^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y bracers "
"%^RESET%^%^BLUE%^over your forearms, and they meld perfectly against your skin.%^RESET%^");
   tell_room(EETO,"%^BLUE%^The %^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y bracers %^RESET%^"
"%^BLUE%^meld perfectly against "+ETO->QCN+"'s forearms.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
     tell_object(ETO,"%^BLUE%^The %^BOLD%^%^BLACK%^dusky br%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^cers %^RESET%^"
"%^BLUE%^slide loose from your forearms.%^RESET%^");
     tell_room(EETO,"%^BLUE%^The %^BOLD%^%^BLACK%^dusky br%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^cers %^RESET%^"
"%^BLUE%^slide loose from "+ETO->QCN+"'s forearms.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"%^BLUE%^The shadowy bracers seem to solidify, just enough to harmlessly deflect "
+target->QCN+"'s attack!%^RESET%^");
     tell_object(target,"%^BLUE%^"+ETO->QCN+"'s shadowy bracers seem to solidify, just enough to harmlessly "
"deflect your attack!%^RESET%^");
     tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s shadowy bracers seem to solidify, just enough to harmlessly "
"deflect "+ETO->QP+"'s attack!%^RESET%^",({ETO,target}));
     return (-1)*damage;
   }
   return 1;
}
