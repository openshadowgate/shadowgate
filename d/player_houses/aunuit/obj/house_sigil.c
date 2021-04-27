//Sigil for House Rilynath
//~Circe~ 8/6/13

#include <std.h>

inherit ARMOUR;


void create(){
   ::create();
   set_name("sigil");
   set_id(({"sigil","amulet","pendant","necklace","house sigil","house rilynath sigil","rilynath_sigil"}));
   set_obvious_short("%^BOLD%^%^WHITE%^mi%^CYAN%^t"
         "%^WHITE%^hr%^RESET%^i%^BOLD%^l amulet%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Sigil of House Rilynath%^RESET%^");
   set_long("This %^BOLD%^mi%^CYAN%^t%^WHITE%^hr%^RESET%^i%^BOLD%^l amulet "
      "%^RESET%^bears the sigil of %^RED%^House Rilynath%^RESET%^, a "
      "%^BOLD%^%^BLACK%^bla%^RESET%^c%^BOLD%^%^BLACK%^k dragon "
      "%^RESET%^formed from %^BOLD%^%^BLACK%^sh%^BLUE%^a%^BLACK%^d"
      "%^RESET%^o%^BOLD%^%^BLACK%^w %^RESET%^itself, rising from the "
      "%^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^BLACK%^rkn%^WHITE%^e%^RESET%^s"
      "%^BOLD%^%^BLACK%^s %^RESET%^with outstretched %^BOLD%^%^BLACK%^cl"
      "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ws %^RESET%^and a gaping "
      "%^BOLD%^%^RED%^maw %^RESET%^to %^BOLD%^%^BLACK%^r%^RED%^e%^BLACK%^nd "
      "%^RESET%^whatever foe lay in its path. Strung on a %^ORANGE%^leather "
      "cord%^RESET%^, this sigil is worn only by those associated with the "
      "House - or by those who are braver than they are intelligent.");
   set_weight(1);
   set_value(0);
   set_type("ring");
   set_limbs(({"neck"}));
   set_ac(0);
}

int is_rilynath_sigil(){ return 1; }