//Temple of Lysara - created by Nienne 2/18
#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_temple("lysara");
   set_name("Temple of Lysara");
   set_short("%^RESET%^%^CYAN%^Temple of Lysara%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Temple of Lysara%^RESET%^\n"
"%^BOLD%^%^WHITE%^A simple %^RESET%^%^ORANGE%^stone %^BOLD%^%^WHITE%^pathway meanders between the trees quite a way, finally emerging within a small grove at the edge of an oceanside cliff.  "
"Grasping branches stretch out overhead, parting here and there to allow occasional g%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^imp%^YELLOW%^s%^BOLD%^%^WHITE%^es of the sky above, while the rest of the "
"clearing is left in a constant state of %^RESET%^%^BLUE%^semi-twilight%^BOLD%^%^WHITE%^.  A faint %^RESET%^mist %^BOLD%^%^WHITE%^seems to linger here at all times of day, drifting aimlessly "
"amidst the trees.  A plain %^BOLD%^%^BLACK%^ebonwood %^BOLD%^%^WHITE%^altar stands in the centre of the grove, its edges traced in %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e"
"%^BOLD%^%^BLACK%^r %^BOLD%^%^WHITE%^while the charge of Lysara has been lettered at its base.  Behind the altar, three tall %^BOLD%^%^BLACK%^ebon statues %^BOLD%^%^WHITE%^stand watch in a semi"
"-circle - one each depicting the Lady's three faces as %^RESET%^%^MAGENTA%^maiden%^BOLD%^%^WHITE%^, %^RESET%^%^RED%^mother %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^crone%^BOLD%^%^WHITE%^.  "
"Glimpses of the %^RESET%^%^CYAN%^o%^BLUE%^c%^RESET%^e%^CYAN%^a%^BLUE%^n %^BOLD%^%^WHITE%^can be caught to the east, where trunks and mists part in places to reveal its sparkling surface."
"\n%^RESET%^");
   set_smell("default","The faint taste of salty air carries upon the mists.");
   set_listen("default","The fog around you doesn't quite dull the constant beat of waves far below.");
   set_exits(([
      "out": "/d/dagger/Torm/road/path3",
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Lysara charges her followers with this message:%^RESET%^%^CYAN%^
Even as the moon waxes and wanes, and the tides turn, so is life a constant cycle of change and growth, death and renewal. While the mysteries of life are to be enjoyed and puzzled over, understand that some answers do not come in this form or this world. Do not fear death, for it is a natural part of life, and each of us have our time to be called. Honor your elders and your ancestors, for their strivings have brought the realm to where it is now, and their lessons have something to teach us all. Find and follow your own path, and aid others in seeking theirs. The cycles of life are mirrored by the cycles of fate, so be prepared to accept the consequences of your actions.
CHARGE
   );
   return 1;
}