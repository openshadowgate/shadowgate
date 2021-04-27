
#include <std.h>;

inherit "/std/armour.c";


void create(){
    ::create();
    set_name("silver greaves");
    set_id(({"greaves","silver greaves","Greaves","armor"}));
    set_obvious_short("%^RESET%^%^BOLD%^silver greaves%^RESET%^");
    set_short("%^RESET%^%^BOLD%^%^WHITE%^J%^RESET%^%^WHITE%^u%^RESET%^"+
"%^BOLD%^%^WHITE%^stice's Stri%^RESET%^%^WHITE%^d%^RESET%^%^BOLD%^"+
"%^WHITE%^e%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^WHITE%^These greaves have been formed "+
"from a %^RESET%^%^WHITE%^silver alloy %^RESET%^%^BOLD%^%^WHITE%^treated "+
"and fired until solid and hard as steel. The front is decorated with an "+
"inlay of %^RESET%^%^CYAN%^b%^RESET%^%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^ue "+
"di%^RESET%^%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^mon%^RESET%^%^BOLD%^%^BLUE%^"+
"d%^RESET%^%^CYAN%^ %^RESET%^%^BOLD%^%^WHITE%^forming a set of scales. The "+
"workmanship of the design is perfect, and even though the greaves seem used, "+
"there isnt a scratch on them. They buckle with a series of %^RESET%^%^ORANGE%^"+
"leather straps %^RESET%^%^BOLD%^%^WHITE%^that tie behind the leg.%^RESET%^.");
     set_lore("%^CYAN%^When a templar of Tyr in the Order of Tal'kalid takes his "+
"final oaths, he or she is presented with a set of greaves blessed by the Hammer "+
"Lord. Loosing their greaves would mean a very long explanation and an even longer "+
"journey to earn them again.%^RESET%^");
    set_property("lore",5);
    set_type("armor");
    set_property("enchantment",1);
    set_ac(1);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_limbs(({"left leg","right leg"}));
    set_weight(5);
    set_value(3000);
}
int wear_func(){
    if((int)TP->query_lowest_level() < 20) {
        tell_object(TP,".");
    return 0;
    }
    if(!TP->is_class("cavalier") && !TP->is_class("paladin") &&
!TP->is_class("fighter") && !TP->is_class("cleric") &&
!TP->is_class("antipaladin")) {
    tell_object(ETO,".");
    return 0;
   }
    tell_room(environment(ETO),"%^CYAN%^%^BOLD%^"+ETOQCN+"%^CYAN%^%^BOLD%^ buckles on the greaves slowly.%^RESET%^",ETO);
    tell_object(ETO,"%^BLACK%^%^BOLD%^You buckle on the greaves.%^RESET%^");
    return 1;
}


int remove_func(){
        tell_room(environment(ETO),"%^CYAN%^%^BOLD%^"+ETOQCN+" %^CYAN%^%^BOLD%^Pulls off the greaves.%^RESET%^",ETO);
        tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the greaves.%^RESET%^");
        return 1;
}