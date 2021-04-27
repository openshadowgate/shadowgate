//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("pendant");
    set_id(({"armor","pendant","Pendant","%^RED%^Ruby Pendant%^RESET%^",}));
    set_short("%^RED%^Ruby Pendant%^RESET%^");
    set_long(
@ARMOR
%^BOLD%^%^RED%^This pendant is made from a %^CYAN%^s%^WHITE%^p%^CYAN%^a%^WHITE%^r%^CYAN%^k%^WHITE%^l%^CYAN%^i%^WHITE%^n%^CYAN%^g%^RED%^ rose red ruby, that seems to %^MAGENTA%^s%^BLUE%^h%^MAGENTA%^i%^BLUE%^m%^MAGENTA%^m%^BLUE%^e%^MAGENTA%^r %^RED%^indefinitely, it is in the shape of a multi-sided %^GREEN%^cylinder%^RED%^ and hangs down around the neck from an almost %^ORANGE%^pure%^RED%^ and quite %^BLUE%^majestic%^RED%^ %^YELLOW%^golded%^RED%^ chain. Althought it is mysteriously %^CYAN%^beautiful%^RED%^, that is not the only remarkable feature to it, as an %^BLUE%^a%^BLACK%^u%^BLUE%^r%^BLACK%^a%^RED%^ of almost power radiates forth from it continually. Engraved into the underside of it is the perfectly crafted word "%^YELLOW%^elfshine%^RED%^", engraved in an obviously very %^CYAN%^elogant%^RED%^, and possibly %^WHITE%^elven%^RED%^ ledger. %^RESET%
ARMOR
        );
    set_weight(4);
    set_size(2);
    set_type("chain");
    set_limbs(({"neck",}));
    set_ac(2);
    set_property("enchantment",2);
    set_value(3000);
}