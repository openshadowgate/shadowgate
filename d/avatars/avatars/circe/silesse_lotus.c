//created by ~Circe~ 8/25/11

#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("lotus blossom");
    set_id(({ "lotus", "lotus blossom","blossom","black lotus","black blossom","black lotus blossom","flower" }));
    set_short("%^BOLD%^%^BLACK%^black l%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^tus blossom%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This delicate flower features concentric rings "+
      "of inky black petals curving to their %^RESET%^%^RED%^red%^BOLD%^-"+
      "%^RESET%^%^RED%^ti%^BOLD%^p%^RESET%^%^RED%^ped p%^BOLD%^o%^RESET%^"+
      "%^RED%^ints%^BOLD%^%^BLACK%^.  The deep %^RESET%^%^RED%^red center"+
      "%^BOLD%^%^BLACK%^ of the blossom features hints of %^RESET%^%^MAGENTA%^"+
      "pi%^BOLD%^n%^RESET%^%^MAGENTA%^k%^BOLD%^%^BLACK%^, a stray beam of "+
      "%^RESET%^light %^BOLD%^%^BLACK%^enhancing the flower's beauty.  The "+
      "petals never wilt or curl, as if they have been protected by some "+
      "%^RESET%^%^CYAN%^enchantment%^BOLD%^%^BLACK%^.  A simple %^RESET%^"+
      "silver pin%^BOLD%^%^BLACK%^ is attached to the short stem, allowing "+
      "the flower to adorn the wearer's hair.%^RESET%^");
    set_weight(1);
    set_value(250);
    set_type("ring");
    set_limbs(({"head"}));
    set_ac(0);
    set_wear("%^CYAN%^A refreshing breeze brings you a sweet fragrance as you pin the %^BOLD%^%^BLACK%^black lotus %^RESET%^%^CYAN%^in your hair.%^RESET%^");
    set_lore("The lotus is said to hold special significance in the lore of certain elven populations, though none has ever mentioned a black variety before.");
}

int isMagic(){ return 1;}