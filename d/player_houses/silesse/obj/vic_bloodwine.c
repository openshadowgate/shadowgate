inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("wine");
   set_id(({"wine","glass of wine","bloodwine","glass of bloodwine","blood wine","drink"}));
   set_strength(50);
   set_weight(1);
   set_type("alcoholic");
   set_empty_name("glass");
   set_short("A glass of %^RESET%^%^RED%^bl%^BOLD%^o%^RESET%^"
      "%^RED%^od%^BOLD%^w%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^e%^RESET%^");
   set_destroy();
   set_long("A wide wine glass balanced upon a delicate stem rimmed "
      "in gold has been filled with a deep %^RED%^ruby liquid%^RESET%^ "
      "that seems somehow thicker than normal wine. Indeed, this drink "
      "is rumored to be distilled from the blood of the enemies of the "
      "Drow, each bottle slightly different than all others. Giving "
      "off a heady, earthy scent, the wine is never complete until "
      "the drinker pricks his or her own finger, adding a drop of blood.");
   set_my_mess("You prick your finger, adding a %^RESET%^%^RED%^drop%^RESET%^ of %^RESET%^%^RED%^bl%^BOLD%^o%^RESET%^"
      "%^RED%^od%^RESET%^ to the wine before draining your %^CYAN%^glass%^RESET%^.");
   set_your_mess("pricks a finger and adds a %^RESET%^%^RED%^drop%^RESET%^ of %^RESET%^%^RED%^bl%^BOLD%^o%^RESET%^"
      "%^RED%^od%^RESET%^ to the wine before drinking it.");
}
