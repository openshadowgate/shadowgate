#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("necrotic hands");
    set_id(({"hand","hands","necrotic hands"}));
    set_short("%^RESET%^%^WHITE%^G%^BOLD%^%^BLACK%^h%^WHITE%^o%^RESET%^s%^BOLD%^%^BLACK%^t%^WHITE%^l%^RESET%^y %^BOLD%^h%^RESET%^a%^BOLD%^%^BLACK%^n%^RESET%^d%^BOLD%^s%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^A %^RESET%^pale white %^BOLD%^in color, these hands are nearly %^RESET%^translucent%^BOLD%^.  Hardly substantial, they appear almost %^BLACK%^wrai%^RESET%^thl%^BOLD%^%^BLACK%^ike%^WHITE%^, but somehow remain fully functional.  Only the most talented of creators could have designed something so unusual.%^RESET%^");
    set_type("ring");
    set_limbs(({"left hand","right hand"}));
    set_property("no animate",1);
    set_weight(0);    
    set_value(0);
    set_ac(0);
    set_property("enchantment",0);
    set_wear((: TO, "wear_me" :));
    set_remove((: TO, "remove_me" :));
}


int wear_me() {
    if(!objectp(ETO)) { return 0; }
    if(avatarp(ETO)) { return 1; }
    if((string)ETO->query_true_name() != "ansekin") { return 0; }
    TO->set_overallStatus(100);
    ETO->set_property("necrotic_hands",1);
    return 1;
}

int remove_me() {
    if(!objectp(ETO)) { return 1; }
    if(avatarp(ETO)) { return 1; }
    if((string)ETO->query_true_name() == "ansekin") {
        tell_object(ETO,"You can't remove your hands!");
        return 0;
    }
    ETO->remove_property("necrotic_hands");
    return 1;
}

int drop(){
   tell_object(query_worn(),"You can't just drop your hands!");
   return 1;
}
