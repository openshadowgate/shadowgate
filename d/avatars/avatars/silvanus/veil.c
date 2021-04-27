//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("veil");
    set_id(({"armor","veil","veil","%^BOLD%^%^WHITE%^Wedding Veil%^RESET%^",}));
    set_short("%^BOLD%^%^WHITE%^Wedding Veil%^RESET%^");
    set_long(
@ARMOR
%^BOLD%^%^WHITE%^A %^MAGENTA%^p%^WHITE%^e%^MAGENTA%^a%^WHITE%^r%^MAGENTA%^l%^YELLOW%^ %^RED%^encrusted %^YELLOW%^tiara%^WHITE%^ is fitted to an %^BLUE%^e%^YELLOW%^l%^BLUE%^e%^YELLOW%^g%^BLUE%^a%^YELLOW%^n%^BLUE%^t%^WHITE%^ hair style. A full sheer layer of white %^YELLOW%^silk%^WHITE%^ organza floats down to provide a %^RED%^r%^BLUE%^o%^RED%^m%^BLUE%^a%^RED%^n%^BLUE%^t%^RED%^i%^BLUE%^c%^WHITE%^ %^CYAN%^screen%^WHITE%^ between the %^YELLOW%^bride%^WHITE%^ and her %^YELLOW%^groom%^RESET%^.
ARMOR
        );
    set_weight(4);
    set_size(2);
    set_type("clothing");
    set_limbs(({"head",}));
    set_ac(0);
    set_property("enchantment",0);
    set_value(250);
}