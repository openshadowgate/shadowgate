//A sapling room that Rheyn wanted
//coded by hades 7-17-20
#include <std.h>


inherit ROOM;

void create(){
  ::create();
  set_terrain(HEAVY_FOREST);
  set_travel(FOOT_PATH);
  set_name("a large clearing in the forest");
  set_short("%^GREEN%^a large c%^BOLD%^l%^ORANGE%^e%^GREEN%^a%^RESET%^%^GREEN%^ri%^BOLD%^n%^ORANGE%^g %^RESET%^%^GREEN%^in the f%^BOLD%^o%^RESET%^%^GREEN%^re%^BOLD%^s%^RESET%^%^GREEN%^t%^WHITE%^%^RESET%^");
  set_long(
  "%^GREEN%^The f%^BOLD%^o%^RESET%^%^GREEN%^re%^BOLD%^s%^RESET%^%^GREEN%^t opens up to reveal a large, lush c%^BOLD%^l%^ORANGE%^e%^RESET%^%^GREEN%^a%^YELLOW%^r%^GREEN%^i%^ORANGE%^n%^RESET%^%^GREEN%^g. Inbetween g%^BOLD%^r%^RESET%^%^GREEN%^ass, fer%^BOLD%^n%^RESET%^%^GREEN%^s and moss-covered %^WHITE%^r%^BOLD%^%^BLACK%^o%^RESET%^cks %^GREEN%^are patches of %^RED%^w%^BOLD%^i%^RESET%^%^RED%^ld cab%^BOLD%^b%^RESET%^%^RED%^age %^GREEN%^and %^YELLOW%^y%^RESET%^%^ORANGE%^e%^BOLD%^llo%^RESET%^%^ORANGE%^w %^BOLD%^l%^RESET%^%^ORANGE%^u%^BOLD%^pin%^RESET%^%^GREEN%^. In the midst of the clearing lies a heap of fertile soil. A tiny fragile %^BOLD%^sa%^RESET%^%^GREEN%^p%^BOLD%^ling %^RESET%^%^GREEN%^has been carefully planted in the heap.%^WHITE%^%^RESET%^");
  set_smell("default","%^RESET%^%^CYAN%^The %^RESET%^%^CYAN%^fresh %^BOLD%^%^WHITE%^air is scented with %^RESET%^%^CYAN%^grass%^BOLD%^%^WHITE%^, %^RESET%^%^CYAN%^soil %^BOLD%^%^WHITE%^and %^RESET%^%^CYAN%^w%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^ldflowe%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^.%^WHITE%^%^RESET%^");
  set_listen("default","%^BOLD%^%^CYAN%^The wind %^WHITE%^rust%^CYAN%^l%^WHITE%^es %^CYAN%^through the undergrowth, and birds %^RESET%^%^MAGENTA%^c%^BOLD%^hi%^RESET%^%^MAGENTA%^rp %^BOLD%^%^CYAN%^in the woods beyond the clearing.%^WHITE%^%^RESET%^");
  set_items(([
  ({"cabbage","wild cabbage"}) : "%^GREEN%^Hardy %^RED%^w%^BOLD%^i%^RESET%^%^RED%^ld c%^BOLD%^ab%^RESET%^%^RED%^b%^BOLD%^a%^RESET%^%^RED%^ge %^GREEN%^plants grow in small patches throghout the clearing.%^WHITE%^%^RESET%^",
           ({"lupne","yellow lupine", "flower"}) : "%^YELLOW%^Y%^RESET%^%^ORANGE%^e%^BOLD%^llow lup%^RESET%^%^ORANGE%^i%^BOLD%^ns %^RESET%^%^GREEN%^color the clearing with their bright flowers.%^RESET%^",
	       ({"grass","ground"}) : "%^GREEN%^The ground is covered with %^BOLD%^l%^ORANGE%^u%^GREEN%^sh %^RESET%^%^GREEN%^grass and ferns surrounding mos%^BOLD%^s%^RESET%^%^GREEN%^y rocks.%^RESET%^",
       "sapling" : "%^GREEN%^A tiny, fragile %^ORANGE%^o%^BOLD%^%^GREEN%^a%^RESET%^%^ORANGE%^k %^BOLD%^%^GREEN%^sapl%^RESET%^%^GREEN%^i%^BOLD%^ng %^RESET%^%^GREEN%^has been carefully planted in the middle of the clearing.%^RESET%^",
        ]));
    set_exits(([
        "south" : "/d/tharis/conforest/rooms/path29",
        ]));
}
