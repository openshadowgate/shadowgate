//Ryzan and Aunuit's House
//Coded by ~Circe~ 7/24/13

#include <std.h>
#include "aunuit.h"

inherit AUNUIT;

void create(){
   ::create();
   set_name("Tiled bath");
   set_short("%^BOLD%^%^BLACK%^Tiled bath%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^O%^BOLD%^%^MAGENTA%^p%^RESET%^"
      "%^MAGENTA%^al%^BOLD%^%^CYAN%^e%^RESET%^%^MAGENTA%^s%^ORANGE%^"
      "c%^MAGENTA%^ent m%^RED%^a%^BOLD%^%^MAGENTA%^u%^RESET%^%^RED%^"
      "v%^MAGENTA%^e tiles cover the floor and walls of this small "
      "circular bath. The center of the room sports a round %^BOLD%^"
      "%^WHITE%^sunken tub %^RESET%^%^MAGENTA%^with a %^ORANGE%^co"
      "%^RED%^p%^ORANGE%^per statue %^MAGENTA%^of a %^ORANGE%^dr"
      "%^BOLD%^%^ORANGE%^a%^RESET%^%^ORANGE%^g%^RED%^o%^ORANGE%^n "
      "%^MAGENTA%^perched on its edge. Resting against the wall to "
      "the left is a %^ORANGE%^co%^RED%^p%^ORANGE%^per b%^BOLD%^"
      "%^ORANGE%^a%^RESET%^%^ORANGE%^sin %^RESET%^%^MAGENTA%^and "
      "%^ORANGE%^faucet%^MAGENTA%^. A small %^WHITE%^m%^BOLD%^%^WHITE%^"
      "i%^CYAN%^r%^BLACK%^r%^WHITE%^o%^RESET%^r %^MAGENTA%^with an "
      "%^BOLD%^%^BLACK%^ornate frame %^RESET%^%^MAGENTA%^is mounted "
      "above the sink. Next to the washbasin a discreet %^BOLD%^"
      "%^BLACK%^niche %^RESET%^%^MAGENTA%^is tucked behind a curved "
      "wall. Assumedly this alcove houses the privy. %^ORANGE%^Shelves "
      "%^MAGENTA%^line the northern wall, their surfaces piled with "
      "neatly folded %^BOLD%^%^WHITE%^towels %^RESET%^%^MAGENTA%^and "
      "%^BOLD%^%^WHITE%^wash cloths %^RESET%^%^MAGENTA%^as well as a "
      "wide assortment of %^BOLD%^%^ORANGE%^sponges%^RESET%^%^MAGENTA%^, "
      "%^WHITE%^soaps %^MAGENTA%^and %^ORANGE%^oils%^MAGENTA%^. The "
      "%^BOLD%^%^WHITE%^pale sandst%^RESET%^o%^BOLD%^%^WHITE%^ne "
      "ceiling %^RESET%^%^MAGENTA%^is a convex dome decorated with "
      "a %^RED%^sensual %^MAGENTA%^bas-relief.%^RESET%^\n");
   set_smell("default","%^RESET%^%^CYAN%^The slightly humid air is alive with the scents of the oils and soaps.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The tile and solid stone surfaces augment any sound.%^RESET%^");
   set_items(([
      ({"tub","bath","bathtub","basin"}) : "%^RESET%^Two steps lead down "
         "into the sunken %^BOLD%^%^WHITE%^bathing basin %^RESET%^which "
         "is large enough for two. The surface of the tub is a smooth "
         "wh%^BOLD%^%^WHITE%^i%^RESET%^te s%^BOLD%^%^WHITE%^a%^RESET%^"
         "ndst%^BOLD%^%^ORANGE%^o%^RESET%^ne plane. On the edge of the "
         "first stair rests a %^ORANGE%^co%^RED%^p%^ORANGE%^per dr"
         "%^BOLD%^%^ORANGE%^a%^RESET%^%^ORANGE%^g%^RED%^o%^ORANGE%^n "
         "statue %^WHITE%^with its wings outstretched and its neck "
         "curled back on itself. Its jaws are stretched wide as if "
         "it is about to spit fire but within the mouth is a hollow "
         "to allow for %^CYAN%^w%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^t"
         "%^GREEN%^e%^CYAN%^r %^WHITE%^to pass through. Upon closer "
         "inspection there is a seam where the wings meet the torso, "
         "which allows them to turn and control the %^CYAN%^fl%^BOLD%^"
         "%^BLUE%^o%^RESET%^%^CYAN%^w%^RESET%^.",
      "ceiling" : "%^RESET%^The wh%^BOLD%^%^WHITE%^i%^RESET%^te "
         "s%^BOLD%^%^WHITE%^a%^RESET%^ndst%^BOLD%^%^ORANGE%^o%^RESET%^"
         "ne ceiling is adorned in an intricate carving of what could "
         "only be described as an %^MAGENTA%^o%^RED%^r%^MAGENTA%^gy"
         "%^RESET%^. Countless lithe nude bodies are tangled amongst "
         "one another engaged in various %^RED%^sex%^BOLD%^%^RED%^u"
         "%^RESET%^%^RED%^al a%^BOLD%^%^RED%^c%^RESET%^%^RED%^ts%^RESET%^. "
         "The Fey faces of their owners are contorted in expressions of "
         "pure %^MAGENTA%^e%^BOLD%^%^MAGENTA%^c%^RESET%^%^MAGENTA%^st"
         "%^RED%^a%^MAGENTA%^sy%^RESET%^.",
      ({"sink","mirror"}) : "%^RESET%^A circular %^ORANGE%^co%^RED%^p"
         "%^ORANGE%^per basin %^WHITE%^and %^ORANGE%^f%^BOLD%^%^ORANGE%^a"
         "%^RESET%^%^ORANGE%^uc%^RED%^e%^ORANGE%^t %^WHITE%^rest on a "
         "carved %^BOLD%^%^BLACK%^darkwood base %^RESET%^decorated with "
         "%^BOLD%^%^BLACK%^dr%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^conic "
         "eff%^RESET%^i%^BOLD%^%^BLACK%^g%^WHITE%^i%^BLUE%^e%^BOLD%^"
         "%^BLACK%^s%^RESET%^. A pristine %^BOLD%^%^WHITE%^white hand "
         "towel %^RESET%^is folded over the rim of the %^ORANGE%^sink "
         "%^WHITE%^and a %^MAGENTA%^fragr%^BOLD%^%^MAGENTA%^a%^RESET%^"
         "%^MAGENTA%^nt b%^WHITE%^a%^MAGENTA%^r %^WHITE%^of soap rests "
         "to the side ready for use. Mounted above the sink is a small "
         "circular m%^BOLD%^%^WHITE%^i%^CYAN%^r%^BLACK%^r%^WHITE%^o%^RESET%^r "
         "bordered by a sturdy %^BOLD%^%^BLACK%^darkwood frame %^RESET%^that "
         "depicts roiling %^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^BLACK%^d"
         "%^WHITE%^o%^BLACK%^w fl%^RESET%^o%^BOLD%^%^BLACK%^wing %^RESET%^over "
         "and through itself in an endless storm of %^BLUE%^darkness%^WHITE%^.%^RESET%^",
      ({"walls","wall","floor","tiles"}) : "%^RESET%^%^MAGENTA%^The walls "
         "and floor are covered with small square o%^BOLD%^%^MAGENTA%^p%^RESET%^"
         "%^MAGENTA%^al%^BOLD%^%^CYAN%^e%^RESET%^%^MAGENTA%^s%^ORANGE%^c"
         "%^MAGENTA%^ent m%^RED%^a%^BOLD%^%^MAGENTA%^u%^RESET%^%^RED%^v"
         "%^MAGENTA%^e tiles.%^RESET%^",
      ({"shelves","shelf","towel","towels","soaps","soap","oils","sponge","sponges"}) :
         "%^BOLD%^%^WHITE%^Pristine white terry cloth towels %^RESET%^have "
         "been neatly folded and stacked on the %^BOLD%^%^BLACK%^darkwood "
         "shelves%^RESET%^. Clear jars filled with %^ORANGE%^amb%^BOLD%^"
         "%^ORANGE%^e%^RESET%^%^ORANGE%^r oil%^RESET%^, %^MAGENTA%^fragr"
         "%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^nt %^WHITE%^soaps and "
         "natural %^BOLD%^%^ORANGE%^sponges %^RESET%^also line the "
         "%^BOLD%^%^BLACK%^shelves%^RESET%^."
   ]));
   set_exits(([
      "west" : ROOMS"bedroom"
   ]));
}
