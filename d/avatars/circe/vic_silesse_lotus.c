//created by ~Circe~ 8/4/14

#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("emerald lotus");
    set_id(({ "lotus", "emerald lotus", "flower", "flower bracelet" }));
    set_short("%^RESET%^%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^ra%^BOLD%^"
       "%^WHITE%^l%^RESET%^%^GREEN%^d l%^RED%^o%^BOLD%^t%^RESET%^%^MAGENTA%^"
       "u%^RESET%^%^GREEN%^s bl%^BOLD%^%^WHITE%^o%^RESET%^%^GREEN%^ss%^BOLD%^o%^RESET%^%^GREEN%^m%^RESET%^");
    set_long("%^RESET%^%^GREEN%^Grown rather than fashioned, this "
       "delicate bra%^BOLD%^c%^RESET%^%^GREEN%^elet is formed entirely "
       "of a slender %^BOLD%^gr%^WHITE%^e%^GREEN%^en v%^RESET%^%^GREEN%^i"
       "%^BOLD%^ne %^RESET%^%^GREEN%^bedecked with wide, scalloped leaves "
       "with backs of %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m"
       "%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g %^RESET%^s%^BOLD%^i"
       "%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^%^GREEN%^.  The vine "
       "wraps several times around the wearer's arm, sometimes seeming to "
       "move of its own accord. It is graced with a breathtaking %^RESET%^b"
       "%^MAGENTA%^l%^RED%^o%^BOLD%^%^GREEN%^ss%^RESET%^%^RED%^o%^MAGENTA%^m "
       "%^RESET%^%^GREEN%^never before seen in nature.  Concentric rings of "
       "petals, %^MAGENTA%^%^du%^BOLD%^s%^RESET%^%^MAGENTA%^ky ma%^BOLD%^"
       "%^BLACK%^g%^RESET%^%^MAGENTA%^enta%^GREEN%^ around the base and "
       "brightening to a %^RED%^vi%^BOLD%^b%^RESET%^%^RED%^rant %^BOLD%^r"
       "%^RESET%^%^RED%^ed%^GREEN%^, surround an %^BOLD%^em%^WHITE%^e%^GREEN%^"
       "ra%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^%^GREEN%^ center that sp"
       "%^BOLD%^%^WHITE%^a%^RESET%^%^GREEN%^rk%^BOLD%^l%^RESET%^%^GREEN%^es "
       "in the light.  The petals never wilt or curl, protected by %^BOLD%^"
       "na%^WHITE%^t%^GREEN%^ur%^BLACK%^e%^GREEN%^'s %^RESET%^%^GREEN%^own "
       "magic.%^RESET%^");
    set_weight(1);
    set_value(250);
    set_type("ring");
    set_limbs(({"left arm"}));
    set_ac(0);
    set_wear("%^GREEN%^The vine wraps around your arm, gently squeezing "
       "you in a welcoming embrace.%^RESET%^");
    set_lore("A most unusual lore surrounds this item, one that many would "
       "consider highly improbable, if not impossible. It is said that a "
       "drow father poured his soul into the earth, bringing forth a single "
       "emerald lotus in honor of his daughter.  Lending some credence to "
       "this tale is the fact that the flower blossoms only once per year, "
       "in Renewal, when the daughter is said to have been born.  The bloom "
       "lasts the whole year through, never withering or wilting, and falls "
       "away only moments before the fresh new bud opens.");
}

int isMagic(){ return 1;}