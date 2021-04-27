//file 

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("cape");
    set_id(({"armor","cape","shimmering cape","%^BOLD%^%^MAGENTA%^S%^BLUE%^h%^GREEN%^i%^RED%^m%^ORANGE%^m%^CYAN%^e%^BLUE%^r%^RESET%^%^BOLD%^i%^RED%^n%^MAGENTA%^g %^GREEN%^C%^CYAN%^a%^RED%^p%^BLUE%^e%^RESET%^",}));
    set_short("%^BOLD%^%^MAGENTA%^S%^BLUE%^h%^GREEN%^i%^RED%^m%^ORANGE%^m%^CYAN%^e%^BLUE%^r%^RESET%^%^BOLD%^i%^RED%^n%^MAGENTA%^g %^GREEN%^C%^CYAN%^a%^RED%^p%^BLUE%^e%^RESET%^");
    set_long(
@ARMOR
This is an incredible garment as it constantly shifts colors in a beautiful rainbow of patterns and shapes, or can be dark if the wearer wishes.
ARMOR
        );
    set_weight(2);
    set_size(2);
    set_type("clothing");
    set_limbs(({"neck",}));
    set_ac(5);
    set_property("enchantment",5);
    set_value(10000);
}