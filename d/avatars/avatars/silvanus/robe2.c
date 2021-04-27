//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("robe");
    set_id(({"armor","robe","robe","%^RED%^Bright Red Robe%^RESET%^",}));
    set_short("%^RED%^Bright Red Robe%^RESET%^");
    set_long(
@ARMOR
%^RED%^This is a red robe made from a fine, %^WHITE%^bright%^RED%^ tharisian %^YELLOW%^silk%^RESET%^%^RED%^. Several small %^MAGENTA%^gemstones%^RED%^ are embroidered into the lining, giving off a %^CYAN%^s%^WHITE%^p%^CYAN%^a%^WHITE%^r%^CYAN%^k%^WHITE%^l%^CYAN%^i%^WHITE%^n%^CYAN%^g%^RESET%^%^RED%^ reflection when %^WHITE%^light%^RED%^ hits it at the right angle.%^RESET%^
ARMOR
        );
    set_weight(5);
    set_size(2);
    set_type("clothing");
    set_limbs(({"torso",}));
    set_ac(1);
    set_property("enchantment",1);
    set_value(25);
}