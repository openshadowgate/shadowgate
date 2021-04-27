inherit "/std/drink.c";

#include <std.h>

void create(){
   ::create();
   set_name("wine");
   set_id(({"wine","glass of wine","ulaver","ulaver wine","glass of ulaver","drink","Ulaver wine"}));
   set_strength(50);
   set_weight(1);
   set_type("alcoholic");
   set_empty_name("glass");
   set_short("A glass of %^GREEN%^ul%^BOLD%^a%^RESET%^%^GREEN%^v%^BOLD%^e%^RESET%^%^GREEN%^r%^RESET%^");
   set_destroy();
   set_long("Served in a %^ORANGE%^copper goblet%^RESET%^ that adds a "
      "faint %^RED%^bloody %^RESET%^taste to the liquid inside, this "
      "wine is a luminous %^BOLD%^%^GREEN%^green%^RESET%^, the product "
      "of its fermentation. A closely guarded secret of the Drow, this "
      "wine is prized for its earthy, fruity taste and its faintly hallucinogenic properties.");
   set_my_mess("As you sip the faintly glowing wine, you could swear you feel the flutter of wings against your ear.");
   set_your_mess("sips the wine and glances to the side.");
}
