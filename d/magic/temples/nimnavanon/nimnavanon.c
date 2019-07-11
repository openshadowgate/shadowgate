//Temple of Nim'navanon revised from Silvanus - created by Nienne 2/18
#include <std.h>
inherit "/std/temple";

void create(){
   ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
   set_light(2);
   set_indoors(0);
   set_temple("nimnavanon");
   set_name("Temple of Silvanus");
   set_short("%^BOLD%^%^GREEN%^Temple of Nim'navanon%^RESET%^");
   set_long("%^BOLD%^%^GREEN%^The Temple of Nim'navanon%^RESET%^\n"
"%^BOLD%^%^WHITE%^You have entered a large clearing deep in the heart of the forest, where a single ancient %^RESET%^%^ORANGE%^oak tree %^BOLD%^%^WHITE%^rises to incredible heights at its "
"heart, its gnarled limbs clawing eternally skyward.  %^BOLD%^%^CYAN%^L%^RESET%^%^CYAN%^ig%^BOLD%^%^CYAN%^ht %^BOLD%^%^WHITE%^dapples the clearing, cast between its leaves as they wave overhead "
"in the breeze.  At the base of the tree stands a rough-hewn altar, a single piece of jade with %^RESET%^%^ORANGE%^du%^RED%^l%^ORANGE%^l %^BOLD%^%^WHITE%^and rugged sides.  Its surface has been "
"polished smooth, displaying the letters of Nim'navanon's charge in g%^YELLOW%^l%^BOLD%^%^WHITE%^ow%^YELLOW%^i%^BOLD%^%^WHITE%^ng amber against the %^RESET%^%^GREEN%^rich mossy hue "
"%^BOLD%^%^WHITE%^of the stone.  Around the oak, much of the rest of this area looks to be new growth, with %^RESET%^%^GREEN%^young grass %^BOLD%^%^WHITE%^underfoot that is relatively clear of "
"brush and leaves.  A circle of new %^BOLD%^%^GREEN%^sa%^YELLOW%^p%^BOLD%^%^GREEN%^lings %^BOLD%^%^WHITE%^questing upwards from the soil at the clearing's edges, beneath the eaves of the older "
"trees that lie beyond.  Occasionally, a hint of company is suggested by the %^RESET%^%^MAGENTA%^rustling %^BOLD%^%^WHITE%^of undergrowth within their depths, a t%^BOLD%^%^CYAN%^r"
"%^BOLD%^%^WHITE%^ill of birdsong, or a distant %^RESET%^%^BLUE%^howl %^BOLD%^%^WHITE%^carried upon the wind.\n%^RESET%^");
   set_smell("default","The air is filled with the smell of the forest that surrounds you.");
   set_listen("default","The wind rustles gently through the trees.");
   set_exits(([
      "out":"/d/tharis/conforest/rooms/path26",
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
%^BOLD%^Nim'navanon charges his followers with this message:%^RESET%^%^CYAN%^
Strive to live in harmony with the wilds, for we are each part of the eternal cycle.  Seek to perceive the greater balance in all things, and do not fear the forces of nature, for where destruction, decay and death clear a passage, life springs forth anew.  Intervene where you must, whether it be to cull or to plant anew.  Work actively against those who would disturb the natural order, and teach the ways of the wilderness to any who will listen.  Though civilisations may rise and fall, in the end nature will always reclaim its own.
CHARGE
   );
   return 1;
}