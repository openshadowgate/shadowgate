#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("amulet");
    set_id(({ "amulet","dragonseye amulet","glowing amulet"}));
    set_short("%^YELLOW%^glowing %^RED%^dragons eye %^CYAN%^amulet%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^This strange amulet is made of what appears to be a rounded "
"piece of %^YELLOW%^glowing %^RED%^dragons eye %^CYAN%^hanging from a %^WHITE%^platinum"
"%^CYAN%^ chain that has become slightly %^GREEN%^green %^CYAN%^with %^BLACK%^age, %^CYAN%^"
"with many scratches. The eye itself seem unharmed and quite lifelike%^RESET%^");
    set_weight(2);
    set_value(3500);
    set_type("ring");
    set_limbs(({"neck"}));
    set_size(2);
}
