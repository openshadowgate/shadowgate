#include <std.h>
inherit ARMOUR;

object ob;

void create(){
        ::create();
        set_name("ring");
        set_id(({ "ring","Ring","beryl ring","call of the dragonet","Call of the Dragonet" }));
        set_short("%^WHITE%^%^BOLD%^Call of the %^RESET%^%^GREEN%^dr%^BOLD%^a%^WHITE%^go%^GREEN%^n%^RESET%^%^GREEN%^et%^RESET%^");
        set_obvious_short("%^RESET%^%^GREEN%^b%^BOLD%^e%^WHITE%^r%^GREEN%^y%^RESET%^%^GREEN%^l %^BOLD%^r%^WHITE%^i%^GREEN%^n%^RESET%^%^GREEN%^g%^RESET%^");
        set_long("%^WHITE%^%^BOLD%^This is a very unique-looking piece of jewelry. A single piece of "
"solid %^RESET%^%^GREEN%^b%^BOLD%^e%^WHITE%^r%^GREEN%^y%^RESET%^%^GREEN%^l%^WHITE%^%^BOLD%^ has been "
"carved into a band small enough to fit around one finger, and engraved in the shape of a tiny dragon. "
"The item has been completed with a tiny "
"%^BOLD%^%^BLUE%^sa%^CYAN%^p%^WHITE%^ph%^CYAN%^i%^BLUE%^re%^WHITE%^ for an eye, "
"and wings that sparkle with %^RESET%^%^RED%^r%^BOLD%^u%^RESET%^%^RED%^by%^WHITE%^%^BOLD%^ dust. Tiny "
"etchings mark the inner surface of the jewelry.%^RESET%^\n");
        set_weight(2);
        set_value(5000);
        set("read","%^WHITE%^%^BOLD%^Just %^CYAN%^summon dragonet%^WHITE%^ to call for it.%^RESET%^");
        set_type("ring");
        set_limbs(({"right hand","left hand"}));
        set_size(2);
        set_ac(0);
        set_property("enchantment",0);
        set_wear((:TO,"wear_fun":));
        set_remove((:TO,"remove_fun":));
}

void init(){
   ::init();
   add_action("summon_fun","summon");
}

int wear_fun(){
    if((string)TP->query_name() != "amberly" && !avatarp(TP)) {
      tell_object(TP,"The ring doesn't seem to fit you.");
      return 0;
    }
    tell_room(EETO,"%^WHITE%^%^BOLD%^The ring glitters as "+ETOQCN+" slips it on.%^RESET%^",ETO);
    tell_object(ETO,"%^WHITE%^%^BOLD%^The ring glitters as you slip it on.%^RESET%^");
    return 1;
}

int remove_fun(){
    tell_room(environment(ETO),"%^WHITE%^%^BOLD%^"+ETOQCN+" slips the glittering ring off "+TP->QP+" finger.%^RESET%^",ETO);
    tell_object(ETO,"%^WHITE%^%^BOLD%^You slip the glittering ring off your finger.%^RESET%^");
    return 1;
}

int summon_fun(string str) {
    if(!str) {
      notify_fail("Summon what?");
      return 0;
    }
    if(str != "dragonet") {
      notify_fail("Nothing happens.");
      return 0;
    }
    if(present("dragonet")) {
    tell_object(TP,"%^WHITE%^%^BOLD%^That is already here!%^RESET%^");
    return 1;
    }
    if(!TO->query_worn()) {
    tell_object(TP,"%^WHITE%^%^BOLD%^You should try wearing the ring first.%^RESET%^");
    return 1;
    }
    tell_room(EETO,"%^WHITE%^%^BOLD%^"+TP->QCN+" murmurs a few words under "+TP->QP+" breath, passing a hand over the %^RESET%^%^GREEN%^b%^BOLD%^e%^WHITE%^r%^GREEN%^y%^RESET%^%^GREEN%^l %^BOLD%^r%^WHITE%^i%^GREEN%^n%^RESET%^%^GREEN%^g%^BOLD%^%^WHITE%^. A tiny dragonet appears!%^RESET%^",TP);
    tell_object(TP,"%^WHITE%^%^BOLD%^You murmur words of the summoning, passing a hand over the %^RESET%^%^GREEN%^b%^BOLD%^e%^WHITE%^r%^GREEN%^y%^RESET%^%^GREEN%^l %^BOLD%^r%^WHITE%^i%^GREEN%^n%^RESET%^%^GREEN%^g%^BOLD%^%^WHITE%^. A tiny dragonet appears!%^RESET%^");
    ob=find_object_or_load("/d/avatars/nienne/dragonet");
    ob->move(EETO);
    return 1;
}
