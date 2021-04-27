//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

void create(){
   ::create();
   set_name("Upper Landing");
   set_short("%^BOLD%^%^BLACK%^Upper Landing%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This balcony is bordered by a "
      "%^RESET%^%^ORANGE%^wooden bannister %^BOLD%^%^BLACK%^"
      "and overlooks the main room. The walls are lined with "
      "rich, %^RESET%^%^ORANGE%^darkwood paneling %^BOLD%^"
      "%^BLACK%^and the floor is composed of the same gl"
      "%^RESET%^o%^BOLD%^%^WHITE%^s%^BLACK%^sy bla%^RESET%^"
      "c%^BOLD%^%^BLACK%^k m%^WHITE%^a%^BLACK%^rble as the "
      "lower level, its reflective surface %^WHITE%^gleaming%^BLACK%^. "
      "A grand %^RESET%^%^ORANGE%^darkwood staircase %^BOLD%^%^BLACK%^"
      "descends into the room below. From this vantage point the "
      "tops of the %^WHITE%^scr%^RESET%^i%^BOLD%^%^WHITE%^ms%^RESET%^"
      "h%^BOLD%^%^ORANGE%^a%^BOLD%^%^WHITE%^w p%^RESET%^i%^BOLD%^"
      "%^WHITE%^ll%^ORANGE%^a%^WHITE%^rs %^BLACK%^as well as the "
      "%^RED%^orn%^RESET%^%^RED%^a%^BOLD%^%^RED%^te ch%^RESET%^"
      "%^RED%^a%^BOLD%^%^RED%^ndel%^MAGENTA%^i%^RESET%^%^RED%^e"
      "%^BOLD%^%^RED%^r %^BLACK%^hanging from the ceiling are "
      "visible. To the north an archway leads into a chamber.%^RESET%^\n");
   set_listen("default","%^BOLD%^%^BLACK%^Faint noises from below carry on the air.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^Tantalizing smells from below hang in the air.%^RESET%^");
   set_items(([
      ({"stairs","staircase","stairwell"}) : "%^BOLD%^%^BLACK%^A "
         "skilled artisan has crafted this magnificent %^RESET%^"
         "%^ORANGE%^darkwood staircase%^BOLD%^%^BLACK%^, sanded "
         "the wood smooth and buffed it, giving it a %^WHITE%^"
         "glossy %^BLACK%^finish. The staircase widens at the "
         "bottom and becomes narrower as it ascends. The %^RESET%^"
         "%^ORANGE%^bannisters %^BOLD%^%^BLACK%^at the base have "
         "been carved to resemble seated dragons with their wings "
         "pinned against their ribs. A %^RED%^red%^BLACK%^, plush "
         "carpet %^RESET%^%^ORANGE%^r%^RED%^u%^BOLD%^%^RED%^nn"
         "%^RESET%^%^RED%^e%^ORANGE%^r %^BOLD%^%^BLACK%^protects "
         "the stairs from %^RESET%^scuffing%^BOLD%^%^BLACK%^. A "
         "railing lines the semi-circular balcony that overlooks "
         "the room below.%^RESET%^",
      ({"walls","wall","panels","paneling"}) : "%^BOLD%^%^BLACK%^The "
         "walls are lined with rich %^RESET%^%^ORANGE%^darkwood "
         "paneling %^BOLD%^%^BLACK%^ that insulate the room, keeping "
         "it at a comfortable temperature and reducing reverberation.%^RESET%^",
      "ceiling" : "%^BOLD%^%^WHITE%^Made from the same material as the "
         "pillars the arched ceiling is composed of pale dr%^RESET%^a"
         "%^BOLD%^%^WHITE%^gon bone scr%^RESET%^i%^BOLD%^%^WHITE%^msh"
         "%^ORANGE%^a%^WHITE%^w. It has been treated so that its color "
         "is a pristine i%^RESET%^v%^BOLD%^%^ORANGE%^o%^RESET%^r%^BOLD%^"
         "%^WHITE%^y and there is no residual %^MAGENTA%^tissue %^WHITE%^"
         "but the natural texture remains, the bone like thick w%^BLACK%^"
         "e%^WHITE%^bb%^RESET%^i%^BOLD%^%^WHITE%^ng in some places and "
         "completely s%^ORANGE%^o%^WHITE%^lid in others.%^RESET%^",
      "chandelier" : "%^BOLD%^%^BLACK%^A six tiered chandelier, each "
         "of its circular levels smaller than the last, hangs from the "
         "ceiling. Delicate %^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^by "
         "str%^RESET%^%^RED%^a%^BOLD%^%^RED%^nds %^BLACK%^hang from the "
         "slender metal circles, the %^WHITE%^wet%^BLACK%^-looking "
         "stones cut to a %^RESET%^%^CYAN%^t%^GREEN%^e%^BOLD%^%^CYAN%^a"
         "%^RESET%^%^CYAN%^r%^BOLD%^%^BLACK%^-drop shape that resembles "
         "beads of %^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d"
         "%^BOLD%^%^BLACK%^. The %^RESET%^%^RED%^gemstones %^BOLD%^"
         "%^BLACK%^cast a warm %^RESET%^%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^"
         "%^RED%^ms%^BOLD%^%^RED%^o%^RESET%^%^RED%^n l%^BOLD%^%^RED%^i"
         "%^WHITE%^g%^RESET%^%^RED%^ht %^BOLD%^%^BLACK%^across the room.%^RESET%^"
   ]));
   set_exits(([
      "stairs" : ROOMS"maw",
      "north" : ROOMS"chamber_of_reckoning"
   ]));
}